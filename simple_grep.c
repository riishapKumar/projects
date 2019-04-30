/*
 rihsap kumar
 reads entire lines from the user, and only prints back those which match any of the patterns received as program arguments, as illustrated in the following example.
 simple_grep.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define	MAXPATTERN 64

void usage() {
	printf("usage: simple_grep [-n] pattern [ pattern ...]\n");
	exit(1);
}

int match(char *line, char *s) {
	char *p;
	int n;
	
	n = strlen(s);
	for (p = line ; *p ; ++p) {
		if (strncasecmp(p,s,n) == 0) {
			return 1;
		}
	}
	return 0;
}

int match_set(char *line, char *set[], int n) {
	int i;
	
	for (i = 0 ; i < n ; ++i) {
		if (match(line, set[i])) {
			return 1;
		}
	}
	return 0;
}


int main(int argc, char *argv[]) {
	char linebuf[BUFSIZ];
	int linenum = 0;
	char *pattern[MAXPATTERN];
	int count = 0;
	int prefix = 0;
	int i;
	
// check for -n option
	if (argc >= 2 && strcmp(argv[1],"-n") == 0) {
		prefix = 1;
		i = 2;
	} else {
		i = 1;
	}
// check there is at least 1 pattern
	if (i >= argc) {
		usage();
	}
// patterns
	while (i < argc) {
		pattern[count++] = argv[i++];
	}

// read input line by line	
	while (! feof(stdin)) {
		if (! fgets(linebuf, BUFSIZ, stdin)) {
			break;
		}
		++linenum;
		if (match_set(linebuf, pattern, count)) {
			if (prefix) {
				printf("%d:", linenum);
			}
			printf("%s", linebuf);
		}
	}
	return 0;
}


