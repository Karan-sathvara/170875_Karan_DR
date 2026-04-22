/*
* File Name     : 170875_Karan_DR_Module7-9.c
* Description   : Functions like isupper can be implemented to save space or to save time. Explore both possibilities.
*		: The question explores the
		: trade-off between space efficiency and time efficiency when implementing functions like isupper.
* Task		: isupper() can be written in two different ways :
		  1. One that uses less memory   2. One that runs faster
* Author        : Karan Sathvara
* Created       : 22-04-2026
*/

#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "header.h"

#define ITERATIONS 100000

/*
* Function Name : isUpperSpace
* Description   : this function manually check if entered char is in uppercase or not
*		: space efficient
* Author        : Karan Sathvara
* Created       : 22-04-2026
*/

int isUpperSpace(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

/*
* Function Name : isUpperTime
* Description   : this function uses standard library function isupper to check char
* Author        : Karan Sathvara
* Created       : 22-04-2026
*/

int isUpperTime(char ch) {
    return isupper(ch);
}

/*
* Function Name : space_and_time_efficient
* Description   : this is main function who checks how much time taken by both functions
* Author        : Karan Sathvara
* Created       : 22-04-2026
*/

void space_and_time_efficient(){

    char testChar = 'A';
    clock_t start, end;
    double timeSpace = 0.0, timeTime = 0.0;

    volatile int result = 0;

    start = clock();
    for (int idx = 0; idx < ITERATIONS; idx++) {
	result += isUpperSpace(testChar);
    }
    end = clock();
    timeSpace = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    for (int idx = 0; idx < ITERATIONS; idx++) {
	result += isUpperTime(testChar);
    }
    end = clock();
    timeTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\tSpace efficient Implementation : %f seconds\n", timeSpace);
    printf("\tTime efficient Implementation  : %f seconds\n", timeTime);
}
