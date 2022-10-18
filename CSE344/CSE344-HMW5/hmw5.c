#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h> 
#include <time.h>
#include <string.h>
#include <signal.h>
#include <math.h>
#include <sys/time.h>

#define READ_FLAGS O_CREAT | O_RDONLY
#define USER_MODS 0666


sig_atomic_t sigusr1_count = 0;


typedef struct matrixSize{

    int id;
    int start;
    int end;

}matrixSize;


struct timeval start;
int counter = 0;
int **matrix;
int **matrix2;
double **result;
pthread_t *threads;
char *buf;
int m;
int N;
matrixSize *ind;
pthread_mutex_t mut =  PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c;
double **real;
double **image;

int powNumber(int N);
void* mulmat(void* arg);
void calculateDFT();


void handler(int signal_number){

    sigusr1_count = 1;
}


float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}


void timestamp(char buf[26]){

    time_t timer;
    struct tm* timestamp;

    timer = time(NULL);
    timestamp = localtime(&timer);

    strftime(buf, 26, "%Y-%m-%d %H:%M:%S", timestamp);
}


void assign(char *argv[]){
  
   
    N = atoi(argv[8]);

    if(N<=2){

        perror("MUST GREATER THAN 2.");
        exit(1);
    }

    m = atoi(argv[10]);

    if(m < 2){
        perror("m must equal or greater than 2:\n");
        exit(0);
    }
  
    int powN;
    powN = powNumber(N);

    matrix = (int **)malloc(powN * sizeof(int*));

    matrix2 = (int **)malloc(powN* sizeof(int*));
    result = (double **)malloc(powN* sizeof(double*));
    buf = (char *)malloc(powN*powN * sizeof(char));
    real = (double **)malloc(powN* sizeof(double*));
    image = (double **)malloc(powN* sizeof(double*));

    for(int i=0;i<powN;i++){
        matrix[i] = (int *)malloc(powN*sizeof(int)); 
        matrix2[i] = (int *)malloc(powN*sizeof(int)); 
        result[i] = (double *)malloc(powN*sizeof(double)); 
        real[i] = (double *)malloc(powN* sizeof(double));
        image[i] = (double *)malloc(powN* sizeof(double));
    }

}

int powNumber(int N){
    
    int result;
    result = pow(2,N);

    return result;
}

void readFile(char *argv[]){


    int fdRead = open(argv[2],READ_FLAGS,USER_MODS);
    int fdRead2 = open(argv[4],READ_FLAGS,USER_MODS);

    if (fdRead < 0){
        perror("can't open\n");
        exit(1);
    }


    if (fdRead2 < 0){
        perror("can't open\n");
        exit(1);
    }

    int size = read(fdRead,buf, powNumber(N)*powNumber(N));
    
    int index = 0;

    for(int i=0;i<powNumber(N);i++){
        for(int j=0;j<powNumber(N);j++,index++){
            matrix[i][j] = (int)buf[index];
        }
    }

    index=0;

    int size2 = read(fdRead2,buf, powNumber(N)*powNumber(N));


    for(int i=0;i<powNumber(N);i++){
        for(int j=0;j<powNumber(N);j++,index++){
            matrix2[i][j] = (int)buf[index];
        }
    }


    if(size < powNumber(N)*powNumber(N)){
        printf("FATAL ERROR must bigger than 2^n*2^n \n");
    
        exit(1);
    }

    if(size2 < powNumber(N)*powNumber(N)){
        printf("FATAL ERROR must bigger than 2^n*2^n \n");
    
        exit(1);
    }

    close(fdRead);

}


void joinThread(){

    for (int i = 0; i < m; i++)
    {
        pthread_join(threads[i],NULL);
    }
}


