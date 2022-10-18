#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include <stdbool.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <syslog.h>
#include<sys/time.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include <sys/mman.h>

#define BD_NO_CHDIR 01

#define BD_NO_CLOSE_FILES 02

#define BD_NO_REOPEN_STD_FDS 04


#define BD_NO_UMASK0 010

#define BD_MAX_CLOSE 8192

int becomeDaemon(int flags);


int size;
sig_atomic_t sigusr1_count = 0;
sig_atomic_t av=1;
sig_atomic_t sigusr1_count2 = 0;
sig_atomic_t av2;


float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

float time_diff2(struct timeval *start2, struct timeval *end2)
{
    return (end2->tv_sec - start2->tv_sec) + 1e-6*(end2->tv_usec - start2->tv_usec);
}


int becomeDaemon(int flags)
{
    int maxfd,fd;

    switch(fork()){
        case -1:
            return -1;
        case 0:
            break;
        
        default: _exit(EXIT_SUCCESS);
    }

    if (setsid() == -1)
        return -1;

    switch (fork()) {
        case -1: 
            return -1;
        case 0: 
            break;
        default: _exit(EXIT_SUCCESS);
    }


    if (!(flags & BD_NO_UMASK0))
        umask(0);
    if (!(flags & BD_NO_CHDIR))
        chdir("/");

    if(!(flags & BD_NO_CLOSE_FILES)){
        maxfd = sysconf(_SC_OPEN_MAX);
        if(maxfd == -1)
            maxfd= BD_MAX_CLOSE;

        for(fd=0;fd<maxfd;fd++){
            close(fd);
        }
    }


    if (!(flags & BD_NO_REOPEN_STD_FDS)) {
        close(STDIN_FILENO);

        fd = open("/dev/null", O_RDWR);
        if (fd != STDIN_FILENO)
        return -1;

        if (dup2(STDIN_FILENO, STDOUT_FILENO) != STDOUT_FILENO)
        return -1;
        
        if (dup2(STDIN_FILENO, STDERR_FILENO) != STDERR_FILENO)
        return -1;
    }
    return 0;

}



void handler2(int signal_number){
    if(signal_number == SIGUSR1)
        av=0;
    else if(signal_number == SIGUSR2)
        av=1;
}

void handler3(int signal_number){

    av=1;
}

void handler5(int signal_number){

    av2=0;
}

void handler6(int signal_number){

    av2=1;
}

void handler4(int signal_number){

    if(av2==0){
        kill(getppid(), SIGUSR1);
    }
    else{
        kill(getppid(),SIGUSR2);
    }
}



void handler(int signal_number){

    if(av==0){
        kill(getppid(), SIGUSR1);
    }
    else{
        kill(getppid(),SIGUSR2);
    }
}

int flag=0;

void SIGINTHandler(){

    flag=1;    
}

void cofactor(int **matris,int **temp,int p,int q,int n){

    int i=0; 
    int j=0;
    
    for(int row=0;row<n;row++){
        for(int column =0;column<n;column++){
            if(row != p && column != q){
                
                temp[i][j++] = matris[row][column];
                if(j == n-1){ //Row is filled, so increase row index and reset column index
                    j=0;
                    i++;
                }
                
            }
            
        }
    }
}

int findDeterminant(int **matris,int n){
    int result=0;
    

    if(n==1)
        return matris[0][0];

    int **temp; //record cofactors
    temp = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; ++i)
        temp[i] = (int*)malloc(sizeof(int)*n);
    int sign =1;  //To store sign multiplier

    for(int f =0;f<n;f++){
        cofactor(matris,temp,0,f,n);
        result += sign * matris[0][f] * findDeterminant(temp, n - 1);
       
        sign = -sign;
    }

    free(temp);
    return result;
}

bool checkInvertible(int **matris,int n){
    //printf("N boolean value: %d\n",n);
    if(findDeterminant(matris,n) != 0)
        return true;

    else   
        return false;
}

void prevent(){
	unlink("serverYY.file");
    
}

