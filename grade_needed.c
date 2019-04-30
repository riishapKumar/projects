
/*
 * File: grade_needed.c
 * Desc: this program makes predictions the score they would need on the final exam to achieve a certain grade in a course
 * Author: Rishap kumar
 */
#include<stdio.h>

int main(void)
{
    char letter_grade;
    double current_average,    /* input for the current averagein course*/
           score;             /* output for the score of 94.20*/
    int percentage, minimum_average;

    /* promptthe user to input for the minimum averagerequired*/
    scanf("%c %d %lf %d",&letter_grade, &minimum_average, &current_average, &percentage);

    /* computethe result */
    score =(minimum_average -current_average*(1-(percentage/100.0)))/(percentage/100.0);

    printf("Minimum average of %d required to get %c\n", minimum_average, letter_grade);
    printf("Your current average is %0.2lf and final is worth %d%%\n", current_average, percentage);
    printf("You need a score of %0.2lf on the final to get %c\n",score, letter_grade);
    

    return 0 ;
}
