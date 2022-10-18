#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_CAPACITY 256

typedef struct Node Node; 

struct Node {
    int frequency;   //frequency of using the characters we get from the file
    char ch;         //the character we get from the file
    Node* left;
    Node* right;
};

struct Heap {
    Node** arr;  //Array in which we record the information
    int size;
};

typedef struct Heap Heap;

Heap* createHeap();    //I am opening memory for heap array in this function
void insert(Heap *heap, Node *node);   //here I add elements to the memory and expand  size
void heapify_bottom_top(Heap *heap,int index);   // I find the min heap in this function
void heapify_top_bottom(Heap *heap, int parent_node);
Node* pop(Heap *heap);  //In this function I started from index 0 of the array and went from top to bottom
int isLeafNode(Node* node);   //I used this function to check if this node is a leaf
int* createFrequencyArray(char * filename);   //I wrote this function to find the frequencies of the characters in the file
Heap *createHeapFromFrequencyArray(int *frequencyArray);  //I took these frequencies from the array and created a heap.
Node* buildHuffmanTree(char* filename);    //I wrote this function to create a tree using the file in the parameter.
void encode_huffman(Node *head, int index, int *sec_index, char bit_codes[100][100],char res[HEAP_CAPACITY][30]); //In this function, I encode the characters with binary numbers according to the frequencies.
void write_to_file(char *filename, char code[HEAP_CAPACITY][30]); //In this function, I write binary numbers to the encoded.dat file.
char* read_message(char *filename);  //Here I read the file to convert it to binary number.
void clear_array(char arr[], int times);  //clear the array.
void decode(char *encode_file, char *decode_file, char code[HEAP_CAPACITY][30]); //I am converting the binary number in the encoded dat file to characters.


int main()
{
   Node* head = buildHuffmanTree("reference.txt");  //I build my huffman tree according to the reference txt file.

   char bits[100][100]={'\0'};
   char code[HEAP_CAPACITY][30];
   char str[100];
   int index=0,i;
   
    for(i = 0 ; i < HEAP_CAPACITY ; ++i){
        code[i][0] = -1;
    }

   encode_huffman(head, 0, &index, bits,code);
  
   write_to_file("encoded.dat",code);
   decode("encoded.dat", "decoded.txt", code);
    return 0;
}


Heap *createHeap()
{

    Heap *heap = (Heap *)malloc(sizeof(Heap));
    
    if (heap == NULL)
    {
        printf("Memory Error!\n");
        return NULL;
    }
    heap->size = 0;
    
    heap->arr = (Node **)malloc(HEAP_CAPACITY * sizeof(Node*));
    
    if (heap->arr == NULL)
    {
        printf("Memory Error!\n");
        return NULL;
    }
    return heap;
}

void insert(Heap *heap, Node *node)
{
    if (heap->size < HEAP_CAPACITY)
    {
        heap->arr[heap->size] = node;
        heapify_bottom_top(heap, heap->size);
        heap->size++;
    }
}

void heapify_bottom_top(Heap *heap, int index)
{
    Node *temp = malloc(sizeof(Node));
    int parent_node = (index - 1) / 2;

    if (heap->arr[parent_node]->frequency > heap->arr[index]->frequency)
    {
        temp = heap->arr[parent_node];
        heap->arr[parent_node] = heap->arr[index];
        heap->arr[index] = temp;
        heapify_bottom_top(heap, parent_node);
    }
}

void heapify_top_bottom(Heap *heap, int parent_node)
{
    int left = parent_node * 2 + 1;
    int right = parent_node * 2 + 2;
    int min;
    Node *temp = malloc(sizeof(Node));

    if (left >= heap->size || left < 0)
        left = -1;
    if (right >= heap->size || right < 0)
        right = -1;

    if (left != -1 && heap->arr[left]->frequency < heap->arr[parent_node]->frequency)
        min = left;
    else
        min = parent_node;
    if (right != -1 && heap->arr[right]->frequency < heap->arr[min]->frequency)
        min = right;

    if (min != parent_node)
    {
        temp = heap->arr[min];
        heap->arr[min] = heap->arr[parent_node];
        heap->arr[parent_node] = temp;
        heapify_top_bottom(heap, min);
    }
}

Node* pop(Heap *heap)
{
    Node *pop;
    pop = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify_top_bottom(heap, 0);
    return pop;
}

int isLeafNode(Node *node)
{
    if (node->left == NULL && node->right==NULL)
        return 1;
    return 0;
}

