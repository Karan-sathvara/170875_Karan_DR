/*
* File Name     : 170875_Karan_DR_Module2-7.c
* Description   :  Write a function invert(x,p,n)
*                - that returns x with the n bits that begin at position p inverted
*                - (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
* Author        : Karan Sathvara
* Created       : 19-02-2026
*/


#include <stdio.h>
#include "header.h"
#include <stdint.h>

void invert(){

    int16_t x;
    int16_t p;
    int16_t n;

    printf("Enter x: ");
    scanf("%hd", &x);

    printf("Enter p: ");
    scanf("%hd", &p);

    printf("Enter n: ");
    scanf("%hd", &n);

    if(x < 0 || p < 0 || n < 0){
        printf("Enter only positive values\n");
        return;
    }

    if(n > p){
        printf("Insufficient bits\n");
        return;
    }

    uint16_t value = 1U << n;  // left shift by n digit
    value = value - 1;

    value = value << (p - n + 1);    // shifting at position

    x = (x ^ value); // XOR operation

    printf("%d\n", x);
}
