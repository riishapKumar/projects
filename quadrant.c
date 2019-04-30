 /*
 * File: quadrant.c
 * Desc: this program prints out where a point lies in a Cartesian system according to its x and y coordinates
 * Author: Rishap kumar and mitchell sibal
 */
#include <stdio.h>

int main(void)
{
/* Input phase */
	float x, y;

	scanf("%f %f", &x, &y);
/* Computation phase */
	if (x > 0 && y > 0)
		printf("(+%.1f, +%.1f) is in quadrant 1\n", x, y);
	else if (x < 0 && y > 0)
        	printf("(%.1f, +%.1f) is in quadrant 2\n", x, y);
	else if (x < 0 && y < 0)
        	printf("(%.1f, %.1f) is in quadrant 3\n", x, y);
	else if (x > 0 && y < 0)
        	printf("(+%.1f, %.1f) is in quadrant 4\n", x, y);
	else if (x > 0 && y == 0)
		printf("(+%.1f, +%.1f) is on the x-axis\n", x, y);
	else if (x < 0 && y == 0)
                printf("(%.1f, +%.1f) is on the x-axis\n", x, y);
	else if (x == 0 && y > 0)
		printf("(+%.1f, +%.1f) is on the y-axis\n", x, y);
	else if (x == 0 && y < 0)
                printf("(+%.1f, %.1f) is on the y-axis\n", x, y);
	else if (x == 0 && y == 0)
                printf("(+%.1f, +%.1f) is the origin\n", x, y);
	
	return 0;
}
