#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>

#include<time.h>

#include<string.h>

//you can change this number if you want number of digits to different capacity

#define SIZE 4

char return_char(int s,int arr[],int pos);

void get_guess_in_array(int arr[], int size,int num);

int main()

{

int guess[SIZE]; //array to hold guess

int secret_number[SIZE]; //array to hold secret number

int i,j=SIZE,num;

char ret[SIZE+1];

//initialize random number generation

srand(time(NULL));

//construct secret number

for (i = 0; i < SIZE; i++)

{

secret_number[i] = rand() % 10;

//to generate unique numbers

j = 2;

while (j)

--j;

}

//give 10 attempt to guess

for (i = 0; i < 10; i++)

{

printf("\nGuess the number: ");

scanf("%d", &num);

get_guess_in_array(guess, SIZE, num);

for (j = 0; j < SIZE; j++)

{

ret[j] = return_char(guess[j], secret_number, j);

}

ret[j] = '\0';

printf("%s\n", ret);

if (strcmp(ret, "xxxx") == 0)

{

printf("You guessed correctly in %d tries!", i + 1);

break;

}

}

}

char return_char(int g, int s[], int pos)

{

int i;

if (g == s[pos])

return 'x';

for (i = 0; i < SIZE; i++)

{

if (s[i] == g)

return 'o';

}

return '-';

}

void get_guess_in_array(int arr[],int size,int num)

{

int rem;

do

{

rem = num % 10;

arr[--size] = rem;

num = num / 10;

} while (num > 0);

}
