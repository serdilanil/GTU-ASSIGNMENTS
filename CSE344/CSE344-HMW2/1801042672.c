#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>
#include <string.h>
#include <signal.h>

#define READ_FLAGS O_CREAT | O_RDONLY
#define WRITE_FLAGS O_CREAT | O_WRONLY | O_TRUNC
#define USER_MODS 0666

int flag = 0;

void handler(int sig_num){

    flag =1;
}


float frobeniusDistance(float matris[3][3]){
    
    int sum=0;
    float result;

    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            sum += pow(matris[i][j],2); 
        }
    }

    result = sqrt(sum);

    return result;

}


int readOutput(int *ans,int fdRead,int index){

    int saver;
    float arr[3][3];
    float buffer[9];


    if (fdRead < 0){
        perror("can't open\n");
        exit(1);
    }

    
    saver = read(fdRead,buffer,9*sizeof(float));
    if(saver == 0){
        *ans = -1;
        return saver;
    }

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            arr[i][j]  = buffer[i*3 + j];
        }
    }


    printf(" %d.Covariance Matrix :",index);
    printf(" {");
    for(int i =0;i<3;i++){
        printf("(%.3f,%.3f,%.3f),",arr[i][0],arr[i][1],arr[i][2]);
    }
    printf("}\n");
    


    *ans = frobeniusDistance(arr);
    return saver;
}



int main(int argc, char *argv[])
{
    struct sigaction sa;
    sa.sa_handler=&handler;
    sigaction(SIGINT, &sa, NULL);
    int number_child = 0;

    if(argc != 5){
        perror("Argument Number must be five\n");
    }

    unsigned char buffer[30];

    pid_t *forkArr = (pid_t *)malloc(1000* sizeof(pid_t));
    

    int fdRead = open(argv[2], READ_FLAGS, USER_MODS);
    int size;

    if (fdRead < 0){
        perror("can't open\n");
        exit(1);
    }

    do{
        size = read(fdRead,buffer,30);
        if(size == 30){
            
            
            printf("Created R_%d with:",number_child);
            for(int i=1;i<=30;i++){
                printf("(%d)",buffer[i-1]);

                if(i%3 == 0){

                    printf(",");
                }
            
            }
            printf("\n");    
            pid_t process_id = fork();

            if(process_id < 0){

                perror("fork failed\n");
                exit(1);
            }

            else if(process_id == 0){
                
                char *args[32];

                for(int i = 0; i < 31; ++i){
                    args[i] = (char*)malloc(200*sizeof(char));
                }

                strcpy(args[0], argv[4]);

                for(int i = 1; i <= 30 ; ++i){
                    sprintf(args[i], "%d", (int)buffer[i-1]);
                   
                }

                args[31] = NULL;
                            
                execv("./processR",args);

                for(int i=0;i<31;i++){
                    free(args[i]);
                }
            }
            else{
                number_child++;
            }
        }
    }while(size == 30);
  
    close(fdRead);

    free(forkArr);

    for(int i = 0; i < number_child; ++i)
        wait(NULL);
    
    fdRead = open(argv[4], READ_FLAGS, USER_MODS);
    int ans;
    float frob_arr[2048];
    int ind = 0;
    int index=0;
    int saver;
    do{
        saver = readOutput(&ans, fdRead,index);
        if(saver > 0)
            frob_arr[ind++] = ans;

            index++;
    }while(saver > 0);

  
    int min;
    int temp_min;
    int ans_1, ans_2;
    
    for(int i=0; i < ind; ++i){
        for(int j = i + 1; j < ind; ++j){
            if(i == 0 && j == 1){
                min = frob_arr[i] - frob_arr[j];
                if(min < 0) min *= -1;
                ans_1 = 0;
                ans_2 = 1;
            }
            else{
                temp_min = frob_arr[i] - frob_arr[j];
                if(temp_min < 0) temp_min *= -1;

                if(temp_min < min){
                    min = temp_min;
                    ans_1 = i;
                    ans_2 = j;
                }
            }

        }
    }

printf("\n");
printf("The Closest 2 matricies are: %d.Matrix and %d.Matrix, and their distance is %f.\n\n", ans_1, ans_2,fabs(frob_arr[ans_1]-frob_arr[ans_2]));

    return 0;
}


