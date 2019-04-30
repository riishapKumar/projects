/*
 * File: Perpendicular_bisector
 * Desc: Computes to find the equation of a line segment’s perpendicular bisector
 * Author: Rishap Kumar and mitchell sibal
*/
#include <stdio.h>
int main(void)
{
	int  pointa_x, pointa_y, pointb_x, pointb_y;
	float slope_of_line, midpoint_of_line_x, midpoint_of_line_y, slope_of_bisector, y_intercept;

	scanf("%d %d %d %d", &pointa_x, &pointa_y, &pointb_x, &pointb_y);

	slope_of_line = (pointb_y - pointa_y) / ((float)pointb_x - pointa_x);
	midpoint_of_line_x = (pointa_x + pointb_x) / 2.0;
	midpoint_of_line_y = (pointa_y + pointb_y) / 2.0;
	slope_of_bisector = -(1 / slope_of_line);
	y_intercept = midpoint_of_line_y - (slope_of_line * midpoint_of_line_x);
	
	printf("Line is defined as (%d, %d), (%d, %d)", pointa_x, pointa_y, pointb_x, pointb_y);
	printf("Equation of the perpendicular bisector is: y = %.2fx + %.2f", slope_of_bisector, y_intercept);

	return 0;
}  
