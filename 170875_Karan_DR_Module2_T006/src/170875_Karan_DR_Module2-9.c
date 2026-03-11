/*
* File Name     : 170875_Karan_DR_Module2-9.c
* Description   :  In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
*                - Explain why. Use this observation to write a faster version of bitcount
* Author        : Karan Sathvara
* Created       : 20-02-2026
*/


#include <stdio.h>
#include "header.h"

void bitcount(){

    uint16_t x;
    int8_t count = 0;

    printf("Enter value of x: ");
    scanf("%hd", &x);

    while(x != 0){
	x = x & (x-1);
	count++;
    }
    printf("set bits are %d\n", count);


}

