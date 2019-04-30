/*
 * File: cobalt_decay.c
 * Desc: this program  reads an initial mass of cobalt and a number of years, and prints the amount of this isotope that remains after each year until the end of the specified period of time.
 * Author: Rishap kumar
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// half life of Cobalt-60
#define		HALF_LIFE	5.272

int main(int argc, char *argv[]) {
	int mass;		// initial mass in grams
	int years;		// number of years
	double m;		// initial mass in grams
	double r;		// calculated mass in grams
	double C;		// constant
	int y;
	int n;
	
	n = scanf("%d%d", &mass, &years);
	if (n != 2 || mass <= 0 || years <= 0) {
		printf("Invalid values\n");
		return 1;
	}
	
	// convert from "int" to "double"
	m = (double) mass;
	
	// calculate C
	C = exp(-0.693);
	
	// note: C = 1/2, since exp(ln(1/2)) = 1/2, and -0.693 = ln(1/2)
	
	for (y = 1 ; y <= years ; ++y) {
		r = m * pow(C, y / HALF_LIFE);
		printf("After %d years, the remaining amount is %.2f grams\n", y, r);
	}
	return 0;
}

