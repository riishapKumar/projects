/*
 * File: char_binrep.c
 * Desc: this program prints the 7 properties of any inputted character
 * Author: Rishap kumar and mitchell sibal
 */
#include <stdio.h>
#include <ctype.h>

int main()
{
	char character;

	scanf("%c", &character);

	if (isalnum(character)){
		printf("1");
	} else {
		printf("0");
	}
	if (isupper(character)){
                printf("1");
        } else {
                printf("0");
        }
	if (islower(character)){
                printf("1");
        } else {
                printf("0");
        }
	if (character == 'a' ||character ==  'e' ||character ==  'i' ||character ==  'o' ||character ==  'u' ||character ==  'A' ||character ==  'E' ||character ==  'I' ||character ==  'O' ||character ==  'U'){
                printf("1");
        } else {
                printf("0");
        }
	if (isdigit(character)){
                printf("1");
        } else {
                printf("0");
        }
	if (isxdigit(character)){
                printf("1");
        } else {
                printf("0");
        }
	if (ispunct(character)){
                printf("1");
        } else {
                printf("0");
        }
	
	return 0;
}
