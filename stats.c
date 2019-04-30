/*
 * File: stats.c
 * Desc: reads a certain number of values from the user and displays some statistics about the sequence of numbers
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBERS 20

void get_stats(double numbers[], int count, double *max, double *min, double *avg, double *stdev) {
	double sum, sum2, x;
	int i;
	
	if (count < 1 || count > MAX_NUMBERS) {
		fprintf(stderr, "get_stats: invalid count (%d) should be between 1 and %d\n", count, MAX_NUMBERS);
		exit(1);
	}
	sum = 0.0;
	sum2 = 0.0;
	*min = numbers[0];
	*max = numbers[0];
	for (i = 0 ; i < count ; ++i) {
		x = numbers[i];
		sum += x;
		sum2 += x * x;
		if (x > *max) {
			*max = x;
		}
		if (x < *min) {
			*min = x;
		}
	}
	*avg = sum / ((double) count);
	*stdev = sqrt( (sum2 / ((double) count)) - (*avg)*(*avg) );
}


int main(int argc, char *argv[]) {
	double numbers[MAX_NUMBERS];
	double min, max, avg, std;
	int count;
	int i;
	int k;
	
// read count
	k = scanf("%d", &count);
	if (k != 1) {
		printf("Invalid input\n");
		return 1;
	}
	if (count < 1 || count > MAX_NUMBERS) {
		printf("Invalid size\n");
		return 1;
	}

// read values in to numbers array	
	for (i = 0 ; i < count ; ++i) {
		k = scanf("%lf", &numbers[i]);
		if (k != 1) {
			printf("Invalid input\n");
			return 1;
		}
	}

// get statistics	
	get_stats(numbers, count, &max, &min, &avg, &std);

// print results	
	printf("Min: %.2lf\n", min);
	printf("Max: %.2lf\n", max);
	printf("Avg: %.2lf\n", avg);
	printf("Std: %.2lf\n", std);
	
	return 0;
}


