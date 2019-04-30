/*
 * File: jet_acceleration.c
 * Desc: this program gives the time for the fighter to be accelerated to takeoff speed
 * Author: Rishap kumar
 */
#include <stdio.h>

int main(void)
 {
	int speed, distance;

	double t,a,v; //for time, acceleration and velocity

	//gets the input from user

	scanf("%d %d",&speed, &distance);

	//converting speed from km/hr to m/s

	v = speed * (5.0/18.0);

	//calculating time in seconds

	t = (2 * distance) / v;

	//calculating acceleration in m/s/s

	a = v / t;

	//displays the calculated values

	printf("Takeoff speed is %d km/h and distance to takeoff is %d m\n", speed, distance);

	printf("The jet would need to accelerate at %0.2lf m/s^2 for %0.2lf seconds\n", a , t);

	return 0 ; 

}



