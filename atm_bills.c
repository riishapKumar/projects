/*
 * File: atm_bills.c
 * Desc: this program makes atm bill deominations
 * Author: Rishap kumar and Jhonathan barrgan
 */
#include <stdio.h>

int main(void)
{

	int amount_money;
	int  denomination_hundred, denomination_twenty, denomination_ten, denomination_one, second_moneyamount, third_moneyamount, hundred_val, twenty_val, ten_val;

	/* Input phase */
	printf("How much money would you like to withdraw? ");
	scanf("%d", &amount_money);

	/* Computation phase */
	
	/* takes amaount of money to withdarw and then divies by bill dnominations */
	denomination_hundred = amount_money / 100;
	hundred_val = denomination_hundred * 100;
	second_moneyamount = amount_money - hundred_val;
	denomination_twenty = second_moneyamount / 20;
	twenty_val = denomination_twenty * 20;
	third_moneyamount = second_moneyamount - twenty_val;
	denomination_ten = third_moneyamount / 10;
	ten_val = denomination_ten * 10;
	denomination_one = third_moneyamount - ten_val;

	/* Output phase */

	printf("Number of $100 bills: %d\n", denomination_hundred);
	printf("Number of $20 bills: %d\n", denomination_twenty);
	printf("Number of $10 bills: %d\n", denomination_ten);
	printf("Number of $1 bills: %d\n", denomination_one);
	
	/* Exit with no error */
	return 0;
}
	
	
