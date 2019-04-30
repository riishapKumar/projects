/*
 * File: loan_cost.c
 * Desc: this program computes the cost of a loan given a certain amount, a duration in years and an interest rate in percent.
 * Author: Rishap kumar and Jhonathan barrgan
 */

#include <stdio.h>
#include <math.h>

int main(void)
{

	float loan_amount, duration_loan, yearly_interst, cal_top, cal_bottom, lower_val;
	float total;

	/* Input phase */

	printf("Enter the loan amount (in $): ");
	scanf("%f", &loan_amount);

	printf("Enter duration of the loan (in yrs): ");
	scanf("%f", &duration_loan);

	printf("Enter the yearly interest (in %%): ");
	scanf("%f", &yearly_interst);

	/* Computation phase */

	yearly_interst = (yearly_interst / 12) / 100;      /* converts yearly interst to monthly interst */

	duration_loan = 12 * duration_loan;                /* converts years to months */

	/* calculates the top and bottom of the interst formula total cost =( ((rate * principal)/(1-(1+ rate)^-num_years) * num_year) */ 
	cal_top = loan_amount * yearly_interst * duration_loan;
	lower_val = 1 + yearly_interst; 
	cal_bottom = 1 - powf(lower_val, -duration_loan);
	total = cal_top / cal_bottom;

	/* Output phase */	

	printf("Total cost of loan: $%.2f\n", total);
	
	/* Exit with no error */
	return 0;
}
