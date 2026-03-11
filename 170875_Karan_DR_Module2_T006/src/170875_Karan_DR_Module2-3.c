/*
* File Name     : 170875_Karan_DR_Module2-3.c
* Description   : Write a loop
*                - equivalent to the for loop above without using && or ||.
* Author        : Karan Sathvara
* Created       : 18-02-2026
*/


#include <stdio.h>
#include "header.h"
#include <stdint.h>
#include "function.h"

void htoi(){

    char hex[1000];
    int16_t i = 0;
    int16_t decimal = 0;
    int16_t integer = 0;

    printf("\nPress CTRL + D to exit\n");
    printf("Enter hexadecimal value : ");
    scanf("%s", hex);

    if(hex[0] == '0' && (hex[1] == 'X' || hex[1] == 'x'))
    i=2;

    while(hex[i] != '\0'){
	if(hex[i] >= '0' && hex[i] <= '9'){
	    decimal = hex[i] - '0';
	}
	else if(hex[i] >= 'A' && hex[i] <= 'F'){
	    decimal = hex[i] - 'A' + 10;
	}
	else if(hex[i] >= 'a' && hex[i] <= 'f'){
	    decimal = hex[i] - 'a' + 10;
	}
	else{
	    printf("Enter valid hex number\n");
	    return;
	}

	integer = integer*16 + decimal;
	i++;
    }
    printf("Decimal equivalent is : %d\n\n", integer);
}
