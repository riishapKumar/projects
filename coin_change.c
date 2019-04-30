/*
 * File: coin_change
 * Desc: this program makes calulations needed to give back coin change
 * Author: Rishap kumar
 */
#include <stdio.h>
int main(void)
{
	int amount_change;
	int denomination_quarters, denomination_dime, denomination_nickels, denomination_penny, second_change, third_change, quarter_val, dime_val, nickel_val;
	/* Input phase */
	printf("What is the amount of cents?\n");
	scanf("%d", &amount_change);
	/* Computation phase */
	
	/* takes amaount of money to withdarw and then divies by bill dnominations */
	denomination_quarters = amount_change / 25;
	quarter_val = denomination_quarters * 25;
	second_change = amount_change - quarter_val;
	denomination_dime = second_change / 10;
	dime_val = denomination_dime * 10;
	third_change = second_change - dime_val;
	denomination_nickels = third_change / 5;
	nickel_val = denomination_nickels * 5;
	denomination_penny = third_change - nickel_val;
	/* Output phase */
	printf("Number of quarters: %d\n", denomination_quarters);
	printf("Number of dimes: %d\n", denomination_dime);
	printf("Number of nickels: %d\n", denomination_nickels);
	printf("Number of pennies: %d\n", denomination_penny);
	
	/* Exit with no error */
	return 0;
}

