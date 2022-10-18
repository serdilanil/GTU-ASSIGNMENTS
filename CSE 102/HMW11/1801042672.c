#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

struct Node{  //I created this structure to add elements to the linked list.

	int data;
	struct Node * next;

};

struct Node* head; //I use this definition when I get linked list numbers from the file.

struct numbers{ //I use this structure to suppress different numbers in the linked list and dynamic array in part2.

	int n1; //different number in the dynamic array.
	int n2; //different number in the linked list.
};

int *read_array(char *filename,int *num,int *used); //In this function, I throw the numbers I get from the file I read dynamically.
void read_linkedlist(char *filename,int x,int *used2);  //I assign the numbers in the file I read in this function to the linked list.
float * stats_array(int *A,int num);  //here I do the necessary operations by processing the numbers in the dynamic array.
float * stats_linkedlist(struct Node* head);  //here, I do the necessary operations by processing the numbers in the linked list.
void add(int x);    //In this function, while adding numbers from the file to the linked list, I add a node to the linked list.
void insert(struct Node** root, int item); //I use this function to add a node to the linked list in part 2 and I changed some numbers by random funciton.
struct Node *arrayToList(int *v, int size);	//In this function, I transfer the numbers entered by the user in dynamic array to the linked list.
void display(struct Node* root);   //I used this function to show the changing numbers in the linked list.
void findDif(struct Node *temp,int *v,struct numbers *number,int size); //In this function, I print the dynamic array and the different numbers in the linked list.


