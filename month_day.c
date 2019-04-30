

/* File: month_day.c
   DESC: prints out a complete date according to a day number and a year
   Author: Rishap kumar
*/
#include<stdio.h>
#include<stdlib.h>
// function to check if a given year is leap year or not
int leap_year_check (int year)
{
  if (year % 4 == 0)
    if (year % 100 == 0)
      if (year % 400 == 0)
	return 1;
      else
	return 0;
    else
      return 1;
  return 0;
}

// Array to store the number of days in each month
int size[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int month_day (int year, int yearday, int *month, int *day)
{
// If either the year or yearday is less than 1 return 0
  if (year < 1 || yearday < 1 || yearday > 366)
    return 0;
// If the year is not a leap year but the day is 366 , return 0
  if (yearday == 366 && leap_year_check (year) == 0)
    return 0;
// If the year turns out to a leap year , add the number of day(1) in february
  if (leap_year_check (year) == 1)
    size[1] = 29;
  *month = 0;
  *day = yearday;
// Loop iterates as long as the number of remaining days is larger than the number of days in the next month
  while (yearday > size[*month])
    {
      yearday -= size[*month];
      *month += 1;
    }
// The correct date and month are returned in varibles
  *day = yearday;
  *month += 1;
  return 1;
}

// this is the main funtion which takes commands and print them out accurtaely 
int main ()
{
  int year = -1, day = -1, month = -1;
  scanf ("%d %d", &year, &day);
// Checks for invalid inputs from the user and shows error message
  if (year == -1 && day == -1)
    {
      printf ("Invalid input\n");
      return 1;
    }
// If the process is successful , the date is displays in mm/dd/yyyy form
  if (month_day (year, day, &month, &day))
    {
      printf ("%02d/%02d/%04d\n", month, day, year);
    }
// If unsuccessful,an error message shows
  else
    {
      printf ("Wrong date\n");
    }
  return 0;
}

