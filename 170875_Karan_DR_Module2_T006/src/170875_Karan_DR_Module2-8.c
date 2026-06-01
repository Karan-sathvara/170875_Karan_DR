/*
* File Name     : 170875_Karan_DR_Module2-8.c
* Description   :  Write a function rightrot(x,n)
*                - that returns the value of the integer x rotated to the right by n positions.
* Author        : Karan Sathvara
* Created       : 20-02-2026
*/

#include <stdio.h>
#include "header.h"

void rightrot(){

    int16_t x;
    int16_t n;

    printf("Enter value of x: ");
    scanf("%hd", &x);

    printf("Enter value of n: ");
    scanf("%hd", &n);

    if(n < 0 || x < 0){
        printf("Number must be non Negative\n");
        return;
    }

    uint16_t value = (1U << n);

    value = value - 1;  // to get last bit of 1U

    value = value & x;

    value = (value) << (15 - n + 1); // to move bits at leftmost

    x = (x >> n);

    x = (x | value);

    printf("value of x is: %d\n", x);
}
