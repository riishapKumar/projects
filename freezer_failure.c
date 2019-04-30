/*
 * File: freezer_failure.c
 * Desc: this program gives an estimate of the temperature T (in Celsius) according to the elapsed time t (in hours) since the power failure
 * Author: Rishap kumar and Jhonathan barrgan
 */

#include <stdio.h>

int main(void)
{
	float hours, min, top, bottom;
	float temp;

	/* Input phase */

	printf("Enter the duration of failure (hh mm): ");
	scanf("%f %f", &hours, &min);

	/* Computation phase */

	min = min / 60;         /*convert min to hours */
	hours = min + hours;

	top = 4 * (hours * hours);        /* Calulate temp of freezer T = (4t^2/t+2)-20 */
	bottom = hours + 2;
	temp = (top / bottom)-20;
	
	/* Output phase */	
	
	printf("Temperature is now: %f\n", temp);
	
	/* Exit with no error */
	return 0;
}
