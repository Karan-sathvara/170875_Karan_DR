/*
* File Name     : 170875_Karan_DR_Module3-5.c
* Description   : Write the function itob(n,s,b)
*                - that converts the integer n into a base b character representation in the string s.
*                - In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
* Author        : Karan Sathvara
* Created       : 26-02-2026
*/


#include <stdio.h>
#include "header.h"
#include <stdint.h>
#include <string.h>
#include "function.h"


void itob(){

    int16_t digit;
    char str[100];
    int8_t base;
    int16_t index = 0;

    printf("Enter digit : ");
    scanf("%hd", &digit);

    int16_t sign = digit;

    if(digit < 0){
        digit = -digit;
    }

    printf("Enter base (between 2 to 16) :");
    scanf("%hhd", &base);


    if(base < 2 || base > 16){
        printf("Enter a valid base value\n");
    	return;
    }

    while(digit > 0){
	int16_t remainder = digit % base;

	if(remainder < 10){
            str[index++] = remainder + '0';
	}
	else{
           str[index++] = remainder - 10 + 'A';
	}
	digit = digit / base;
    }

    if(sign < 0){
	str[index++] = '-';
    }
    str[index+1] = '\0';
    reverse(str);

    printf("Equivalent base : %s\n", str);

}
