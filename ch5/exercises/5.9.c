//Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of
//indexing.

#include <stdio.h>


static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    char *pointer_to_daytab;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    
    //Assign daytab[leap] to var   
    pointer_to_daytab = daytab[leap];

    if (month >= 1  && month <= 12 && day >= 1 && day <= *(pointer_to_daytab + month)) {
    for (i = 1; i < month; i++)
        day += *(pointer_to_daytab + i);
    return day;
    }
    else {
        return 0;
    }

}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    char *pointer_to_daytab;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    //Assign daytab[leap][i] to var
    pointer_to_daytab = daytab[leap];

    if (yearday >= 1 && yearday <= *(pointer_to_daytab + *pmonth)) {
    for (i = 1; yearday > *pointer_to_daytab; i++)
        yearday -= *(pointer_to_daytab + i);
    *pmonth = i;
    *pday = yearday;
    }
    else {
        *pmonth = 0;
        *pday = 0;
    }
}