int main(){

	float *Array,*Arr;
	int x,i,count,used=0,used2=0;
	int *A,num,number2;
	double tk,ta,sa,sk;
	A = read_array("list.txt",&num,&used); //I call the functions to in main.
	
	read_linkedlist("list.txt",x,&used2);
	
	Array = (float*)malloc(sizeof(float)*8);
	Array = stats_array(A,num);
	

	printf("\n\n(FOR READ ARRAY:)\n");   //here I print the result of my operations in the dynamic array.
	printf("Number of byte used :%d\n",used);
	printf("-----------------------------------------------------------------------------------\n");
	

	printf("MEAN:\t          MAX:\t         MIN:\t       STANDART DEVIATION:\n");
		
		for(i=0;i<4;i++){

			printf("%f\t",Array[i]);
		}

	printf("\n--------------------------------------------------------------------------------\n");

		Arr = stats_linkedlist(head);
		
		printf("\n\n(FOR READ LINKED LIST:)\n"); //here I print the result of my actions on the linked list.
		printf("Number of byte used:%d\n",used2);
		printf("\n------------------------------------------------------------------------------\n");

	printf("MEAN:\t          MAX:\t         MIN:\t       STANDART DEVIATION:\n");


			for(i=0;i<4;i++){

				printf("%f\t",Arr[i]);
			}


	printf("\n--------------------------------------------------------------------------------\n");


	clock_t t; //here I measure the time of functions when performing operations.
	t = clock();
	read_array("list.txt",&num,&used);
	t = clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;

	clock_t t2;
	t2 = clock();
	read_linkedlist("list.txt",x,&used2);
	t2 = clock()-t2;
	double time_taken2 = ((double)t2)/CLOCKS_PER_SEC;


	clock_t t5;
	t5 = clock();
	read_linkedlist("list.txt",x,&used2);
	t5 = clock()-t5;
	double time_taken5 = ((double)t5)/CLOCKS_PER_SEC;

	
	clock_t t6; //here I measure the time of functions when performing operations.
	t6 = clock();
	read_array("list.txt",&num,&used);
	t6 = clock()-t6;
	double time_taken6 = ((double)t6)/CLOCKS_PER_SEC;


	clock_t t7; //here I measure the time of functions when performing operations.
	t7 = clock();
	read_array("list.txt",&num,&used);
	t7 = clock()-t7;
	double time_taken7 = ((double)t7)/CLOCKS_PER_SEC;

	clock_t t8;
	t8 = clock();
	read_linkedlist("list.txt",x,&used2);
	t8 = clock()-t8;
	double time_taken8 = ((double)t8)/CLOCKS_PER_SEC;

	clock_t t9; //here I measure the time of functions when performing operations.
	t9 = clock();
	read_array("list.txt",&num,&used);
	t9 = clock()-t9;
	double time_taken9 = ((double)t9)/CLOCKS_PER_SEC;

	clock_t t10;
	t10 = clock();
	read_linkedlist("list.txt",x,&used2);
	t10 = clock()-t10;
	double time_taken10 = ((double)t10)/CLOCKS_PER_SEC;

	clock_t t3;
	t3 = clock();
	stats_array(A,num);
	t3 = clock()-t3;
	double time_taken3 = ((double)t3)/CLOCKS_PER_SEC;


	clock_t t4;
	t4 = clock();
	stats_linkedlist(head);
	t4 = clock()-t4;
	double time_taken4 = ((double)t4)/CLOCKS_PER_SEC;
	
	
	clock_t t11;
	t11 = clock();
	stats_linkedlist(head);
	t11 = clock()-t11;
	double time_taken11 = ((double)t11)/CLOCKS_PER_SEC;

	clock_t t12;
	t12 = clock();
	stats_array(A,num);
	t12 = clock()-t12;
	double time_taken12 = ((double)t12)/CLOCKS_PER_SEC;

	clock_t t13;
	t13 = clock();
	stats_array(A,num);
	t13 = clock()-t13;
	double time_taken13 = ((double)t13)/CLOCKS_PER_SEC;


	clock_t t14;
	t14 = clock();
	stats_linkedlist(head);
	t14 = clock()-t14;
	double time_taken14 = ((double)t14)/CLOCKS_PER_SEC;


	clock_t t15;
	t15 = clock();
	stats_array(A,num);
	t15 = clock()-t15;
	double time_taken15 = ((double)t15)/CLOCKS_PER_SEC;
	
	clock_t t16;
	t16 = clock();
	stats_linkedlist(head);
	t16 = clock()-t16;
	double time_taken16 = ((double)t16)/CLOCKS_PER_SEC;

	ta = (time_taken + time_taken6 + time_taken7 + time_taken9)/4;  //I take the average values of time of operations.
	tk = (time_taken2 + time_taken5 + time_taken8 + time_taken10)/4;

	sa = (time_taken3 + time_taken12 + time_taken13 + time_taken15)/4;
	sk = (time_taken4 + time_taken11 + time_taken14 + time_taken16)/4;
	

	printf("\nPASSED TIME IN *READ ARRAY (AVERAGE TIME) %f\n",ta);
	printf("\nPASSED TIME IN *READ LINKED LIST (AVERAGE TIME) %f\n",tk);
	printf("\nPASSED TIME IN *STATS ARRAY (AVERAGE TIME) %f\n",time_taken3);
	printf("\nPASSED TIME IN *STATS LINKED LIST(AVERAGE TIME) %f\n",time_taken4);
	

	struct numbers *number;  //Since I will assign the numbers that are different in part2 to the dynamic array, I have defined a structure array.

    srand (time(NULL));  //The reason I use this function is to change some of the numbers I transferred from part2 to the linked list in part2 and find different numbers between the two.
   
	int size = 0;
    
    int *v = NULL;
    
    int val;
    
    printf("\n\nWrite a group of real numbers for dynamic array. Write -1 if you want to stop writing numbers\n");
    
    printf("Write a number\n");
    
    while(scanf("%d", &val) == 1 && val != -1)   //here I add elements to the dynamic array with user input.
    {
        v = realloc(v, (size+1) * sizeof(int));
        v[size++] = val;
        printf("Write a number\n");
    }

    struct Node* root = arrayToList(&v[0],size);  //here I transfer the elements in the dynamic array to the linked list.
    printf("(linked list values:) (numbers were transferred from the dynamic array and replaced by random function.):\n");
    display(root);   //here I press the linked list whose elements have been changed with the random function to the terminal.
    
    printf("(Dynamic Array Results:)\n");
    
    for(i=0; i<size; i++)
        printf("%d\n", v[i]);

    printf("\nDifferent numbers in the dynamic array and linked list:\n\n");

    findDif(root,&v[0],number,size);

    free(v);



	return 0;
}


int *read_array(char *filename,int *num,int *used){ //In this function, I throw the numbers I get from the file I read dynamically.
	int number2;
	int *A;
	int count=1,y;
	A = NULL;
	int i;
	*used=0;
	FILE *fp;
	fp = fopen("list.txt","r");

	A = (int*)malloc(sizeof(int)*count);

	while(!feof(fp)){

		if(fscanf(fp,"%d, ",&number2) > 0)
		
			A[count-1] = number2;
			count++;
			
			A = (int*)realloc(A,sizeof(int)* count); //here I used the realloc function to make size for file's data.
			*used +=sizeof(int); //here I used to measure the total bytes used in the dynamic array.
	}		
				
	
		*num = count-1;
		
		return 	A;

	fclose(fp);


}


