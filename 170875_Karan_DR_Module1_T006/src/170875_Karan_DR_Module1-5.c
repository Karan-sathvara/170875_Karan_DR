/*
* File Name     : 170875_Karan_DR_Module1-5.c
* Description   : Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
* Author        : Karan Sathvara
* Created       : 05-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"


void celsius_fahrenheit_reverse(void){

    int16_t celsius;
    float fahrenheit;

    /* Making Table */
    printf("Celsius\tFahrenheit\n");
    printf("-------------------\n");

    /* For loop */
    for (celsius = 300; celsius >= 0; celsius -= 20){

    /* converting celsius to fahrenheit */
        fahrenheit = (9.0/5.0) * celsius + 32;
        printf("%d\t%.2f\n", celsius, fahrenheit);
    }
        ask_continue();
        celsius_fahrenheit_reverse();
}
