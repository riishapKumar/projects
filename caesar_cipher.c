#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void cipher(int key, char *c);

int main(int argc, char **argv) {
	int shift;
	char c;

	if(! scanf("%d", &shift)) {
		printf("Incorrect input. Please type the key on the first line\n");
		return -1;
	}
	if(shift < 0 || shift > 26) {
		printf("Invalid key\n");
		return 1;
	}

	getchar();


	while( (c = getchar()) != EOF) {
		cipher(shift, &c);
	//	printf("%c", c);
	}
	//printf("\n");
	return 0;
}

/*
 * This really shouldn't be a pointer to a char since we are processing the
 * input one character at a time but anyway it can be made to work.
 *
 */
void cipher(int key, char *c) {
	char output = *c;
	if(isalpha(output)) {
		if(isupper(output)) {
			/* in c character are really just ints in disguise. so we can do
			 * character arithmatic like this:
			 */
			output = output - 'A';
			output += key;
			output %= 26;
			output += 'A';
		}
		else {
			output = output - 'a';
			output += key;
			output %= 26;
			output += 'a';
		}
	}

	printf("%c", output);
}
