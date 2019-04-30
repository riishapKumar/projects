/*
 * File: track_runner.c
 * Desc: this program scans in the time in minutes and seconds as well as the runner’s initials, and displays the speed in feet per second and in meters per seconds
 * Author: Rishap kumar and Mitchell Sibal
 */
#include <stdio.h>

int main(void)
{
	/* Input phase */
	int minutes;
	double seconds, feet_psec, meters_psec, total_time;
	char initials, initial_s;

	scanf("%d %lf %c%c", &minutes, &seconds, &initials, &initial_s);

	/* Computation phase */

	#define mile_distance (5280)      /* constant for miles to feet */ 
	#define meters_distance (1609.34) /* constant for miles to kilometers to meters */
	total_time = (minutes*60)+ seconds;
	feet_psec = mile_distance  / total_time;
	meters_psec = meters_distance / total_time;
	
	/* Output phase */
	printf("Time (mm:ss) for runner %c%c is %d:%0.2lf\n", initials, initial_s, minutes, seconds);
	printf("Runner %c%c ran at the speed of %0.1lf feet per second or %0.1lf meters per second\n", initials, initial_s, feet_psec, meters_psec);

	/* Exit with no error */
	return 0;
}	   	   
