/*
 * File: car_mileage.c
 * Desc: this program computes MPG per gallon
 * Author: Rishap kumar
 */
#include <stdio.h>
int main(void)
{
	float mileage_start, mileage_end, displacement_miles;
	float total;
 	/* Input phase */
	printf("Starting odometer reading?\n");
	scanf("%f", &mileage_start);
	printf("Ending odometer reading?\n");
	scanf("%f", &mileage_end);
	/* Computation phase */
	displacement_miles = mileage_end - mileage_start;
	total = displacement_miles / 19.5;
	/* Output phase */
	printf("You traveled %.1f miles.\n", displacement_miles);
	printf("With a tank of 19.50 gallons, your gas mileage is %.2f MPG.\n", total);
	
	/* Exit with no error */	
	return 0;
}
