/*
* File Name     : 170875_Karan_DR_Module3-4.c
* Description   : In a two's complement number representation,
*                - our version of itoa does not handle the largest negative number
*                - that is the value of n equal to -(2wordsize-1).
*		 - Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.
* Author        : Karan Sathvara
* Created       : 26-02-2026
*/


#include <stdio.h>
#include "header.h"
#include "function.h"
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include "function.h"

/*
* Function Name : itoa
* Description   : This function converts integer to string
* input         : 123
* output        : "123"
* Author        : Karan Sathvara
* Created       : 26-02-2026
*/

void itoa(int32_t number, char str[]){

    int32_t integer = 0;
    int32_t sign = number;

    do{
        int32_t digit = number % 10;

	if(digit < 0){
	    digit = -digit;
	}

	str[integer++] = digit + '0';
	number = number/10;

    }while(number != 0);

    if (sign < 0){
	str[integer++] = '-';
    }

    str[integer] = '\0';
    reverse(str);

}

/*
* Function Name : integer_to_character
* Description   : This function solves problem :
*		: in 32 bit range is -2147483648 to 2147483647
*		: old itoa take whole number and then perform operation
* input         : -2147483648
* output        : -2147483648
* Author        : Karan Sathvara
* Created       : 26-02-2026
*/

void integer_to_character(){

    long temp;
    int32_t number;
    char str[50];

    printf("Enter number: ");
    scanf("%ld", &temp);

    if (temp > INT_MAX || temp < INT_MIN) {
        printf("Entered number is not in range\n");
	return;
    }

    number = (int32_t)temp;

    itoa(number, str);
    printf("Output is: %s\n", str);
}
