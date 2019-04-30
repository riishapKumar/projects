/*
 * File: loan_cost.c
 * Desc: this program mutiplyies pi to the entered number twice
 * Author: Rishap kumar and Jhonathan barrgan
 */
#include <stdio.h>

int main(void)      /* changed void to int to get a value by running main */
{
	float tmp = 3.14, b;
	int x;

	/* Input phase */

	printf("Enter number: ");
	scanf("%d", &x);

	/* Computation phase */
	b = tmp * x;
	b = b * x;

	/* Output phase */
	printf("Result is %f.\n", b);
}
