/*
 * File: hydroelectric_dam.c
 * Desc: this program makes Predicting how many megawatts (1MW = 10^6W) of power will be produced depends on the height of the dam and the number of cubic meters of water that are projected to flow from the top to the bottom of the dam each second
 * Author: Rishap kumar and Mitchell Sibal
 */
#include <stdio.h>

int main(void)
{
	/* Input phase */

	int height, flow, mega_watt;
	float mass_of_water, work_done, power;

	scanf("%d %d", &height, &flow);

	/* Computation phase */

	#define CUBIC_MASS_H20 (1000)
	#define GRAVITY (9.80)
	mass_of_water = flow * CUBIC_MASS_H20;         /*calculates the mass of water in cubic with the flow(m^3/s) */
	work_done = mass_of_water * GRAVITY * height;
	power = 0.9 * work_done;
	mega_watt = power / 1000000;                   /* since 1Megawatt = 10^6W */

	/* Output phase */

	printf("The dam is %d meters high and the water flow is %d m^3/sec\n", height, flow);
	printf("The dam will produce %d megawatts\n", mega_watt);
	
	/* Exit with no error */
	return 0;
}
