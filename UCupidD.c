// ucupid.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct person {
	int sid;
	char *name;
	char sex;
	char seeking;
	int age;
	int politics;
	char *major;
	char *minor;
	int height;
	int weight;
	struct person *next;
} PERSON;

// read next integer from file
// ... returns -1 if fscanf fails (probably because End-of-File)
int read_int(FILE *fin) {
	char buf[BUFSIZ];
	int n;
	
	n = fscanf(fin, "%[^,\n]", buf);
	if (n != 1) {
		return -1;
	}
	fgetc(fin);
	return atoi(buf);
}

// read next char
char read_char(FILE *fin) {
	char buf[BUFSIZ];
	
	fscanf(fin, "%[^,\n]", buf);
	fgetc(fin);
	return buf[0];
}

// read next string
char *read_string(FILE *fin) {
	char buf[BUFSIZ];
	
	fscanf(fin, "%[^,\n]", buf);
	fgetc(fin);
	return strdup(buf);
}

// insert person into linked list
// note: list in sorted by SID
PERSON *list_insert(PERSON *list, PERSON *p) {
	if (! list || p->sid < list->sid) {
		p->next = list;
		list = p;
	} else {
		list->next = list_insert(list->next, p);
	}
	return list;
}

// find person in list with specified SID
PERSON *list_find(PERSON *list, int sid) {
	PERSON *p;
	
	for (p = list ; p ; p = p->next) {
		if (p->sid == sid) {
			return p;
		}
	}
	return NULL;
}

void list_destroy(PERSON *list) {
	PERSON *p, *next;
	
	for (p = list ; p ; p = next) {
		next = p->next;
	// free memory allocated for strings
		free(p->name);
		free(p->major);
		free(p->minor);
	// free memory allocated for PERSON
		free(p);
	}
}

// absolute value
int abs(int x) {
	return (x < 0) ? -x : x;
}

// return true if x and y within 10% of each other
int within_10_percent(int x, int y) {
	double dx, dy, delta;
	
	dx = (double) x;
	dy = (double) y;
	delta = abs(x - y);
	return (delta/dx) <= 0.10 && (delta/dy) <= 0.10;
}

// try to match person p and person q
// ... return 1 if there is a match between p and q
// ... return 0 if there is no match
int match(PERSON *p, PERSON *q) {
	int delta_age, delta_politics;
	
// sexual orientation
	if (p->sex != q->seeking
	||  q->sex != p->seeking) {
		return 0;
	}
	
// social identity
	delta_age = abs(p->age - q->age);;
	delta_politics = abs(p->politics - q->politics);
	if (delta_age <= 10 && delta_politics <= 2) {
		return 1;
	}
	
// personality
	if ((strcmp(p->major,q->major) == 0 && strcmp(p->minor,q->minor) == 0)
	||  (strcmp(p->major,q->minor) == 0 && strcmp(p->minor,q->major) == 0)) {
		return 1;
	}
	
// appearance
	if (within_10_percent(p->height, q->height)
	&&  within_10_percent(p->weight, q->weight)) {
		return 1;
	}
	
	return 0;
}

// write all matches for person p to file
int match_to_file(PERSON *list, PERSON *q) {
	char buf[BUFSIZ];
	FILE *fout;
	PERSON *p;
	int count = 0;
	
	sprintf(buf, "match_%09d.txt", q->sid);
	fout = fopen(buf, "w");
	if (! fout) {
		perror(buf);
		exit(1);
	}
	
	fprintf(fout, "Matches for user %09d (%s):", q->sid, q->name);
	
	for (p = list ; p ; p = p->next) {
		if (p->sid == q->sid) {
			continue;
		}
		if (match(p,q)) {
			fprintf(fout, "- %09d (%s)", p->sid, p->name);
			++count;
		}
	}
	fprintf(fout, "\n");
	fclose(fout);
	return count;
}

// load the database from CSV file
// ... return linked list to all the data
PERSON *load_database(char *filename) {
	FILE *fin;
	PERSON *list = NULL;
	PERSON *p;

	fin = fopen(filename, "r");
	if (! fin) {
		perror(filename);
		return NULL;
	}
	while (! feof(fin)) {
		p = (PERSON *) malloc(sizeof(PERSON));
		p->sid = read_int(fin);
		if (p->sid < 0) {
			break;
		}
		p->name = read_string(fin);
		p->sex = read_char(fin);
		p->seeking = read_char(fin);
		p->age = read_int(fin);
		p->politics = read_int(fin);
		p->major = read_string(fin);
		p->minor = read_string(fin);
		p->height = read_int(fin);
		p->weight = read_int(fin);
		
// 		printf("sid = %09d, name = %s, sex = %c, seeking = %c, age = %d, p = %d, major = %s, minor = %s, h = %d, w = %d\n",
// 			p->sid, p->name, p->sex, p->seeking, p->age, p->politics, p->major, p->minor, p->height, p->weight);

		list = list_insert(list, p);
	}
	fclose(fin);
	
// 	printf("LIST:\n");
// 	for (p = list ; p ; p = p->next) {
// 		printf("sid = %09d, name = %s, sex = %c, seeking = %c, age = %d, p = %d, major = %s, minor = %s, h = %d, w = %d\n",
// 			p->sid, p->name, p->sex, p->seeking, p->age, p->politics, p->major, p->minor, p->height, p->weight);
// 	}

	return list;
}

// main program
int main(int argc, char *argv[]) {
	PERSON *list, *p;
	int sid;
	int count;
	
// check required command line arguments are present
	if (argc != 3) {
		printf("usage:  ucupid database SID\n");
		return 1;
	}

// create linked list from database file
	list = load_database(argv[1]);
	if (! list) {
		return 1;
	}
	
// find person of interest
	sid = atoi(argv[2]);
	p = list_find(list, sid);
	if (! p) {
		printf("User with SID %09d not found\n", sid);
		return 1;
	}
	
// find matches for person of interest
	count = match_to_file(list, p);
	printf("Matches for %09d = %d\n", sid, count);

// destroy linked list
	list_destroy(list);

	return 0;
}


