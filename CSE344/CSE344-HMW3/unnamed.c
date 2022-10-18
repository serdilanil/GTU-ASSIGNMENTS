#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <unistd.h>


typedef struct Ingredient{
    char array[2];
    sem_t wholeSaler_wait,mutex;
    sem_t s_cf0,s_cf1,s_cf2,s_cf3,s_cf4,s_cf5;
    sem_t s_milk,s_sugar,s_walnuts,s_flour;
    bool sugar, milk, walnuts, flour;


}Ingredient;


Ingredient* init_sharedMemory(){
    size_t len = 4096;
    Ingredient *ing = NULL;
    
    int shm_fd = shm_open("test",O_CREAT|O_RDWR,0666);
    ftruncate(shm_fd, len);
     
    ing = (Ingredient*)mmap(NULL, sizeof(Ingredient),
            PROT_READ | PROT_WRITE,
            MAP_SHARED, shm_fd, 0);
    
    
    sem_init(&(ing->wholeSaler_wait),4,0);
    sem_init(&(ing->mutex),4,1);
    sem_init(&(ing->s_cf0),4,0);
    sem_init(&(ing->s_cf1),4,0);
    sem_init(&(ing->s_cf2),4,0);
    sem_init(&(ing->s_cf3),4,0);
    sem_init(&(ing->s_cf4),4,0);
    sem_init(&(ing->s_cf5),4,0);
    sem_init(&(ing->s_sugar),4,0);
    sem_init(&(ing->s_walnuts),4,0);
    sem_init(&(ing->s_flour),4,0);
    sem_init(&(ing->s_milk),4,0);

    return ing;

}


int chefs0(Ingredient *order,int id,int id2){
    int counter =0;
    
    while(1){
        printf("chef0 (pid %d) is waiting for walnuts and sugar ( )\n",id);
        sem_wait(&(order->s_cf0)); 
            printf("chef0 (pid %d) has taken the sugar\n",id);
            printf("chef0 (pid %d) has taken the walnuts\n",id);
            printf("chef0 (pid %d) is preparing the dessert (%c%c)\n",id,order->array[0],order->array[1]);
            printf("the wholesaler (pid %d) is waiting for the dessert (%c%c)\n",id2,order->array[0],order->array[1]);
            printf("chef0 (pid %d) has delivered the dessert (%c%c)\n",id,order->array[0],order->array[1]);
            printf("the wholesaler (pid %d) has obtained the dessert and left (%c%c)\n",id2,order->array[0],order->array[1]);
            printf("chef0 (pid %d) is exiting (%c%c)\n",id,order->array[0],order->array[1]);
            sem_post(&(order->wholeSaler_wait));

        
        counter++;
        
    }
    
}


int chefs1(Ingredient *order,int id,int id2){

    int counter = 0;

    while(1){    
        printf("\nchef1 (pid %d) is waiting for flour and walnuts ( )\n",id);
        sem_wait(&(order->s_cf1));   
            printf("chef1 (pid %d) has taken the flour\n",id);
            printf("chef1 (pid %d) has taken the walnuts\n",id);
            printf("chef1 (pid %d) is preparing the dessert (%c%c)\n",id,order->array[0],order->array[1]);
            printf("the wholesaler (pid %d) is waiting for the dessert (%c%c)\n",id2,order->array[0],order->array[1]);
            printf("chef1 (pid %d) has delivered the dessert (%c%c)\n",id,order->array[0],order->array[1]);
            printf("the wholesaler (pid %d) has obtained the dessert and left (%c%c)\n",id2,order->array[0],order->array[1]);
            printf("chef1 (pid %d) is exiting (%c%c)\n",id,order->array[0],order->array[1]);
            sem_post(&(order->wholeSaler_wait));
        
        counter++;
        
    }

    return counter;
}

int chefs2(Ingredient *order,int id,int id2){

    int counter = 0;
    printf("chef2 (pid %d) is waiting for flour and sugar ( )\n",id);    

    while(1){    
        sem_wait(&(order->s_cf2));
            printf("chef2 (pid %d) has taken the sugar\n",id);
            printf("chef2 (pid %d) has taken the flour\n",id);
            printf("chef2 (pid %d) is preparing the dessert (%c%c)\n",id,order->array[0],order->array[1]);
            printf("the wholesaler (pid %d) is waiting for the dessert (%c%c)\n",id2,order->array[0],order->array[1]);
            printf("chef2 (pid %d) has delivered the dessert (%c%c)\n",id,order->array[0],order->array[1]);
            printf("the wholesaler (pid %d) has obtained the dessert and left (%c%c)\n",id2,order->array[0],order->array[1]);
            printf("chef2 (pid %d) is exiting (%c%c)\n",id,order->array[0],order->array[1]);
            sem_post(&(order->wholeSaler_wait));
        counter++;
        
    }

    return counter;

}

