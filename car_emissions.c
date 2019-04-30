/*
 * File: car_emissions.c
 * Desc: this program reads the type of emissions, the number of grams per mile emitted by the vehicle and the current value of the odometer, and determines if the emissions exceed the permitted level
 * Author: Rishap kumar
 */


#include <stdio.h>
int main()
{
	int pollutant,odometer;
	double grams , max1 , max2 , max3 , max4 , max , ok;

	scanf("%d %lf %d",&pollutant, &grams, &odometer);
	
	if (pollutant < 1 || pollutant > 4) {
	printf("Unknown pollutant\n");
	return 1;


}
	if(odometer>50000)      /*et pollutantvalues if odometer > 50000*/ {
		max1=4.2;
		max2=.39;
		max3=.5;
		max4=.31;
}
	else                  /*set pollutant values if odometer > 50000*/ {
		max1=3.4;
		max2=.31;
		max3=.4;
		max4=.25;
}
	ok=1;              //1 means emissions not exceeded
                          //0 means emissions exceeded
	switch(pollutant)
{                 //decide if exceeded & set grams limit
	case 1:if(grams>max1)
          ok=0;
          max=max1;
          break;
	case 2:if(grams>max2)
          ok=0;
          max=max2;
          break;
	case 3:if(grams>max3)
          ok=0;
          max=max3;
          break;
	case 4:if(grams>max4)
          ok=0;
          max=max4;
          break;
}
	if(ok==1)        //notexceeded?
		printf("Emissions do not exceed permitted level of %.2lf grams/mile\n",max);
	else
		printf("Emissions exceed permitted level of %.2lf grams/mile\n",max);
	return 0;
}

