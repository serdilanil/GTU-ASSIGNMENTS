#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int yylex();
int yyerror(char *error);


typedef struct node_s
{
    int value;
    char str[30];
    struct node_s *next;
}node_t;


node_t *head= NULL;
node_t *temp = NULL;


void addValue(char str[30], int value){
    node_t *iter;
    iter=head;
    if (head==NULL) {
        head=(node_t *)malloc(sizeof(node_t));
        head->value=value;
        strcpy(head->str, str);
        head->next=NULL;
    }
    else{
        while(iter->next!=NULL){
            iter=iter->next;
        }
        node_t *temp1=(node_t *)malloc(sizeof(node_t));
        temp1->value=value;
        strcpy(temp1->str, str);
        temp1->next=iter->next;
        iter->next =temp1;
    }
}

// will be used both in init and append situations.
int* appendTwoArray(int *array, int number){ // build if not exist, or append the num.
    if(array == NULL){ // create new arr.
        array = (int *)malloc(sizeof(int)*2);
        array[0] = number;
        array[1] = -1;
    } 
    else{ // expand the old array.
        int *temp = array;
        int size = 0;

        while(*temp != -1){
            ++temp;
            ++size;
        }

        temp = array;
        array = (int*)(malloc(sizeof(int)*(size+2)));

        int i=0;
        for(i;i<size;++i)
            array[i] = temp[i]; // copy old arrayay.
        array[i] = number; // add the item.
        array[i+1] = -1; // new size.
        free(temp);
    } 

    return array;     
}


int getValue(char str[30]){
    node_t *iter;
    iter=head;
    while(iter != NULL){
        if(strcmp(iter->str, str) == 0){
            return iter->value;
		}
        iter=iter->next;
    }
    return -1;// if not found return -1

}


/*concat operation on linked list*/
int* concat(int *element1, int *element2){
    return element2;
}


void print_arr(int *arr){

    printf("( ");
    for(int i=0;arr[i]!=-1; ++i)
        printf("%d ", arr[i]);
    printf(")\n");

}

int rec_pow(int base,int number){
	if(number != 0)
            return (base * rec_pow(base, number-1));

    else    
        return 1;
}

