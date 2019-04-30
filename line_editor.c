#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 100005  // assuming the max length of any string wont exceed 10^5
void trim(char *s)   // A function to remove the trailing newline charcter from the string
{
	int len = strlen(s);
	while(len > 0 && s[len-1] == '\n' )
		len--;
	s[len] = '\0';
}

void insertfunc(char *str, char *inp, char *aux)
{
	printf("Enter string to insert:\n");
	fgets(inp, MAXN, stdin);
	trim(inp);
	int pos;
	printf("Enter position to insert:\n");
	scanf("%d",&pos);
	strncpy(aux, str, pos);
	aux[pos] = '\0';
	strcat(aux, inp);
	strcat(aux, str+pos);
	strcpy(str, aux);
	getchar();
}

void deleteFunc(char *str, char *inp, char *aux)
{
	printf("Enter string to delete:\n");
	fgets(inp, MAXN, stdin);
	trim(inp);
	if(!strstr(str,inp)){
		printf("Error, '%s' not found\n", inp);
		return;
	}
	else{
		while((str=strstr(str,inp)))
    		memmove(str,str+strlen(inp),1+strlen(str+strlen(inp)));
	}
}
int main()
{
	char str[MAXN], inp[MAXN], aux[MAXN];
	printf("Enter the source string:\n");
	fgets(str, MAXN, stdin);
	trim(str);
	while(1)
	{
		printf("Source string is: '%s'\n",str);
		printf("Enter [Dd] (delete), [Ii] (insert) or [Qq] (quit):\n");
		char type;
		fgets(inp, MAXN, stdin);
		trim(inp);
		if(strlen(inp) != 1){
			puts("Invalid command");
			continue;
		}
		type = inp[0];
		if(type == 'd')
			deleteFunc(str, inp, aux);
		else if(type == 'i')
			insertfunc(str, inp,aux);
		else if(type == 'q')
			goto p;
		else {
			puts("Invalid command");
		}
	}	
	p:;
	printf("Final string: '%s\n'", str);
	return 0;

}
