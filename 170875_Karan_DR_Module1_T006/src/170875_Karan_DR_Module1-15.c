/*
* File Name     : 170875_Karan_DR_Module1-15.c
* Description   : Write a program to
*                 - temperature conversion program to use a function for conversion.
* Author        : Karan Sathvara
* Created       : 10-02-2026
*/

#include <stdio.h>
#include "header.h"
#include "function.h"
#include <stdint.h>

void convert_temperature_using_helper(){

    int16_t temp;

    printf("Enter temperature of degree celsius to convert fahrenheit: ");

    if(scanf("%hd", &temp) != 1){
	printf("Enter valid  number\n");
	return;
    }

    float result = temp_helper(temp);

    printf("%hd celsius = %.1f fahrenheit\n", temp, result);

}

