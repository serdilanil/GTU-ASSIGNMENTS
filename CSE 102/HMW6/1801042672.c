#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD 100
#define NUM_WORDS 10

//function prototypes
void Rand_func(char randwords[NUM_WORDS][MAX_WORD]); //In this function I get random 10 words from txt file.
int is_empty(int x, int y, int direct, char g_table[20][20], int len); //here I have assigned the character '-' in the table, except for the words, and then I will fill these places with random letters.
void fill_random(char g_table[20][20], char randwords[NUM_WORDS][MAX_WORD]); //In this function, I assign places to random words.
char random_letter(char arr[20][20]); //In this function, I assign random letters to places other than words in the table.
int user_find(int user_row, int user_column, char user_word[15], int word_size, char g_table[20][20]); //Thanks to this function, when the user enters the correct words he finds, the word becomes uppercase in the table and gets score points.
void words_printer(char randwords[NUM_WORDS][MAX_WORD]);  //Thanks to this function, the words that the user needs to find are printed on the table each time the program is refreshed.
int main()
{
    int x=0, flag,user_column, word_size,count;
    int arr1[10];
    int arr2[100];
    char words[NUM_WORDS][MAX_WORD], c, g_table[20][20], user_word[15],user_row;
 
    srand((unsigned)time(NULL)); //for random word and letter

    
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            g_table[i][j] = '-'; //here I place the '-' character in places other than words, then I will assign random letters instead.
        }
    }

    Rand_func(words); //I call my functions
    fill_random(g_table, words);
    random_letter(g_table);

while(x!=10){  //When the number of words we find here is 10, the program will close.
    words_printer(words);
    
    printf("   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19\n");
    for (int i = 0; i < 20; i++)
    {   
        printf("%c  ",i+'A');
            for (int j = 0; j < 20; j++)
            {
                printf("%c  ", g_table[i][j]); //consist the board in there
            }
            printf("\n");
    }
    
    printf("\nPlease enter your guess in this format (letter number word) (for example E5 word) if you want to exit please write exit:\n");  //here if the user wants to exit, he can press the exit button.
    scanf(" %c%d %s", &user_row, &user_column, user_word);  ////here the information that the user will enter is defined in scanf.
    if(user_row == 'e'){
	printf("time to go have a nice day.\n"); 
	printf("Score : %d\n" , x);
	exit(0);	
    }  
    flag = user_find(user_row-'A', user_column, user_word, strlen(user_word), g_table); //Here I called the function to enlarge the words the user will find in the table.
        
        
     if(!flag) //If the user enters the wrong word or coordinate, the program will give a warning.
     {
         printf("please try again\n");
     }

     else if (flag)  //Whenever he/she knows, 1 point will be added to his score and this game will continue up to 10 points.
     {
         x++;
     }

     printf("Score : %d\n" , x);

}
    
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%c  ", g_table[i][j]);
        }
        printf("\n");
    }

    return 0;
}
void words_printer(char randwords[NUM_WORDS][MAX_WORD]){  //here, I print the words that the user needs to find at the top of the table every time.
for (int i = 0; i < NUM_WORDS; i++)
    {
        printf("\t\t%s", randwords[i]);
    }
}
void Rand_func(char randwords[NUM_WORDS][MAX_WORD])  //I use it here to get words from the file randomly.
{

    /* Open words file */
    FILE *fp = fopen("words.txt", "r");

    if (fp == NULL)
    {
        perror("Unable to locate word list");
        exit(EXIT_FAILURE);
    }

                                     //Count words in file 
    char word[MAX_WORD];
    long num = 0;
    while (fgets(word, sizeof(word), fp) != NULL)
    {
        ++num;
    }

                                         // Store random words in array 
    for (int i = 0; i < NUM_WORDS; i++)
    {
        rewind(fp);
        int sel = rand() % num + 1;
        for (int j = 0; j < sel; j++)
        {
            if (fgets(word, sizeof(word), fp) == NULL)
            {
                perror("Error in fgets()");
            }
        }

        strcpy(randwords[i], word);

        //printf("\t\t%s", randwords[i]);
    }

    if (fclose(fp) != 0)
    {
        perror("Unable to close file");
    }
}