int chefs3(Ingredient *order,int id,int id2){
    
    int counter = 0;
    printf("chef3 (pid %d) is waiting for flour and milk ( )\n",id);    

    while(1){    
        sem_wait(&(order->s_cf3));
            printf("chef3 (pid %d) has taken the milk\n",id);
            printf("chef3 (pid %d) has taken the flour\n",id);
            printf("chef3 (pid %d) is preparing the dessert (%c%c)\n",id,order->array[0],order->array[1]);
            printf("the wholesaler (pid %d) is waiting for the dessert (%c%c)\n",id2,order->array[0],order->array[1]);
            printf("chef3 (pid %d) has delivered the dessert (%c%c)\n",id,order->array[0],order->array[1]);
            printf("the wholesaler (pid %d) has obtained the dessert and left (%c%c)\n",id2,order->array[0],order->array[1]);
            printf("chef3 (pid %d) is exiting (%c%c)\n",id,order->array[0],order->array[1]);
            sem_post(&(order->wholeSaler_wait));
            
        counter++;
        
    }

    return counter;
}

int chefs4(Ingredient *order,int id,int id2){
    int counter = 0;
    printf("chef4 (pid %d) is waiting for milk and walnuts ( )\n",id);    

    while(1){    
        sem_wait(&(order->s_cf4));
            printf("chef4 (pid %d) has taken the milk\n",id);
            printf("chef4 (pid %d) has taken the walnuts\n",id);
            printf("chef4 (pid %d) is preparing the dessert (%c%c)\n",id,order->array[0],order->array[1]);
            printf("the wholesaler (pid %d) is waiting for the dessert (%c%c)\n",id2,order->array[0],order->array[1]);
            printf("chef4 (pid %d) has delivered the dessert (%c%c)\n",id,order->array[0],order->array[1]);
            printf("the wholesaler (pid %d) has obtained the dessert and left (%c%c)\n",id2,order->array[0],order->array[1]);
            printf("chef4 (pid %d) is exiting (%c%c)\n",id,order->array[0],order->array[1]);
            sem_post(&(order->wholeSaler_wait));
          
        counter++;
        
    }
    return counter;

}

int chefs5(Ingredient *order,int id,int id2){
    
    int counter = 0;
    printf("chef5 (pid %d) is waiting for sugar and milk ( )\n",id);    

    while(1){    
        sem_wait(&(order->s_cf5));
        
            printf("chef5 (pid %d) has taken the milk\n",id);
            printf("chef5 (pid %d) has taken the sugar\n",id);
            printf("chef5 (pid %d) is preparing the dessert (%c%c)\n",id,order->array[0],order->array[1]);
            printf("the wholesaler (pid %d) is waiting for the dessert (%c%c)\n",id2,order->array[0],order->array[1]);
            printf("chef5 (pid %d) has delivered the dessert (%c%c)\n",id,order->array[0],order->array[1]);
            printf("the wholesaler (pid %d) has obtained the dessert and left (%c%c)\n",id2,order->array[0],order->array[1]);
            printf("chef5 (pid %d) is exiting (%c%c)\n",id,order->array[0],order->array[1]);
            sem_post(&(order->wholeSaler_wait));

        counter++;
        
    }
    return counter;

}

void helper0(Ingredient *order){
     
     
    while (1)
    {
        
        sem_wait(&(order->s_milk));
        sem_wait(&(order->mutex));

        if(order->sugar == true){
            order->sugar=false;
            sem_post(&(order->s_cf5));
        
        }

        else if(order->flour == true){
            order->flour = false;
            sem_post(&(order->s_cf3));
        
        }

        else if(order->walnuts == true){
            order->walnuts = false;
            sem_post(&(order->s_cf4));
        }

        else
            order->milk=true;

        sem_post(&(order->mutex));
    }
         
}

void helper1(Ingredient *order){
    while (1)
    {
    
        sem_wait(&(order->s_flour));
        sem_wait(&(order->mutex));

        if(order->sugar == true){
            order->sugar=false;
            sem_post(&(order->s_cf2));
        
        }

        else if(order->milk == true){
            order->milk = false;
            sem_post(&(order->s_cf3));
        }

        else if(order->walnuts == true){
            order->walnuts = false;
            sem_post(&(order->s_cf1));
        }

        else
            order->flour = true;

        sem_post(&(order->mutex));
    }
     
     
}

void helper2(Ingredient *order){

     while (1)
     {
        sem_wait(&(order->s_walnuts));
        sem_wait(&(order->mutex));

        if(order->sugar == true){
            order->sugar=false;
            sem_post(&(order->s_cf0));
        }

        else if(order->milk == true){
            order->milk = false;
            sem_post(&(order->s_cf4));
        }

        else if(order->flour == true){
            order->flour = false;
            sem_post(&(order->s_cf1));
        }

        else
            order->walnuts = true;

        sem_post(&(order->mutex));
    }
     
    
}


void helper3(Ingredient *order){

     while (1)
     {
        sem_wait(&(order->s_sugar));
        sem_wait(&(order->mutex));

        if(order->flour == true){
            order->flour=false;
            sem_post(&(order->s_cf2));
        }

        else if(order->milk == true){
            order->milk = false;
            sem_post(&(order->s_cf5));
        
        }

        else if(order->walnuts == true){
            order->walnuts = false;
            sem_post(&(order->s_cf0));
        }

        else
            order->sugar = true;

        sem_post(&(order->mutex));
    }
     
}

