/*
 * File: world_population.c
 * Desc: 
 * Author: Rishap kumar and Mitchell Sibal
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int perdcit_year, time_years;
	double rate_growth, perdiction_of_population, power;

	scanf("%d %lf", &perdcit_year, &rate_growth);

	#define WORLD_POPULATION (7632819325)
	time_years = perdcit_year - 2018;
	power = rate_growth * time_years;
	perdiction_of_population = WORLD_POPULATION * (pow(M_E,power));

	printf("Prediction year is %d", perdcit_year);
	printf("Predicted growth rate is %lf", rate_growth);
	printf("%d years after 2018, the world population is expected to be %lf\n", time_years, perdiction_of_population);

	return 0;
}