void fill_random(char g_table[20][20], char randwords[NUM_WORDS][MAX_WORD])   //I put this function to randomly place the direction and location of the words.
{
                                                                        /*0=south, 1=south-west, 2=west, 3=north-west, 4=north, 5=north-east, 6=east, 7=south-east*/
    int direction = 0, x_pos, y_pos, l, flag = 0;
    for (int i = 0; i < 10; i++)
    {
        flag = 0;
        l = strlen(randwords[i]) - 2;

        while (flag == 0)
        {
            direction = rand() % 8;   //I got 8 percent of the direction because there are 8 directions here.
            x_pos = rand() % 20;      //Since it is 20 * 20 in the table, I bought 20 percent of the positions here.
            y_pos = rand() % 20;
            if (is_empty(x_pos, y_pos, direction, g_table, l))  //here I define the empty fields and place the character '-' in the empty spaces, then I will assign random letters to these places.
            {
                flag = 1;
            }
        }
	                                                           
        if (direction == 0)  //here I determined how the coordinate points will change in 8 directions.
        {
            for (int j = 0; j < l; j++)
            {
                g_table[y_pos][x_pos] = randwords[i][j];  //south
                y_pos -= 1;
                x_pos += 0;  //I reduced and increased x and y to determine positions.
            }
        }
        else if (direction == 1)
        {
            for (int j = 0; j < l; j++)
            {
                g_table[y_pos][x_pos] = randwords[i][j];  //south-west
                y_pos -= 1;
                x_pos -= 1;
            }
        }
        else if (direction == 2)
        {
            for (int j = 0; j < l; j++)
            {
                g_table[y_pos][x_pos] = randwords[i][j]; //west
                y_pos += 0;
                x_pos -= 1;
            }
        }
        else if (direction == 3)
        {
            for (int j = 0; j < l; j++)
            {
                g_table[y_pos][x_pos] = randwords[i][j]; //north-west
                y_pos += 1;
                x_pos -= 1;
            }
        }
        else if (direction == 4)
        {
            for (int j = 0; j < l; j++)
            {
                g_table[y_pos][x_pos] = randwords[i][j];  //north
                y_pos += 1;
                x_pos += 0;
            }
        }
        else if (direction == 5)
        {
            for (int j = 0; j < l; j++)
            {
                g_table[y_pos][x_pos] = randwords[i][j];  //north-east
                y_pos += 1;
                x_pos += 1;
            }
        }
        else if (direction == 6)
        {
            for (int j = 0; j < l; j++)
            {
                g_table[y_pos][x_pos] = randwords[i][j];  //east
                y_pos += 0;
                x_pos += 1;
            }
        }
        else if (direction == 7)
        {
            for (int j = 0; j < l; j++)
            {
                g_table[y_pos][x_pos] = randwords[i][j];  //south-east
                y_pos -= 1;
                x_pos += 1;
            }
        }
    }
}