int main(int argc, char *argv[])
{

    int id6 = getpid();
    setvbuf(stdout, NULL, _IONBF, 0);
    int chef0,chef1,chef2,chef3,chef4,chef5;
    Ingredient *ch=init_sharedMemory();


  pid_t pd = fork();
   if(pd == 0){
       int id = getpid();
       chef0 = chefs0(ch,id,id6);
       return chef0;
   }
   
    
    pid_t pd2 = fork();
    if(pd2 == 0){
        int id2 = getpid();
        chef1 = chefs1(ch,id2,id6);
        return chef1;
    }
   
  
   
    pid_t pd3 = fork();
    if(pd3 == 0){
        int id3= getpid();
       chef2 = chefs2(ch,id3,id6);
       return chef2;
    }

   
    pid_t pd4 = fork();
    if(pd4 == 0){
        int id4 = getpid();
       chef3 = chefs3(ch,id4,id6);
       return chef3;
    }
   
    
    pid_t pd5 = fork();
    if(pd5 == 0){
        int id4 = getpid();
       chef4 = chefs4(ch,id4,id6);
       return chef4;
    }
   
   
    pid_t pd6 = fork();
    if(pd6 == 0){
        int id5 = getpid();
        chef5 = chefs5(ch,id5,id6);
        return chef5;
    }

    pid_t pd7 = fork();
    if(pd7 == 0){
       helper0(ch);
       return 0;
    }
    
    pid_t pd8 = fork();
    if(pd8 == 0){
       helper1(ch);
       return 0;
    }

    pid_t pd9 = fork();
    if(pd9 == 0){
       helper2(ch);
       return 0;
    }

    pid_t pd10 = fork();
    if(pd10 == 0){
       helper3(ch);
       return 0;
    }

    
    int countdesert=0;

    FILE *fp;
    

    fp = fopen(argv[2],"r");
    
    if(fp == NULL){
        printf("cannot open file.\n");
        return 1;
    }
    
    while(1){
        sem_wait(&(ch->mutex));
    char c;
        
        int count =0;

        do{
            c = fgetc(fp);
            if(c == '\n' || c == EOF)break;
            ch->array[count] = c;
            count++;
        }while (c);
                

        if(ch->array[0] == 'S' || ch->array[1] == 'S')
            sem_post(&(ch->s_sugar));
        if(ch->array[0] == 'W' || ch->array[1] == 'W')
            sem_post(&(ch->s_walnuts));
        if(ch->array[0] == 'M' || ch->array[1] == 'M')
            sem_post(&(ch->s_milk));
        if(ch->array[0] == 'F' || ch->array[1] == 'F')
            sem_post(&(ch->s_flour));
    
        
        if((ch->array[0] == 'W' && ch->array[1] =='S') || (ch->array[0] == 'S' && ch->array[1] =='S')){
            printf("The wholesaler (pid %d) delivered walnuts and sugar (%c%c)\n",id6,ch->array[0],ch->array[1]);
        }


       if((ch->array[0] == 'F' && ch->array[1] =='W') || (ch->array[0] == 'W' && ch->array[1] =='F')){
            printf("The wholesaler (pid %d) delivered flour and walnut (%c%c)\n",id6,ch->array[0],ch->array[1]);
        }

        if((ch->array[0] == 'S' && ch->array[1] =='F') ||(ch->array[0] == 'F' && ch->array[1] =='S')){
            printf("The wholesaler (pid %d) delivered flour and sugar (%c%c)\n",id6,ch->array[0],ch->array[1]);
        }

        if((ch->array[0] == 'F' && ch->array[1] =='M') ||(ch->array[0] == 'M' && ch->array[1] =='F')){
            printf("The wholesaler (pid %d) delivered flour and milk (%c%c)\n",id6,ch->array[0],ch->array[1]);
        }

        if((ch->array[0] == 'W' && ch->array[1] =='M') || (ch->array[0] == 'M' && ch->array[1] =='W')){
            printf("The wholesaler (pid %d) delivered milk and walnut (%c%c)\n",id6,ch->array[0],ch->array[1]);
        }
        
        if((ch->array[0] == 'S' && ch->array[1] =='M') || (ch->array[0] == 'M' && ch->array[1] =='S')){
            printf("The wholesaler (pid %d) delivered milk and sugar (%c%c)\n",id6,ch->array[0],ch->array[1]);
        }
         

        sem_post(&(ch->mutex));
        sem_wait(&(ch->wholeSaler_wait));
        countdesert++;
        if(c== EOF) break;

    }

    printf("The wholesaler pid(%d) is done (total deserts: %d) \n",id6,countdesert);

    kill(pd, SIGINT);
    kill(pd2, SIGINT);
    kill(pd3, SIGINT);
    kill(pd4, SIGINT);
    kill(pd5, SIGINT);
    kill(pd6, SIGINT);
    kill(pd7, SIGINT);
    kill(pd8, SIGINT);
    kill(pd9, SIGINT);
    kill(pd10, SIGINT);


    for(int i = 0; i < 10; ++i)
        wait(NULL);
    return 0;
}


