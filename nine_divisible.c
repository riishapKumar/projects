/*
 * File: quadrant.c
 * Desc: this program prints out where a point lies in a Cartesian system according to its x and y coordinates
 * Author: Rishap kumar and mitchell sibal
 */
#include <stdio.h>

int main()
{
    int n;
    int digitSum = 0;
    int digit;
   
    scanf("%d", &n);
    int m = n;
   
    while (n)
    {
        digit = n % 10;
        printf("%d\n", digit);
        digitSum += digit;
        n /= 10;
    }
   
    if (digitSum % 9)
        printf("\n%d is NOT divisible by 9\n", m);
    else
        printf("\n%d is divisible by 9\n", m);
   
    return 0;
} 
