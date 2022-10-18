#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h> 
#include <time.h>
#include <string.h>
#include <signal.h>

int N;
int C;
key_t key;
int semid;

char *fileName;

sig_atomic_t sigusr1_count = 0;

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short  *array;
};

void suppliersemOperation(int index){

    struct sembuf waitpostSem = {index, 1, 0};

    if (semop(semid, &waitpostSem, 1) == -1) 
    { 
                perror("semop");
                exit(1); 
    }
    
}

void consumersemOperation(){
   
    struct sembuf waitpostSem[2] = {{0, -1, 0},{1,-1,0}};

    if (semop(semid, waitpostSem, 2) == -1) 
    { 
                perror("semop");
                exit(1); 
    }
   
}


void timestamp(char buf[26]){

    time_t timer;
    struct tm* timestamp;

    timer = time(NULL);
    timestamp = localtime(&timer);

    strftime(buf, 26, "%Y-%m-%d %H:%M:%S", timestamp);
}

void* consumer_print(void* arg){

    char buffer[26];
    int b = (intptr_t)arg; 
    timestamp(buffer);

    for(int i=0;i<N;i++){

        printf("timestamp:%s ,Consumer-%d at iteration %d (waiting). Current amounts: %d x '1', %d x '2'.\n",buffer,b,i,semctl(semid,0,GETVAL,NULL),semctl(semid,0,GETVAL,NULL));
        
        consumersemOperation();

        if(sigusr1_count > 0){
            break;
        }

        timestamp(buffer);
        printf("timestamp:%s ,Consumer-%d at iteration %d (consumed). Post-consumption amounts: %d x '1', %d x '2'.\n",buffer,b,i,semctl(semid,0,GETVAL,NULL),semctl(semid,0,GETVAL,NULL)); 
    
    }
    printf("timestamp:%s,Consumer-%d has left.\n",buffer,b);

    pthread_exit(NULL);

}


void* supplier_print(){
    FILE *fp;
    
    fp = fopen(fileName,"r");   

    if(fp == NULL){
        perror("cannot open file.\n");
    }

    int c;
    int count = 0;
    union semun arg;
    arg.array = (unsigned short*)malloc(2*sizeof(unsigned short));
    arg.array[0] = (unsigned short) C;
    arg.array[1] = (unsigned short) C;

    do
    {
        char buffer[26];
        timestamp(buffer);

        c = fgetc(fp);

        if(sigusr1_count > 0){
            break;
        }

        if(c == '\n' || c == EOF)break;
        printf("timestamp:%s ,Supplier: read from input a '%c'. Current amounts: %d x '1', %d x '2'.\n",buffer,c,semctl(semid,0,GETVAL,NULL),semctl(semid,1,GETVAL,NULL));
        
        switch (c)
        {
        case '1':
            suppliersemOperation(0);
           
        break;

        case '2':
            suppliersemOperation(1);
        break;
        
        default:
            break;
        }
        timestamp(buffer);  

        printf("timestamp:%s ,Supplier: delivered a '%c'. Post-delivery amounts: %d x '1', %d x '2'.\n",buffer,c,semctl(semid,0,GETVAL,NULL),semctl(semid,1,GETVAL,NULL));  
        count++;
    }while (c);
    if(sigusr1_count > 0 || count < 2*N*C){
        if(count < 2*N*C) sigusr1_count = 1;
        if(semctl(semid, 0, SETALL, arg) < 0){
            perror("SEMCTL SETALL: ");
        }
    }
    char buffer[26];
    fclose(fp);
    free(arg.array);
    timestamp(buffer);
    printf("timestamp:%s ,The Supplier has left.\n",buffer);
   
    pthread_exit(NULL);
}


void handler(int signal_number){

    sigusr1_count = 1;
}


int main(int argc, char *argv[])
{

    struct sigaction sa;
    memset(&sa,0,sizeof(sa));
    sa.sa_handler=handler;
    sigaction(SIGINT,&sa,NULL);
    char *input = NULL;
    char *output = NULL;

    if(setvbuf(stdout, NULL, _IONBF, 0)) {
        perror("failed to change the buffer of stdout\n");
        return EXIT_FAILURE;
    }   

    fileName = argv[6];
    C = atoi(argv[2]);
    N = atoi(argv[4]);


    if(C <= 4){
        perror("MUST BIGGER 4.\n");
        return 1;
    }

    if(N <= 1){
        perror("MUST BIGGER 1.\n");
        return 0;
    }

    if(sigusr1_count == 1){
        write(1, "SIGINT signal is caught, exiting gracefully...\n", 44);
        free(input);
        free(output);
        return -1;
    }


    if ((key = ftok("/tmp", 1)) == -1) 
    {   
        perror("ftok");
        exit(1); 
    }

    
    if ((semid = semget(IPC_PRIVATE, 2, IPC_CREAT|IPC_EXCL|0600)) == -1) 
    {
        perror("semget");
        exit(1); 
    }

    if(sigusr1_count == 1){
        write(1, "SIGINT signal is caught, exiting gracefully...\n", 44);
        free(input);
        free(output);
        return -1;
    }

  
    pthread_t array[C];

    for (int i = 0; i < C; i++)
    {
        pthread_create(&array[i],NULL,consumer_print,(void*)(intptr_t)i);
    }
        

    pthread_t thread1_id; 

   
    pthread_create(&thread1_id,NULL,supplier_print,NULL);
   
    pthread_detach(thread1_id);

    for (int i = 0; i < C; i++)
    {
        pthread_join(array[i],NULL);
    }
    
    if(sigusr1_count == 1){
        write(1, "SIGINT signal is caught, exiting gracefully...\n", 44);
        free(input);
        free(output);
        return -1;
    }


    semctl(semid, 0, IPC_RMID);

    return 0;
}