int is_empty(int x, int y, int direct, char g_table[20][20], int len)  //here I have assigned the character '-' in the table, except for the words, and then I will fill these places with random letters.
{
    int flag = 1;
    char c;

    if (direct == 0)
    {
        for (int j = 0; j < len && flag == 1; j++)
        {
            if (x > 19 || y > 19 || x < 0 || y < 0)  //I write this equation so that there is no overflow here.
            {
                flag = 0;
            }
            if (g_table[y][x] != '-')
            {
                flag = 0;  //If it does not correspond to the '-' character, the flag becomes 0.
            }
            y -= 1;  //here I increase and decrease x and y coordinates according to directions.
            x += 0;
        }
    }

    else if (direct == 1)
    {
        for (int j = 0; j < len && flag == 1; j++)
        {
            if (x > 19 || y > 19 || x < 0 || y < 0)  //I write this equation so that there is no overflow here.
            {
                flag = 0;
            }
            if (g_table[y][x] != '-')
            {
                flag = 0;  //If it does not correspond to the '-' character, the flag becomes 0.
            }
            y -= 1;
            x -= 1;   //here I increase and decrease x and y coordinates according to directions
        }
    }

    else if (direct == 2)
    {
        for (int j = 0; j < len && flag == 1; j++)
        {
            if (x > 19 || y > 19 || x < 0 || y < 0)   //I write this equation so that there is no overflow here.
            {
                flag = 0;
            }
            if (g_table[y][x] != '-')
            {
                flag = 0;   //If it does not correspond to the '-' character, the flag becomes 0.
            }
            y += 0;
            x -= 1;   //here I increase and decrease x and y coordinates according to directions
        }
    }

    else if (direct == 3)
    {
        for (int j = 0; j < len && flag == 1; j++)
        {
            if (x > 19 || y > 19 || x < 0 || y < 0)  //I write this equation so that there is no overflow here.
            {
                flag = 0;
            }
            if (g_table[y][x] != '-')
            {
                flag = 0;   //If it does not correspond to the '-' character, the flag becomes 0.
            }
            y += 1;
            x -= 1;     //here I increase and decrease x and y coordinates according to directions
        }
    }

    else if (direct == 4)
    {
        for (int j = 0; j < len && flag == 1; j++)
        {
            if (x > 19 || y > 19 || x < 0 || y < 0)   //I write this equation so that there is no overflow here.
            {
                flag = 0;
            }
            if (g_table[y][x] != '-')
            {
                flag = 0;   //If it does not correspond to the '-' character, the flag becomes 0.
            }
            y += 1;
            x += 0;    //here I increase and decrease x and y coordinates according to directions
        }
    }

    else if (direct == 5)
    {
        for (int j = 0; j < len && flag == 1; j++)
        {
            if (x > 19 || y > 19 || x < 0 || y < 0)   //I write this equation so that there is no overflow here.
            {
                flag = 0;
            }
            if (g_table[y][x] != '-')
            {
                flag = 0;    //If it does not correspond to the '-' character, the flag becomes 0.
            }
            y += 1;
            x += 1;   //here I increase and decrease x and y coordinates according to directions
        }
    }

    else if (direct == 6)
    {
        for (int j = 0; j < len && flag == 1; j++)
        {
            if (x > 19 || y > 19 || x < 0 || y < 0)   //I write this equation so that there is no overflow here.
            {
                flag = 0;
            }
            if (g_table[y][x] != '-')
            {
                flag = 0;   //If it does not correspond to the '-' character, the flag becomes 0.
            }
            y += 0;
            x += 1;    //here I increase and decrease x and y coordinates according to directions
        }
    }

    else if (direct == 7)
    {
        for (int j = 0; j < len && flag == 1; j++)
        {
            if (x > 19 || y > 19 || x < 0 || y < 0)   //I write this equation so that there is no overflow here
            {
                flag = 0;
            }
            if (g_table[y][x] != '-')
            {
                flag = 0;   //If it does not correspond to the '-' character, the flag becomes 0
            }
            y -= 1;
            x += 1;   //here I increase and decrease x and y coordinates according to directions
        }
    }

    return flag;
}

char random_letter(char arr[20][20])
{

    int x, y;
    char c;

    srand(time(NULL));

    for (y = 0; y < 20; y++)
    {

        for (x = 0; x < 20; x++)
        {

            c = (char)(rand() % 26) + 'a'; // Generate a random character between 'a' and 'z'

            if (arr[y][x] == '-')  //I am replacing the '-' character with random letters.
            {
                arr[y][x] = c;
            }
        }
    }
}

