/*
 *File: btu_house.c
 * Dsec: this program number of BTUs of heat delivered to a house depends on the number of gallons of oil burned and on the efficiency of the furnace.
 * Author: Rishap kumar and Mitchell Sibal
 */
#include <stdio.h>
int main(void)
{
	/* Input phase */

	int oil_burned, efficiency;
	long int  efficiency_furnace;
	double one_gal_oil, oil_used;

	scanf("%d %d%%", &oil_burned, &efficiency);

	/* Computation phase */

	#define BARREL_CAPACITY (42.0)
	#define BARREL_ENERGY (5800000.0)
	/* calulate for one barrel and then mulityply by input of barrel and efficiency of fuel */
	one_gal_oil = BARREL_ENERGY / BARREL_CAPACITY;
	oil_used = oil_burned * one_gal_oil;
	efficiency_furnace = oil_used * (efficiency / 100.0);

	/* Output phase */

	printf("Number of gallons of oil burned is %d\n", oil_burned);
	printf("Efficiency of furnace is %d%%\n", efficiency);
	printf("Amount of BTUs of heat delivered to house is %ld\n", efficiency_furnace);
	
	/* Exit with no error */

	return 0;
}
