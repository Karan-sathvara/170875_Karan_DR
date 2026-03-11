/*
* File Name     : 170875_Karan_DR_Module4-2.c
* Description   : Extend atof to handle scientific notation of the form
*                -  123.45e-6
*                - where a floating-point number may be followed by e or E and an optionally signed exponent.
* Author        : Karan Sathvara
* Created       : 02-03-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>

void extended_atof(){

    char store[100];
    int8_t index = 0;
    int8_t num = 0;
    int8_t dot_index = 0;
    int8_t sign = 1;

    printf("Enter input notation: ");
    scanf("%s", store);

    /* checking first element is negative or not */
    int8_t negative = 0;
    if(store[0] == '-'){
	negative = 1;

        while(store[index] != '\0'){
    	    store[index] = store[index+1];
	    index++;
        }
    }

    /* Finding Dot index */
    if(negative){
	dot_index--;
    }
    for(index = 0; store[index] != 'e'; index++){
        if (store[index] == '.'){
            dot_index = index;
        }
    }


    /* storing last digit for expansion */
    for(index=0; store[index] != '\0'; index++){
	if (store[index] == 'e'){
	    index++;

	    if(store[index] == '-'){
	        sign = -1;
	        index++;
	    }
	    else if (store[index] == '+'){
	        sign = 1;
		index++;
	    }
            while(store[index] >= '0' && store[index] <= '9'){
                num = num * 10 + (store[index] - '0');
                index++;
            }
        }
    }

    /* removing every character after e */
    for(index=0; store[index] != '\0'; index++){
        if (store[index] == 'e'){
            store[index] = '\0';
	}
    }

    /* removing decimal */
    for(index=0; store[index] != '\0'; index++){
        if (store[index] == '.'){
            for(int8_t j = index; store[j] != '\0'; j++){
                store[j] = store[j + 1];
            }
        }
    }

    int8_t new_decimal;
    if(sign == -1){
	new_decimal = dot_index - num;
    }
    else if(sign == 1){
	new_decimal = dot_index + num;
    }

    /* printing the equivalent expansion */
    int8_t len = strlen(store);

    printf("Equivalent expansion is : ");

    if(negative){
        printf("-");
    }

    if (sign == -1){
	if(new_decimal <= 0){
	    int8_t zeros = -new_decimal;
	    printf("0.");
	    for(index = 0; index < zeros; index++){
	        printf("0");
	    }
	    printf("%s\n", store);
        }
	else{
	    for(index = len; index >= new_decimal; index--){
		store[index + 1] = store[index];
	    }
	    store[new_decimal] = '.';
            printf("%s\n", store);
        }
    }
    else if(sign == 1){
	if(new_decimal >= len){
    	    printf("%s", store);
            for(index = 0; index < new_decimal - len; index++){
                printf("0");
            }
    	    printf("\n");
	}
        else{
            for(index = len; index >= new_decimal; index--){
                store[index + 1] = store[index];
            }

            store[new_decimal] = '.';
	    printf("%s\n", store);
        }
    }
}

