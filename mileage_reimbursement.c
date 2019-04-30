/*
 * File: atm_bills.c
 * Desc: this program computes mileage reimbursement at the rate of $0.35 per mile
 * Author: Rishap kumar and Jhonathan barrgan
 */
#include <stdio.h>

int main(void)
{
	float mileage_start, mileage_end, displacement_miles;
	float total;

 	/* Input phase */
	printf("Enter beginning odometer reading: ");
	scanf("%f", &mileage_start);

	printf("Enter ending odometer reading: ");
	scanf("%f", &mileage_end);

	/* Computation phase */

	displacement_miles = mileage_end - mileage_start;
	total = displacement_miles * 0.35;

	/* Output phase */

	printf("You traveled %.1f miles. At $0.35/mile, your reimbursement is $%.2f.\n", displacement_miles, total);
	
	/* Exit with no error */	

	return 0;
}
