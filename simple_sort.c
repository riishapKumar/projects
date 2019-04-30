#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **get_lines(int nlines);
int get_nlines(void);
int mystrcmp(const void *a, const void *b);
void print_lines(char **lines, int nlines);
void free_lines(char **lines, int nlines);
void sort_lines(char **lines, int nlines);

int main(int argc, char **argv) {
	int n = get_nlines();
	char **lines;
	if (n >= 0) {
		lines = get_lines(n);
		if(lines != NULL) {
			//printf("Before soring\n------\n");
			//print_lines(lines,n);
			//printf("After soring\n------\n");
			sort_lines(lines, n);
			print_lines(lines, n);
			free_lines(lines, n);
			return 0;
		}
		else {
			return 1;
		}
	} else {
		printf("Invalid input\n");
		return 1;
	}
}

/**
 * This function return the number of lines to be read subsequently.
 */
int get_nlines(void) {
	int *n = malloc(sizeof(int));
	if (scanf("%d", n)) {
		getchar();
		return *n;
	}
	return -1;
}

/**
 * Dynamically allocts nlines of strings. And reads data.
 *
 * If the memory cannot be allocated returns null.
 */
char **get_lines(int nlines) {
	int i;
	char **lines = malloc(nlines *  sizeof(char *));
	if (lines != NULL) {
		for (i = 0; i < nlines; i++) {
			lines[i] = malloc(80);
			if (lines[i] == 0) {
				printf("malloc failed\n");
				return NULL;
			}
			if (fgets(lines[i], 80, stdin) == NULL) {
				printf("Input error\n");
				return NULL;
			}
		}
	}
	else {
		printf("malloc failed\n");
	}
	return lines;
}

void print_lines(char **lines, int nlines) {
	for (int i = 0; i < nlines; i++) {
		printf("%s", lines[i]);
	}
}

void free_lines(char **lines, int nlines) {
	for (int i = 0; i < nlines; i++) {
		free(lines[i]);
	}
	free(lines);

}

void sort_lines(char **lines, int nlines) {
	qsort(lines, nlines, sizeof(char *), mystrcmp);
}

/*
 * Qsort comparison helper
 */
int mystrcmp(const void *a, const void *b) {
	const char **stra = (const char **) a;
	const char **strb = (const char **) b;
	return strcasecmp(*stra, *strb);
}
