/*
* File Name     : 170875_Karan_DR_Module4-12.c
* Description   : Adapt the ideas of printd to write a recursive version of itoa;
*                - that is, convert an integer into a string by calling a recursive routine.
* Author        : Karan Sathvara
* Created       : 09-03-2026
*/


#include <stdio.h>
#include "header.h"
#include "stdint.h"

/*
* Function Name : printd
* Description   : this function will convert integer to string recursively
* Author        : Karan Sathvara
* Created       : 09-03-2026
*/

void printd(double digit, char store[], int16_t *index){

    if (digit < 0){
	store[*index] = '-';
	(*index)++;
	digit = -digit;
    }

    int16_t number = (int16_t)digit;

    if (number == 0){
	return;
    }

    if(number / 10){
	printd(number/10, store, index);
    }

    store[*index] = (number % 10 + '0');
    (*index)++;

    double frac = digit - number;

    if(frac > 0){
	store[(*index)++] = '.';

        for(int i = 0; i < 5; i++){
	    frac = frac * 10;
	    int value = (int)frac;
	    store[(*index)++] = value + '0';
	    frac = frac - value;
        }
    }
}

/*
* Function Name : integer_to_char_recursive
* Description   : this function will convert integer to string
* Expected input: 123
* Expected output: 123
* Author        : Karan Sathvara
* Created       : 09-03-2026
*/

void integer_to_char_recursive(){

    double digit;
    char store[50];
    int16_t index = 0;

    printf("Enter digit : ");
    scanf("%lf", &digit);

    printd(digit, store, &index);
    store[index] = '\0';

    printf("String is: %s\n", store);
}