int user_find(int user_row, int user_column, char user_word[15], int word_size, char g_table[20][20])
{

    int count = 0;

    // left to right
    for (int j = user_column, k = 0; j < user_column + word_size; j++, k++) //In this function, if the coordinate and word entered by the user is correct, the words grow in the table.
    {
        if (user_word[k] == g_table[user_row][j])  //I increase the counter as I assign the letters.
            count++;
        else
            break;
    }

    if (count == word_size)
    {
        for (int j = user_column, k = 0; j < user_column + word_size; j++, k++)
        {
            g_table[user_row][j] -= 32;  //I removed 32 to convert it to uppercase. (According to ASCII table)
        }
        return 1;
    }

    // right to left
    count = 0;   //I reset the counter every time.
    for (int j = user_column, k = 0; j > user_column - word_size; j--, k++)  //the column is decreasing here
    {
        if (user_word[k] == g_table[user_row][j])  //I increase the counter as I assign the letters.
            count++;
        else
            break;
    }

    if (count == word_size)
    {
        for (int j = user_column, k = 0; j > user_column - word_size; j--, k++) //the column is decreasing here
        {
            g_table[user_row][j] -= 32;  //I removed 32 to convert it to uppercase. (According to ASCII table)
        }
	
        return 1;
	
    }

    //top to down
    count = 0;
    for (int i = user_row, k = 0; i < user_row + word_size; i++, k++)  //row is increasing
    {
        if (user_word[k] == g_table[i][user_column])    //I increase the counter as I assign the letters.
            count++;
        else
            break;
    }

    if (count == word_size)
    {
        for (int i = user_row, k = 0; i < user_row + word_size; i++, k++)  //row is increasing
        {
            g_table[i][user_column] -= 32;   //I removed 32 to convert it to uppercase. (According to ASCII table)
        }
        return 1;
    }

    // down to top
    count = 0;
    for (int i = user_row, k = 0; i > user_row - word_size; i--, k++)
    {
        if (user_word[k] == g_table[i][user_column])
            count++;
        else
            break;
    }

    if (count == word_size)
    {
        for (int i = user_row, k = 0; i > user_row - word_size; i--, k++)
        {
            g_table[i][user_column] -= 32;
        }
        return 1;
    }

    // left top
    count = 0;
    for (int i = user_row, j = user_column, k = 0; i > user_row - word_size,j > user_column - word_size; i--, j--, k++)  //Since it is an intermediate direction, I change both i and j.
    {
        if (user_word[k] == g_table[i][j])
            count++;
        else
            break;
    }

    if (count == word_size)
    {
        for (int i = user_row, j = user_column, k = 0; i > user_row - word_size; i--, j--, k++)
        {
            g_table[i][j] -= 32;
        }
        return 1;
    }

    // right top
    count = 0;
    for (int i = user_row, j = user_column, k = 0; i > user_row - word_size,j < user_column + word_size; i--, j++, k++)
    {
        if (user_word[k] == g_table[i][j])
            count++;
        else
            break;
    }

    if (count == word_size)
    {
        for (int i = user_row, j = user_column, k = 0; i > user_row - word_size; i--, j++, k++)
        {
            g_table[i][j] -= 32;
        }
        return 1;
    }


    // left down
    count = 0;
    for (int i = user_row, j = user_column, k = 0;i < user_row + word_size, j > user_column - word_size; i++, j--, k++)
    {
        if (user_word[k] == g_table[i][j])
            count++;
        else
            break;
    }

    if (count == word_size)
    {
        for (int i = user_row, j = user_column, k = 0; i <user_row + word_size; i++, j--, k++)
        {
            g_table[i][j] -= 32;
        }
        return 1;
    }

    // right down
    count = 0;
    for (int i = user_row, j = user_column, k = 0; i < user_row + word_size, j< user_column + word_size; i++, j++, k++)
    {
        if (user_word[k] == g_table[i][j])
            count++;
        else
            break;
    }

    if (count == word_size)
    {
        for (int i = user_row, j = user_column, k = 0; i < user_row + word_size; i++, j++, k++)
        {
            g_table[i][j] -= 32;
        }
        return 1;
    }

}
    