/*
* File Name     : 170875_Karan_DR_Module1-4.c
* Description   : Write a program to print the corresponding Celsius to Fahrenheit table.
* Author        : Karan Sathvara
* Created       : 05-02-2026
*/


#include <stdio.h>
#include "header.h"
#include "function.h"
#include <stdint.h>

void celsius_fahrenheit(){

    int16_t temp;

    printf("Enter temperature of degree celsius to convert fahrenheit: ");

    if(scanf("%hd", &temp) != 1){
        printf("Enter valid  number\n");
        return;
    }

    temp_helper(temp);

}

