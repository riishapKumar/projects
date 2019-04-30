/*
 * File: richter_scale.c
 * Desc: this program prints the correct characterization given a earthquake’s magnitude inputted by the user
 * Author: Rishap kumar
 */



#include<stdio.h>

int main()
{
	float value;
	scanf("%f",&value);//input from user
	
/*n < 5.0	        Little or no damage
5.0 \leq n < 5.5	Some damage
5.5 \leq n < 6.5	Serious damage: walls may crack or fall
6.5 \leq n < 7.5	Disaster: houses and buildings may collapse
higher	                Catastrophe: most buildings destroyed*/
	if (value <= 0){
		printf("Invalid magnitude\n");
                return 1;
}	else if(value < 5.0){
		printf("Little or no damage\n");
}	else if(value >= 5.0 && value < 5.5){
		printf("Some damage\n");
}	else if(value >= 5.5 && value < 6.5){
		printf("Serious damage: walls may crack or fall\n");
}	else if(value >= 6.5 && value <7.5){
		printf("Disaster: houses and buildings may collapse\n");
}	else{
		printf("Catastrophe: most buildings destroyed\n");
}
	return 0;
}
