/*
 * File: can_cost.c
 * Desc: this program calculates cost of the surface area of the can is the sum of the circular bases plus the surrounding cylinder.
 * Author: Rishap kumar
 */

#include <stdio.h>
#include <math.h>
int main()
{
	double radius,height,cost,single,all;
	int count;
//input for user
	scanf("%lf %lf %lf %d",&radius, &height, &cost, &count);
//computation using 2PI r^2 and height of cyclinder
	single = ((2*(radius*radius*M_PI))+(2*M_PI*radius*height));
	all = (single*count)* cost;
// output 
	printf("Radius of bases is %0.2lf, height of cylinder is %0.2lf\n", radius, height);
	printf("Cost per square centimeter is %0.4lf and quantity is %d\n", cost, count);
	printf("Each can has a surface of %0.3lf cm2 and the run will cost $%.02lf\n", single, all);

	return 0;
}
