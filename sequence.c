/*
 * File:  sequence.c
 * Desc: this program that reimplements the advanced use-case of seq 
 * Author: Rishap kumar and mitchell sibal
 */
#include <stdio.h>

int main()
{
	int start, step, end;

	scanf("%d %d %d", &start, &step, &end);

	if (start > end || step < start){
		printf("Invalid values");
	}
	while (start < end){
		printf("%d ", start);
		start = start + step; 
	}
	return 0;
}		
