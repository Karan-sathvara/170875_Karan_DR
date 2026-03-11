/*
* File Name     : 170875_Karan_DR_Module2-1.c
* Description   : Write a program
*                 - to determine the ranges of char, short, int, and long variables, both signed and unsigned
*		  - by printing appropriate values from standard headers and by direct computation.
* 		  - Harder if you compute them: determine the ranges of the various floating-point types.
* Author        : Karan Sathvara
* Created       : 17-02-2026
*/


#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "header.h"
#include "function.h"

static void range_using_library(){

    printf("\nRange of signed int: %d to %d", INT_MIN, INT_MAX);
    printf("\nRange of unsigned int: 0 to %u\n\n", UINT_MAX);

    printf("\nRange of signed char: %d to %d", SCHAR_MIN, SCHAR_MAX);
    printf("\nRange of unsigned char: 0 to %u\n\n", UCHAR_MAX);

    printf("\nRange of signed short: %d to %d", SHRT_MIN, SHRT_MAX);
    printf("\nRange of unsigned short: 0 to %hu\n\n", USHRT_MAX);

    printf("\nRange of signed long: %ld to %ld", LONG_MIN, LONG_MAX);
    printf("\nRange of unsigned long: 0 to %lu\n\n", ULONG_MAX);

    printf("\nRange of float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("\nRange of double: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("\nRange of long double: %Le to %Le\n\n", LDBL_MIN, LDBL_MAX);
}

static void range_using_math(){

    unsigned int ui = ~0U;
    printf("Unsigned int range: 0 to %u\n", ui);

    int max = (int) (~0U >> 1);
    int min = - (max + 1);
    printf("signed int range is: %d to %d\n", min, max);

    unsigned char uc = (unsigned char)~0;
    printf("Unsigned char range: 0 to %u\n", uc);

    signed char maxx = (signed char) ((unsigned char)~0U >> 1);
    signed char minn = - (maxx + 1);
    printf("signed char range is: %d to %d\n", minn, maxx);

    signed short maxxx = (signed short) ((unsigned short)~0U >> 1);
    signed short minnn = - (maxxx + 1);
    printf("signed short range is: %d to %d\n", minnn, maxxx);

    unsigned short ush = (unsigned short)~0;
    printf("Unsigned short range: 0 to %u\n", ush);

    signed long maxxxx = (signed long) ((unsigned long)~0U >> 1);
    signed long minnnn = - (maxxxx + 1);
    printf("signed long range is: %ld to %ld\n", minnnn, maxxxx);

    unsigned long ul = (unsigned long)~0;
    printf("Unsigned long range: 0 to %lu\n", ul);

    float mx = (float) (~0U >> 1);
    float mn = - (mx + 1);
    printf("range of float is: %e to %e\n", mn, mx);

    double mxx = (double) (~0U >> 1);
    double mnn = - (mxx + 1);
    printf("range of double is: %e to %e\n", mnn, mxx);

    long double mxxx = (long double) (~0U >> 1);
    long double mnnn = - (mxxx + 1);
    printf("range of long double is: %Le to %Le\n", mnnn, mxxx);


}

void range_of_charcters() {

    int8_t choice;

while(1){
    printf("\nEnter choice:\n");
    printf("1. range using library\n");
    printf("2. range using computing\n");
    scanf("%hhd", &choice);

    if(choice == 1){
        range_using_library();
        ask_continue();
        range_using_library();
    }
    else if(choice == 2){
        range_using_math();
        ask_continue();
        range_using_math();
    }
    else{
        printf("Enter only 1 or 2\n");
    }
}
}