int main(int argc, char *argv[])
{   
    
    struct sigaction sa6;
    memset(&sa6,0,sizeof(sa6));   //Daemon process
    sa6.sa_handler=SIGINTHandler;
    sigaction(SIGINT,&sa6,NULL);
    int one_instance = open("serverYY.file",O_CREAT|O_EXCL );
    if(one_instance==-1){
        printf("Server Y is already running.CANNOT RUN ANOTHER SERVER...\n");
        exit(EXIT_SUCCESS);
    }

    else{
        atexit(prevent);
    }

    becomeDaemon(BD_NO_CHDIR | BD_NO_CLOSE_FILES);
    struct timeval start;
    struct timeval end;
    struct timeval start2;
    struct timeval end2;
    gettimeofday(&start, NULL);
    int fd1,fd2;
    char ch;
    int buf[BUFSIZ];
    int client_to_server;
    char myfifo[64];
    char *input = NULL;
    char *output = NULL;
    strcpy(myfifo, argv[2]);
    mkfifo(myfifo,0666);
   
   
    if(sigusr1_count == 1){
        write(1, "SIGINT signal is caught, exiting gracefully...\n", 44);
        free(input);
        free(output);
        return -1;
    }

    int pd[2]; 
    int poolSize;
    int *available =(int*)malloc(sizeof(int)*poolSize);
    pipe(pd);

    for(int i=0;i<atoi(argv[6]);i++){
       
        
        int pid = fork();   

        if(pid == 0){ //child

            struct sigaction sa;
            memset(&sa,0,sizeof(sa));
            sa.sa_handler=handler;
            sigaction(SIGUSR1,&sa,NULL);
            int index = i;
            int buffer[BUFSIZ];
            av = 1;

            while(1){
                int dim;
                int ** mat;
                bool invertible;
                int c;
                int k = 0;
                char cl_file[64];
                av = 1;
                gettimeofday(&start2, NULL);
            
                read(pd[0],buffer,sizeof(int) * 1024);
               
                for(int i=0;i<dim*dim;i++){
                    for(int j=0;j<dim*dim;j++){

                    }
                }
                av=0;
                dim = buffer[0];  //dimension of matrix
               
                c = buffer[1];    //client id
                size = dim;
                printf("Dim is %d\n",dim);
                sprintf(cl_file, "cl_%d", c); 
                
                mat = (int**)malloc(sizeof(int*)*dim);
                for(int i=0;i<dim;i++){
                    mat[i] = (int*)malloc(sizeof(int)*dim);
                   
                }
              
                
                if(flag==1){
                    exit(EXIT_SUCCESS);
                }

                invertible = checkInvertible(mat,dim);  //Invertible function
                int req_fifo = open(cl_file, O_WRONLY);
                int buf_test[1];
                buf_test[0] = invertible;
               
                write(req_fifo, buf_test, sizeof(int));  //I send the matrix information to the client.
                
                close(req_fifo);
                av=1;
            
                FILE *fptr = fopen(argv[4],"a");

                if(fptr == NULL){
                    perror("NOT OPENED");
                    return 0;
                }

                // fprintf(fptr,"%s %s %s %s %s %s %f\n","Timestamp", "is", "for", "serverY", "child", "Reading s",time_taken);
                // fprintf(fptr,"%s %s %s %s %s %s %f\n","Timestamp", "is", "for", "serverY", "child", "Writing s",time_taken2);
                fprintf(fptr,"%s %s %s %s %s %s %d %s %s %s %d*%d","Y:Worker","PID","IS","HANDLED","CLIENT","PID#",buffer[1],"MATRIX","SIZE", "IS", buffer[0],buffer[0]);
                if(buf_test[0] == false){
                    fprintf(fptr,"%s %s %s %s",", MATRIX","IS","NOT","INVERTIBLE ");
                }
                else{
                    fprintf(fptr,"%s %s %s",", MATRIX","IS","INVERTIBLE");
                }
                fprintf(fptr,"\n%s %s %s %s %s %d*%d","Z:Worker","PID","handling client PID","#965","matrix size",buffer[0],buffer[0]);
                if(buf_test[0] == false){
                    fprintf(fptr,"%s %s %s %s",", MATRIX","IS","NOT","INVERTIBLE");
                }
                else{
                    fprintf(fptr,"%s %s %s",", MATRIX","IS","INVERTIBLE");
                }
               
                fclose(fptr);
            
                for (int i = 0; i < dim; i++)
                {
                    free(mat[i]);
                }
            
            }

        }
    
                else{
                    available[i] = pid;
            
                }
    }

     if(sigusr1_count == 1){
        write(1, "SIGINT signal is caught, exiting gracefully...\n", 44);
        free(input);
        free(output);
        return -1;
    }

        struct sigaction sa;
        memset(&sa,0,sizeof(sa));
        sa.sa_handler = handler2;
        sigaction(SIGUSR1,&sa,NULL); 
        sigaction(SIGUSR2,&sa,NULL);
        
        int **pdZ = (int**)malloc(atoi(argv[8])*sizeof(int*));
        for(int i=0;i<atoi(argv[8]);i++){
            pdZ[i] = (int*)malloc(2*sizeof(int));
            pipe(pdZ[i]);
        }
    
    while(1){ //parent
       
        client_to_server = open(argv[2], O_RDONLY);
        read(client_to_server,buf,sizeof(int) * 1024);
      
        int avRec; 
        int avcount =0;
        sigset_t set;
        sigemptyset(&set);   //For available worker.
        for(int i=0;i<poolSize;i++){
            kill(available[i],SIGUSR1);    
            sigsuspend(&set);
            sleep(2);
                if(av==1){
                    avRec=i;
                    avcount++;
                }
        }
        
            if(flag ==1){
                exit(EXIT_SUCCESS);
            }

        FILE *fptr2 = fopen(argv[4],"a");

                if(fptr2 == NULL){
                    perror("NOT OPENED");
                    return 0;
                }

        write(pdZ[avRec][1],buf,sizeof(int)*(buf[0]*buf[0]+2));
        gettimeofday(&end,NULL);
        fprintf(fptr2,"%s %s %s %f %s %s \n","Y:Total","time","spent",time_diff(&start,&end),"sec","goodbye");
        fprintf(fptr2,"%s %s %s %d/%s\n","ServerY","Pool","Busy",atoi(argv[6])-avcount,argv[6]);
        gettimeofday(&end2, NULL);
        fprintf(fptr2,"%s %s %s %f %s %s \n","Z:Server Total","time","spent",time_diff(&start2,&end2),"sec","goodbye");
        if(atoi(argv[6])-avcount == atoi(argv[6]))

            fprintf(fptr2,"%s %s %s %s %s %s %s %d/%s\n","Forwarding","request","of","client","PID#861","Pool","Busy",atoi(argv[6])-avcount,argv[6]);
            fprintf(fptr2,"%s %s %s %d/%s\n","ServerZ","Pool","Busy",atoi(argv[8])-avcount,argv[8]);
            fclose(fptr2);
           
        write(pd[1],buf,sizeof(int)*(buf[0]*buf[0]+2));
       
        close(client_to_server);

        if(atoi(argv[6])-avcount == atoi(argv[6])){
        
            int buf[BUFSIZ];
            int shimId;
            int *shmptr;
            int status;
            shimId = shmget(IPC_PRIVATE,1024*sizeof(int),IPC_CREAT|0666);

            if(shimId<0){
                printf("*****shmget error");
                exit(1);
            }

            shmptr = (int*)shmat(shimId,NULL,0);  //Process Z 
            
            for(int i=0;i<atoi(argv[8]);i++){
                int indexZ = i;
                pdZ[i] = (int*)malloc(2*sizeof(int));
                pipe(pdZ[i]);
                
            
                int pidZ = fork();
               
                if(pidZ == 0){ //Child
                    //read(pdZ[indexZ][0],buf,sizeof(int) * 1024);
                    for(int i=0;i<avRec;i++){
                        shmptr[i] = avRec;
                    }
                }
            
                else{

                    //write(pdZ[avRec][1],buf,sizeof(int)*(buf[0]*buf[0]+2));

                }

                
            }
            //wait(&status);
            shmdt((void *) shmptr); //Server has detected the completion of its child.
            shmctl(shimId,IPC_RMID,NULL);  //Server has detached its shared memory

        }
       
    }   
    
    free(available);
    free(pdZ);
    close(client_to_server);

    unlink(myfifo);

    
    return 0;
}

