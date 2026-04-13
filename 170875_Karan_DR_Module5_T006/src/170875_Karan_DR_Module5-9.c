/*
* File Name     : 170875_Karan_DR_Module5-9.c
* Description   : Revised previous question using pointer
*               : Remedy this defect.
* Author        : Karan Sathvara
* Created       : 01-04-2026
*/

#include <stdio.h>
#include "header.h"

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/*
* Function Name : day_of_year
* Description   : this function returns day of year
* Author        : Karan Sathvara
* Created       : 01-04-2026
*/

int day_of_year(int16_t year, int8_t month, int16_t day){

    int8_t leap = 0;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (year <= 0) {
        printf("Year must be positive\n");
        return -1;
    }

    if (month < 1 || month > 12) {
        printf("Month must be between 1 to 12\n");
        return -1;
    }

    if (day < 1 || day > daytab[leap][month]) {
        printf("Invalid day for given month and year\n");
        return -1;
    }

    char *start = &daytab[leap][1];
    char *end = start + (month - 1);

    while(start < end){
	day += *start++;
    }

    return day;
}

/*
* Function Name : month_day
* Description   : this function returns back month and day
* Author        : Karan Sathvara
* Created       : 01-04-2026
*/

void month_day(int16_t year, int16_t yearday, int8_t *pmonth, int16_t *pday){

    int8_t leap = 0, idx = 0;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int16_t maxdays = leap ? 366 : 365;

    if(yearday < 1 || yearday > maxdays){
	printf("Day of the year must be between 1 and %hd for %hd year as it not a leap year\n", maxdays, year);
	*pmonth = -1;
	*pday = -1;
	return;
    }

    char *start = &daytab[leap][1];

    for (idx = 1; idx <= 12 && yearday > *(start + idx - 1); idx++){
        yearday -= *(start + idx - 1);
    }

    *pmonth = idx;
    *pday = yearday;
}

/*
* Function Name : calender
* Description   : this is the main function which controls the execution of program
* Author        : Karan Sathvara
* Created       : 01-04-2026
*/

void calender_using_ptr(){

    int16_t iYear = 0, iDay = 0, yearday = 0, outDay = 0;
    int8_t iMonth = 0, outMonth = 0, choice = 0;

    printf("What do you want to use\n");
    printf("1. Day of year\n");
    printf("2. Month day\n");
    scanf("%hhd", &choice);

    switch(choice){
	case 1 :
	    printf("\nEnter Year : ");
    	    scanf("%hd", &iYear);

    	    printf("Enter Month : ");
    	    scanf("%hhd", &iMonth);

	    printf("Enter Day : ");
	    scanf("%hd", &iDay);

	    yearday = day_of_year(iYear, iMonth, iDay);
	    if(yearday == -1){
		return;
    	    }
	    printf("Day of year: %d\n", yearday);

	    break;

	case 2 :
	    printf("\nEnter Year : ");
	    scanf("%hd", &iYear);

	    printf("Enter yearday : ");
	    scanf("%hd", &yearday);

	    month_day(iYear, yearday, &outMonth, &outDay);
	    if(outMonth == -1){
                return;
    	    }

	    printf("Converted back into Month: %d Day: %d\n", outMonth, outDay);
	    break;

	default :
	    printf("Invalid input\n");
	    break;

	}
}