int *createFrequencyArray(char *filename)
{

    FILE *filePointer;
    int *frequencyArray = (int *)malloc(HEAP_CAPACITY * sizeof(int));
    char ch;
    for (int i = 0; i < HEAP_CAPACITY; i++)
    {
        frequencyArray[i] = 0;
    }
    if (NULL == (filePointer = fopen(filename, "r")))
    {
        printf("Failed to open file : %s\n",filename);
        return NULL;
    }
    for (ch = fgetc(filePointer); ch != EOF; ch = fgetc(filePointer))
    {
        frequencyArray[ch] += 1;
    }
    
    fclose(filePointer);
    
    return frequencyArray;
}

Heap *createHeapFromFrequencyArray(int *frequencyArray)
{
    Heap *heap = createHeap();
    for (int i = 0; i < HEAP_CAPACITY; i++)
    {
        if (frequencyArray[i] > 0)
        {
            Node *node = malloc(sizeof(Node));
            node->frequency = frequencyArray[i];
            node->ch = i;
            node->left = NULL;
            node->right = NULL;
            insert(heap, node);
        }
    }
    
    return heap;
}

Node* buildHuffmanTree(char* filename) {
    
    int *frequencyArray;
    frequencyArray = createFrequencyArray(filename);
    Heap* heap = createHeapFromFrequencyArray(frequencyArray);


    while (heap->size > 1)
    {   
        Node *left = pop(heap);
        Node *right = pop(heap);

        Node *newNode = malloc(sizeof(Node));
        newNode->frequency = left->frequency + right->frequency;
        newNode->left = left;
        newNode->right = right;
        insert(heap, newNode);

    }
    free(frequencyArray);
    return pop(heap);
}


void encode_huffman(Node *head, int index, int *sec_index, char bit_codes[100][100], char res[HEAP_CAPACITY][30]){
    if(isLeafNode(head)){
        bit_codes[*sec_index][index]='\0';
        strcpy(res[head->ch],bit_codes[*sec_index]);
        
        (*sec_index)+=1;
    }
    else{
        bit_codes[*sec_index][index]='0';
        encode_huffman(head->left, index+1, sec_index, bit_codes,res);
        for(int i=0; i<index; i++){
            bit_codes[*sec_index][i]=bit_codes[*sec_index-1][i];
        }
        bit_codes[*sec_index][index]='1';
        encode_huffman(head->right, index+1, sec_index, bit_codes,res);
    }
}

char* read_message(char *filename){
    char *str = (char*)malloc(sizeof(char));
    char ch;
    int size = 0,capacity = 1;
    FILE *filePointer;

    if (NULL == (filePointer = fopen(filename, "r")))
    {
        printf("Failed to open file : %s\n",filename);
        return NULL;
    }
    for (ch = fgetc(filePointer); ch != EOF; ch = fgetc(filePointer))
    {
        if(size == capacity){
            capacity *= 2;
            str = realloc(str,capacity * sizeof(char));
        }
        str[size++] = ch;
    }
    str[size] = '\0';

    return str;
}

void write_to_file(char *filename, char code[HEAP_CAPACITY][30]){
    char *str = read_message("message.txt");
    FILE *filePointer;
    int i,y;

    if (NULL == (filePointer = fopen(filename, "wb")))
    {
        printf("Failed to open file : %s\n",filename);
        return;
    }

    for(i = 0 ; str[i] != '\0' ; ++i){
        y = str[i];
        fwrite(code[y],sizeof(char),strlen(code[y]),filePointer);
    }

    free(str);
    fclose(filePointer);
}

void clear_array(char arr[], int times){
    for(int k=0; k<times; k++){
        arr[k]='\0';
    }
}

void decode(char *encode_file, char *decode_file, char code[HEAP_CAPACITY][30]){
    char temp[30]={'\0'};
    int counter=0;
    FILE *encfp;
    FILE *decfp;

    encfp=fopen(encode_file, "rb");
    decfp=fopen(decode_file, "w");

    for(int i=0; !feof(encfp); i++){
        fread(&temp[i], 1, 1, encfp);
        for(int j=0; j<HEAP_CAPACITY; j++){
            if(strncmp(temp, code[j], strlen(code[j]))==0){
                fprintf(decfp, "%c", j);
                clear_array(temp, i+1);
                j=HEAP_CAPACITY;
                i=-1;
            }
        }
    }
}