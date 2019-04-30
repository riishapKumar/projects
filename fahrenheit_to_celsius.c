 /*
  * File: fahrenheit_to_celsius.c
  * Desc: converts fahrenheit to celsius
  * Author: Rishap kumar and Mitchel sibal
*/
#include <stdio.h>

int main(void)
{ 
	int input_fahrenheit;
	double convert_celsius;

	scanf("%d", &input_fahrenheit);

	convert_celsius = (5.0/9)*(input_fahrenheit - 32);

	printf("Temperature in Fahrenheit is: %d\n", input_fahrenheit);
	printf("Temperature in Celsius is: %.2f\n", convert_celsius);

	return 0;
}
