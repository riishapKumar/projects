// number.c
//
// read in a positive integer
// and display number properties

#include <stdlib.h>
#include <stdio.h>
// #include <math.h>

// divisible
// returns 1 if x is evenly divisible by y
// returns 0 otherwise

int divisible(int x, int y) {
	return (x % y) == 0;	// divisible == remainder after division is zero
}


// sum_of_digits_is_even
// returns 1 if sum of decimal digits of x is even
// returns 0 otherwise

int sum_of_digits_is_even(int x) {
	int sum;
	
	sum = x % 10;			// least significant decimal digit
	while (x) {
		x /= 10;			// shift decimal number to right
		sum += x % 10;		// add least significant decimal digit
	}
	return (sum % 2) == 0;
}


// is_prime
// returns 1 if x is prime
// returns 0 otherwise

int prime(int x) {
	// int sqrt_x;
	int factor, max_factor;
	
	// quickly handle small prime numbers
	// 1, 2, 3 are all prime numbers
	if (x <= 3) {
		return 1;
	} else if (divisible(x,2)) {
		// even numbers larger than 2 are not prime
		return 0;
	}
	
	// largest possible factor is sqrt(x)
	// sqrt_x = (int) floor(sqrt((double) x));
	
	// we are not allowed to use sqrt from math library
	// ... so use a simpler choice for max factor
	max_factor = x / 2;
	
	// try all odd numbers from 3 to sqrt_x
	for (factor = 3 ; factor <= max_factor ; factor += 2) {
		if (divisible(x,factor)) {
			return 0;
		}
	}
	// must be prime because not divisible by any factors
	return 1;
}


// get_number

int get_number() {
	int number;
	int count;
	
	count = scanf("%d", &number);
	if (count != 1 || number < 1) {
		printf("Invalid input\n");
		exit(1);
	}
	return number;
}


int main(int argc, char *argv[]) {
	int number;
	int is_multiple;
	int is_even;
	int is_prime;
	
	number = get_number();
	printf("Properties of number %d:\n", number);
	
	is_multiple = divisible(number,7) || divisible(number,11) || divisible(number,13);
	printf("- %s of 7, 11 or 13\n", is_multiple ? "Multiple" : "Not a multiple");
	
	is_even = sum_of_digits_is_even(number);
	printf("- Sum of digits is %s\n", is_even ? "even" : "odd");
	
	is_prime = prime(number);
	printf("- %s number\n", is_prime ? "Prime" : "Not a prime");
	
	return 0;
}


	

