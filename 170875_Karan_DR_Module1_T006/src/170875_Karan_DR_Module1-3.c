/*
* File Name     : 170875_Karan_DR_Module1-3.c
* Description   : Modify the temperature conversion program to print a heading above the table.
* Author        : Karan Sathvara
* Created       : 04-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"

void temp_converter(void){

    int16_t celsius;
    float fahrenheit;

    /* Making Table */
    printf("Celsius\tFahrenheit\n");
    printf("-------------------\n");

    /* For loop */
    for (celsius = 0; celsius <= 300; celsius += 20){

    /* converting celsius to fahrenheit */
	fahrenheit = (9.0/5.0) * celsius + 32;
    	printf("%d\t%.2f\n", celsius, fahrenheit);

    }
        ask_continue();
	temp_converter();
}

