#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>

sig_atomic_t sigusr1_count = 0;



float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}


int findDimension(char *argv[]){
  int index=0;
  int line=1;
  int fileRead=0;
  int readByte;

  
  int input = open(argv[4],O_RDONLY);

  char buffer[1000];

  if(input < 0){
    perror("open");
    exit(-1);
  }   

  do{

    readByte = read(input, buffer,1000);
    
    if(readByte == -1)
        perror("read while:-1");
    
    if(readByte == 0)
        fileRead = 1;
    for(int i=0;i<readByte;i++){
        if(buffer[i] == '\n'){
            ++line;
        }
    
    
    }
  }while(readByte != 0);

   
    return line;
    close(input);

}

void handler(int signal_number){

    ++sigusr1_count;
}

int main(int argc,char* argv[]){
    
    struct timeval start;
    struct timeval end;

    gettimeofday(&start, NULL);
    struct sigaction sa;
    memset(&sa,0,sizeof(sa));
    sa.sa_handler=handler;
    sigaction(SIGINT,&sa,NULL);
    char *input = NULL;
    char *output = NULL;
   
    int dimension;
    dimension = findDimension(argv);

    if(sigusr1_count == 1){
        write(1, "SIGINT signal is caught, exiting gracefully...\n", 44);
        free(input);
        free(output);
        return -1;
    }

    

    FILE *fp;
    int data,row,col,c,count,inc;
    int *array, capacity=1024;
    char ch;
    array=(int*)malloc(sizeof(int)*capacity);
    fp=fopen(argv[4],"r");
    row=col=c=count=0;
    count++;
    while(EOF!=(inc=fscanf(fp,"%d%c", &data, &ch)) && inc >0){
        ++c;//COLUMN count
        if(capacity==count)
            array=(int*)realloc(array, sizeof(int)*(capacity*=2));
        array[count++] = data;
        if(ch == '\n'){
            ++row;
            if(col == 0){
                col = c;
            } else if(col != c){
                fprintf(stderr, "format error of different Column of Row at %d\n", row);
               
            }
            c = 0;
        } else if(ch != ','){
            fprintf(stderr, "format error of different separator(%c) of Row at %d \n", ch, row);
            
        }
    }
    row++;
    
    fclose(fp);  


    if(sigusr1_count == 1){
        write(1, "SIGINT signal is caught, exiting gracefully...\n", 44);
        free(input);
        free(output);
        return -1;
    }

    int fd1,fd2;
    
    int client_to_server;

    int server_to_client;
    char return_fifo[64];
    char *myfifo2 = "/tmp/fifo2";
    char str[2] = "0";
    sprintf(return_fifo, "cl_%d", getpid());
    printf("Client PID#%s, ",return_fifo);
    printf("is submitting a %d*%d matrix:\n",findDimension(argv),findDimension(argv));
    mkfifo(return_fifo, 0666);
    client_to_server = open(argv[2], O_WRONLY);
    server_to_client = open(myfifo2, O_RDONLY);
    int buffer[1];
    array[0] = findDimension(argv);
    array[1] = getpid();
   
    write(client_to_server,array,sizeof(int)*(dimension*dimension +2));
    sleep(5);
   
    int ret_fifo = open(return_fifo, O_RDONLY);
   
    read(ret_fifo, buffer, sizeof(int));
    
    if(buffer[0] == 0){
        printf("the matrix is not invertible\n");
    }

    else{
        printf("the matrix is invertible\n");
    }
    gettimeofday(&end,NULL);
    printf("Total time spent: %f sec  goodbye.\n",time_diff(&start,&end));
 



    return 0;
}