void createThreads(char *argv[]){

    FILE *ptr;

    ptr = fopen(argv[6],"w");

    if(ptr == NULL)
    {
      perror("Error!\n");   
      exit(1);             
    }

    threads = (pthread_t*)malloc(sizeof(pthread_t)*m);
    
    ind = (matrixSize*)malloc(sizeof(matrixSize)*m);
    
    for(int i=0;i<m;i++){
        ind[i].id = i;
        ind[i].start = i*powNumber(N)/m;
        ind[i].end = ((i+1)* powNumber(N)/m) -1;
    }


    for(int i=0;i<m;i++){
        pthread_create(&threads[i],NULL,mulmat,(&ind[i]));

    }

    joinThread();

    for(int i=0;i<powNumber(N);i++){
        for(int j=0;j<powNumber(N);j++){
            fprintf(ptr,"%.3f + (%.3fi), ",(real[i][j]),(image[i][j]));
            
            if(sigusr1_count > 0){
                break;
            }
        }

        fprintf(ptr,"\n");
    }

    fclose(ptr);
}


void barrier(){

    pthread_mutex_lock(&mut);
    ++counter;

    if(counter<m){
        pthread_cond_wait(&c,&mut);
    }

    else{
         pthread_cond_broadcast(&c);
    }

    pthread_mutex_unlock(&mut);

}

void* mulmat(void* arg){

    char buffer[26];
    char buffer4[26];
    timestamp(buffer);
    timestamp(buffer4);
    
    struct timeval mid;
    struct timeval end;

    matrixSize obj = *((matrixSize*)arg);

    for(int i=0;i<powNumber(N);i++){
        for(int j=obj.start;j<=obj.end;j++){
            for(int k=0;k<powNumber(N);k++){
                result[i][j] += matrix[i][k] * matrix2[k][j];
            }
        }
    }

    gettimeofday(&mid,NULL);

    
    printf("Timestamp: %s, Thread %d has reached the rendezvous point in %f seconds\n",buffer,obj.id,time_diff(&start,&mid));


    barrier();
    printf("Timestamp: %s, Thread %d advancing to the second part\n",buffer,obj.id);
    calculateDFT(&obj);
    
    
    gettimeofday(&end,NULL);

    printf("Timestamp: %s, Thread %d has has finished the second part in %f seconds\n",buffer4,obj.id,time_diff(&mid,&end));
    return NULL;
}

void calculateDFT(matrixSize *obj){

    for(int k=0;k<powNumber(N);k++){
        for(int l= obj->start;l<= obj->end;l++){
            real[k][l] = 0.0;
            image[k][l] = 0.0;
            for(int m=0;m<powNumber(N);m++){
                for(int n=0;n<powNumber(N);n++){
                   real[k][l]+= (result[m][n]*cos(-2 * M_PI* ((1.0 * l * n/ powNumber(N))+ (1.0 * k * m/ powNumber(N)))));
                    
                   image[k][l] += (result[m][n]* sin(-2 * M_PI* ((1.0 * l * n/ powNumber(N))+ (1.0 * k * m/ powNumber(N)))));
                                    
                    if(sigusr1_count > 0){
                        break;
                    }

                }
            }
        }
    }

}

int main(int argc, char *argv[])
{   
    

    struct sigaction sa;
    memset(&sa,0,sizeof(sa));
    sa.sa_handler=handler;
    sigaction(SIGINT,&sa,NULL);
    char *input = NULL;
    char *output = NULL;


    char buffer2[26];
    char buffer3[26];
    timestamp(buffer2);
    timestamp(buffer3);
    struct timeval end;

    assign(argv);
    gettimeofday(&start, NULL);
    readFile(argv);

    for(int i=0;i<powNumber(N);i++){
        for(int j=0;j<powNumber(N);j++){
                result[i][j] = 0;  
        }
    }

    printf("Timestamp: %s, Two matrices of size %d x %d have been read. The number of threads is %d\n",buffer2,powNumber(N),powNumber(N),m);

    createThreads(argv);

    if(sigusr1_count == 1){
        write(1, "SIGINT signal is caught, exiting gracefully...\n", 44);
        free(input);
        free(output);
        return -1;
    }


    gettimeofday(&end,NULL);
    printf("Timestamp: %s, The process has written the output file.The total time spent is %f seconds.\n",buffer3,time_diff(&start,&end));

    

    for(int i=0;i<powNumber(N);i++){

        free(matrix[i]); 
        free(matrix2[i]); 
        free(result[i]); 
        free(real[i]); 
        free(image[i]);
    }

    free(matrix);
    free(matrix2);
    free(result);
    free(real);
    free(image);
    free(threads);
    free(ind);
    free(buf);

    
    return 0;
}







