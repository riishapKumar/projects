#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv);
int is_verb(char *verb);
char * conjugate(char *verb);

/**
 * The main method. The program entry point.
 */
int main(int argc, char **argv) {
        /* the verb that the user types in  (will be malloced) */
        char *verb;
        /* the response from the conjugate method */
        char *resp = NULL;
        /* character for yes no prompt */
        char c;

    verb = (char *) malloc(30);

        while(1) { // infinite loop
                printf("Enter a French verb (-er):\n");
                memset(verb, 0, 30);
            scanf("%s", verb);
            if(is_verb(verb)) {  // determine that it's a verb
                resp = conjugate(verb); // conjugate
                printf("%s", resp);
            }
            else {
                printf("Not a correct -er verb\n");
            }
            printf("Conjugate another verb? [Yy]\n");
            scanf(" %c", &c); // the space in front of %c skips extra white space
            if(c == 'y' || c == 'Y') {
                continue;
            }
            break;
        }

        /* free the memory */
        free(verb);
        if(resp != NULL) {
                free(resp);
        }
        return 0;
}

/**
 * Conjugates the verbs and returns the result
 *
 */
char * conjugate(char *verb) {
        char *versions[6];
        char *buf;
        char tmp[30], cpy[30]; // Assume max of 30
        int offset = 0;
        int n = strlen(verb);

        buf = (char *) malloc(30 * 6); // they hve said to assume maximum length of 30 each.

        strncpy(cpy, verb, n - 2);
    cpy[n -1] = 0;

        versions[0] = "je %se\n";
        versions[1] = "tu %ses\n";
        versions[2] = "elle/il %se\n";
        versions[3] = "nous %sons\n";
        versions[4] = "vous %sez\n";
	versions[5] = "elles/ils %sent\n";

        for (int i = 0; i < 6; i++) {
                /* print the conjugation to tmp */
        sprintf(tmp, versions[i], cpy);

        /* find the length of tmp */
        n = strlen(tmp);
        /* copy tmp to buf, start from the last known position on it */
        strncpy(buf + offset, tmp, n);
        offset += n;
        }

        buf[++offset] = 0; // add a string terminator
        return buf;
}

/**
 * Is the given verb really a verb?
 */
int is_verb(char *verb) {
        int n = strlen(verb);
        if( (verb[n-1] == 'r' || verb[n-1] == 'R') &&
                (verb[n-2] == 'e' || verb[n-2] == 'E')) {
                return 1;
        }

        return 0;
}

