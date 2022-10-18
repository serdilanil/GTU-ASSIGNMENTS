#include<stdio.h>
#include<math.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

#define WRITE_FLAGS O_CREAT | O_WRONLY | O_APPEND
#define USER_MODS 0666
#define COLUMN 3
#define ROW 10

int flag = 0;


void handler(int sig_num){

    flag =1;

}

void findConveriance(int arr[ROW][COLUMN],int arr2[ROW][ROW],float result[ROW][COLUMN],int column1,int row1,int column2,int row2);

int main(int argc, char *argv[]){
    

    struct sigaction sa;
    sa.sa_handler = &handler;
    sigaction(SIGINT, &sa, NULL);



    int coveriance[ROW][COLUMN];
    int unit[ROW][ROW];
    float result[COLUMN][COLUMN];


    for(int i=0;i<ROW;i++){
        
        for(int j=0;j<COLUMN;j++){
            sscanf(argv[i*COLUMN + j +1], "%d", &coveriance[i][j]);
          
        }
    }

    for(int i=0;i<ROW;i++){

        for(int j=0;j<ROW;j++){

            unit[i][j]=1;

        }
    }

    sigset_t sigset;
    sigset_t backup;
    sigfillset(&sigset);
    sigemptyset(&backup);
    sigprocmask(SIG_SETMASK, &sigset, &backup);
    findConveriance(coveriance,unit,result,COLUMN,ROW,ROW,ROW);

  
    int fdWrite = open(argv[0],WRITE_FLAGS,USER_MODS);

    for(int i=0;i<3;i++){
        for(int j = 0; j < 3; ++j){
        
        }
        write(fdWrite,result[i],COLUMN*sizeof(float));    
    }
    printf("\n");
    

    if(flag == 1){

        close(fdWrite);
        remove(argv[0]);
        perror("Removed file process succesfully done !!!! \n");
    }

    close(fdWrite);
    sigprocmask(SIG_SETMASK, &backup, NULL);

    return 0;
}


void findConveriance(int arr[ROW][COLUMN],int arr2[ROW][ROW],float result[COLUMN][COLUMN],int column1,int row1,int column2,int row2){
    float temp_1[ROW][COLUMN];
    float temp_2[ROW][COLUMN];
    float transpose[COLUMN][ROW];

    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COLUMN; ++j){
            temp_2[i][j] = (float)arr[i][j];
        }
    }
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
           temp_1[i][j]=0;
        
            for(int k=0;k<ROW;k++){
               temp_1[i][j] += ((float)arr2[i][k] * (float)temp_2[k][j]) * 1/ROW;
            }
        }
    }

    
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
             
            temp_2[i][j] -= (float)temp_1[i][j];
        }
    }


    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COLUMN; ++j){
            transpose[j][i] = temp_2[i][j];
        }
    }

    for(int i=0;i<COLUMN;i++){
        for(int j=0;j<COLUMN;j++){
           result[i][j]=0;
        
            for(int k=0;k<ROW;k++){
               result[i][j] += (transpose[i][k] * temp_2[k][j]) * 1/ROW;
            }
        }
    }
}

