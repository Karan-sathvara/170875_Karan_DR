/*
* File Name     : 170875_Karan_DR_Module2-6.c
* Description   :  Write a function setbits(x,p,n,y)
*                - that returns x with the n bits that begin at position p inverted
*		 - (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
* Author        : Karan Sathvara
* Created       : 19-02-2026
*/

#include <stdio.h>
#include "header.h"
#include <stdint.h>
#include "function.h"

void setbits(){

    int16_t x;
    int16_t p;
    int16_t n;
    int16_t y;

    printf("Enter x: ");
    scanf("%hd", &x);

    printf("Enter p: ");
    scanf("%hd", &p);

    printf("Enter n: ");
    scanf("%hd", &n);

    printf("Enter y: ");
    scanf("%hd", &y);

    if(x < 0 || p < 0 || n < 0 || y < 0){
	printf("Enter only positive values\n");
	return;
    }

    if(n > p){
	printf("Insufficient bits");
        return;
    }

    int16_t value = 1U << n;    // left shift unsigned 1 by n digit
    value = value - 1;                 // from value subtract 1 to get last n digits

    y = y & value; // will get last n digits from y

    y = y << (p - n + 1); // shift n digits at p position in y

    int16_t new = (value << (p - n + 1));   // shift digit at n position

    int16_t neww  = ~(new);  // toggle

    x = x & neww;

    x = x | y;

    printf("%d\n", x);


}