void read_linkedlist(char *filename,int x,int *used2){  //I assign the numbers in the file I read in this function to the linked list.

		int counter = 0,j;
		head = NULL;
		*used2=0;
		FILE *fptr;
		fptr = fopen("list.txt","r");
			
			while(!feof(fptr)){
				
				if(fscanf(fptr,"%d, ",&x)==1){				
					
					add(x);
					counter++;
				}			

			*used2 +=sizeof(struct Node); //here I used to measure the total bytes used in the linked list.
			}


}

float * stats_array(int *A,int num){  //here I do the necessary operations by processing the numbers in the dynamic array.

	int i,count;
	int max = A[0];
	int min = A[0];
	float s = 0.0;
	float *Array;
	double sum_dev = 0.00;
	Array = (float*)malloc(sizeof(float)*8);
	

	for(i=0;i<num;i++){   //here I transfer the numbers to the array by using adding operation.

		s = s + A[i];
	}
	
			//I transfer the results I find here to the float array and return the array.

		Array[0] = s/num;  // I finding the mean of dynamic array.

			for(i=1;i<num;i++)
				if(A[i] > max)
					max = A[i];  //I finding max.
			
				Array[1] = max;


			for(i=1;i<num;i++)	
					if(A[i] < min)
						min = A[i];

				Array[2] = min;   //I finding min.



		for(i=0;i<num;i++){

			sum_dev +=(A[i] - s/num) * (A[i] - s/num);  
		}
			

			Array[3] = sqrt(sum_dev/num); //I finding standart deviation.
	
			return Array;
				
	free(A);

}


float * stats_linkedlist(struct Node* head){  //here I do the necessary operations by processing the numbers in the linked list.

	int cnt = 0;
	double sum = 0;
	double avg = 0.0,sum_devi = 0.0;
	float *Arr;
	float min = 327672;
	float max = -327672;
	Arr = (float*)malloc(sizeof(float)*8);



	while(head != NULL){ 

		cnt++;

		if(min > head->data)
			min = head->data;
	
			if(max< head->data)
				max = head->data;
				
				sum += head->data;
				
			
				sum_devi += (head->data - sum/cnt) * (head->data - sum/cnt);

				head = head->next;

	}
		//I transfer the results I find here to the float array and return the array.
		Arr[0] = sum/cnt;// I finding the mean of linked list.
		Arr[1] = max;   
		Arr[2] = min;
		Arr[3] = sqrt(sum_devi/cnt); // I finding the standart deviation the linked list.


		return Arr;
	
}


void add(int x){    //In this function, while adding numbers from the file to the linked list, I add a node to the linked list.

		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp ->data = x;
		temp -> next = head;
		head = temp;		
}


void insert(struct Node** root, int item) //I use this function to add a node to the linked list in part 2 and I changed some numbers by random funciton.
{ 
   struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
   struct  Node* ptr; 
   
    temp->data = item; 
    temp->next = NULL; 
  
    if (*root == NULL) 
        *root = temp; 
    
    else { 
        ptr = *root; 
        
        while (ptr->next != NULL)
        	ptr = ptr->next;
        ptr->next = temp;
        temp ->data= rand()%2000;
    } 
} 


struct Node *arrayToList(int *v, int size) //In this function, I transfer the numbers entered by the user in dynamic array to the linked list.
{ 
    struct Node *root = NULL; 
    for (int i = 0; i < size; i++) 
        insert(&root, v[i]); 
   return root; 
} 



void display(struct Node* root) //I used this function to show the changing numbers in the linked list.
{ 
    while (root != NULL) { 
        printf("%d\n",root->data);
        root = root->next; 
    } 
} 

void findDif(struct Node *temp,int *v,struct numbers *number,int size){  //In this function, I print the dynamic array and the different numbers in the linked list.

    int i,n1,n2,j=0;
    number =(struct numbers*)malloc(sizeof(struct numbers)); //here I am dimensioning the array of structures where I transfer the numbers n1 ne n2.

    for(i=0;i<size;i++){

        if(v[i] != temp->data){  //here if the numbers in the linked list and the dynamic array are different, I transfer them to the structure array.
            
            number[j].n1 = v[i];
            number[j].n2 = temp->data;
            temp = temp->next;
            j++;

            number =realloc(number,(j+1)*sizeof(struct numbers));

            printf("different number is for dynamic array %d\n",number[j-1].n1);
            printf("different number is for linked list %d\n\n",temp->data);

        }
    }

}