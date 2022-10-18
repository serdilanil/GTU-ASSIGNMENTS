#include<stdio.h>
#include<fcntl.h> 
#include<errno.h> 
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

#define READ_FLAGS O_CREAT | O_RDONLY
#define WRITE_FLAGS O_CREAT | O_WRONLY | O_TRUNC
#define USER_MODS 0666

struct line
{
    int insensitive,head,dollar;
    char *ptr,*ptr2;

};


char * bufRecord(char *buffer,char *argv); //In this function, I progress character by character and after the desired characters are found, I perform the necessary transformations. I'm using the buffer and the pointer in the structure while moving character by character.
struct line *parse(char *argv);    // When there are specially specified characters in this function, I set the int value that I defined as the flag in the structure to 1 and act accordingly.
int checkInsensitiveFormat(char *buffer, struct line *fl, int record, int i); //Here I wrote this function to operate without character sensitivity.
int checkStringCharacter(char *buffer, struct line *fl, int record, int i,int isStart); //I wrote this function to make the connection between the functions I made here to perform special character manipulations.
int checkHead(struct line *fl, int isStart);  //In this function ,I control the head character for task.
int checkDollar(struct line *fl, int isEnd); //In this function ,I control the dollar symbol for task


int main(int argc, char *argv[]){

    struct flock lock;
    int size;
    char *c = (char *)calloc(1000,sizeof(char));

    if(argc != 3){

        perror("ERROR argc can't bigger than 3!!!!");
        free(c);
        return -1;
    }

    if(argv[1][0] != '/'){
        perror("First Argument is Wrong.");
        exit(1);
    }

    int fdRead = open(argv[2], READ_FLAGS, USER_MODS);
    memset(&lock,0,sizeof(lock));
    lock.l_type = F_WRLCK;
    

    if(fdRead<0){
        perror("Error while Read ");   
        free(c);
        exit(1);
    }
    
    
    size = read(fdRead,c,1000);
    close(fdRead);
    
    if(size<0){     //Error check
        perror("Read process negative");
        exit(1);
    }



    int fdWrite = open(argv[2], WRITE_FLAGS, USER_MODS);
    fcntl(fdWrite,F_SETLKW,&lock);

    c = bufRecord(c,argv[1]);
    
    if(strlen(c) == 0){
        perror("Buffer is empty");
    }
    
    write(fdWrite,c,strlen(c));
    lock.l_type = F_UNLCK;
    fcntl(fdWrite,F_SETLKW,&lock);

    close(fdWrite);


    free(c);

    return 0;
}


struct line *parse(char *argv){

    struct line *sv = (struct line *)malloc(sizeof(struct line));
    sv->dollar = 0;
    sv->head = 0;
    sv->insensitive = 0;
    sv->ptr = NULL;
    sv->ptr2 = NULL;


    char *token;
    char *token2;
     
    
    if(argv[strlen(argv)-1] == 'i'){
        sv->insensitive = 1;
    }

    else{
       sv->insensitive = 0;
    }

    if(argv[strlen(argv)-1] == '^'){
        sv->head = 1;
    }

    if(argv[strlen(argv)-1] == '$'){
        sv->dollar = 1;
    }

    token = strtok(argv,"/");  //Parsing process
    token2 = strtok(NULL,"/");

    if(token[strlen(token) - 1] == '$') //I determine symbols
        sv->dollar = 1;

    if(token[0] == '^')
        sv->head = 1;



    sv->ptr = token;
    sv->ptr2 = token2;

    return sv;

}


int checkInsensitiveFormat(char *buffer, struct line *fl, int record, int i){  //I check the insensitive situation.
    
    return (fl->insensitive == 1 && 
            ((fl->ptr[i] >= 'a' && fl->ptr[i] <= 'z') || (fl->ptr[i] >= 'A' && fl->ptr[i] <= 'Z')) &&
            (buffer[record] + 32 == fl->ptr[i] || buffer[record] - 32 == fl->ptr[i]));
}

int checkHead(struct line *fl, int isStart){
    
    return (!fl->head || isStart);
}

int checkDollar(struct line *fl, int isEnd){
   
    return (!fl->dollar || isEnd);
}


int checkStringCharacter(char *buffer, struct line *fl, int record, int i, int isStart){  //I call the some functions for control.
    return (checkHead(fl, isStart) && (buffer[record] == fl->ptr[i]
            || checkInsensitiveFormat(buffer, fl, record, i)));
}


char *bufRecord(char *buffer,char* argv){ //I do all of the process of file , and I control the wanted word by character character.
    
    struct line *fl = NULL;
    int record = 0;
    int isStart=0;  //for head sign
    int isEnd=0;  //for dollar sign
    fl = parse(argv);

    int correctStr1Len = strlen(fl->ptr);
    
    for(int j = 0 ;j<strlen(buffer);j++){   //I proceed end of the file line and check the searched element and then change it.

        isEnd = 0;
        isStart = 0;

        for(int i=0;i<strlen(fl->ptr) && record < strlen(buffer);i++){  //I searched first element by the ptr pointer.
            int flag =0;

            while(!(fl->ptr[i] == '[' || fl->ptr[i] == ']') && i < strlen(fl->ptr) && (fl->ptr[i] < 'a' || fl->ptr[i] > 'z') && (fl->ptr[i] < 'A' || fl->ptr[i] > 'Z') &&
                    (fl->ptr[i] < '0' || fl->ptr[i] > '9') ){
                        i++;
                        correctStr1Len--;    //In while loop I check the special situation like box bracket or insensitivity.
                            
            }

            if(fl->ptr[i] == '['){
                
                while(fl->ptr[i] != ']'){

                    if(fl->ptr[i] == buffer[record] || (fl->insensitive && (fl->ptr[i] + 32 == buffer[record] || fl->ptr[i] - 32 == buffer[record]))){
                        flag = 1;
                    }                 //In this if condition I check bracket and also insensitivity.

                    i++;    
                }
            
            }

            if(i == strlen(fl->ptr))
                break;

            if(record == 0 || buffer[record-1] == '\n')  //I check the head symbol.
                isStart = 1;
            

            if(checkStringCharacter(buffer, fl, record, i, isStart)){
                flag = 1;
            
            }

            if(!flag){     //I check if searching operation is unsuccesfully.
                isStart=0;
                i = -1;
                if(checkStringCharacter(buffer, fl, record, 0, isStart)){
                    i = 0;
                }
            }
            
            record++;

        }
        int pass = 0;
        
      
        if(record == strlen(buffer) || buffer[record] == '\n'){
        
            isEnd = 1;
        }
        
        if(fl->head && isStart){
            pass = 1;
        }
        else if(fl->dollar && isEnd){
            pass = 1;
        }
        else if(!fl->dollar && !fl->head){
            pass = 1;
        }

        for (int i= 0; i < strlen(fl->ptr2); i++)  //I changed from ptr to ptr2.
        {
        
            if(pass)
                buffer[record-strlen(fl->ptr2)+i] = fl->ptr2[i];

            else
                break; 
        }

        isEnd = 0;
        isStart = 0;

        if(record >= strlen(buffer)-1){
            free(fl);
            return buffer;
        }
    
    }
    free(fl);
    return buffer;

}

