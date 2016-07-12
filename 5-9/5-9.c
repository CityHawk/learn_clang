#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year:  set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int leap;
    char *p;

    if ( month < 1 || month > 12 || year < 0 || day > 31 || day < 1)
        return -1;

    leap = ( year%4 == 0 && year%100 != 0 ) || ( year%400 == 0 );
    p = &daytab[leap][1];
    while ( *p < month ) {
        day += *p;
        p++;
    }
    return day;
}

/* month_day:  set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap;
    char *p;

    if (year < 0)
        return -1;

    leap = ( year%4 == 0 && year%100 != 0) || (year%400 == 0);
    if (yearday < 1 || (yearday > 365 && leap == 0) || (yearday > 366 && leap == 1))
        return -1;

    p = &daytab[leap][1];
    while (yearday > *p) {
        yearday -= *p;
        p++;
    }
    *pmonth = *p;
    *pday = yearday;
    return 0;
}

int main() {
    int pm, pd;

    printf("2007-9-13 %d\n", day_of_year(2007,9,13));
    month_day(2007,256,&pm,&pd);
    printf("256 2007 %d %d\n", pm, pd);
    printf("2007-9-13 %d\n", day_of_year(2007,15,13));
    month_day(2007,366,&pm,&pd);
    printf("366 2007 %d %d\n", pm, pd);
    month_day(2008,366,&pm,&pd);
    printf("366 2008 %d %d\n", pm, pd);
}
