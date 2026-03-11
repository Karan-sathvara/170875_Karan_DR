/*
* File Name     : 170875_Karan_DR_Module3-7.c
* Description   : Version of Task 2 with fgets
*                -
*                -
* Author        : Karan Sathvara
* Created       : 25-02-2026
*/


#include <stdio.h>
#include "header.h"
#include <stdint.h>
#include <string.h>

void escape(char input_str[], char output_str[]){

    int16_t idx_i = 0;
    int16_t idx_j = 0;

    while(input_str[idx_i] != '\0'){
	switch (input_str[idx_i]){
	    case '\n':
		output_str[idx_j] = '\\';
		idx_j++;
		output_str[idx_j] = 'n';
		idx_j++;
	        break;

            case '\t':
                output_str[idx_j] = '\\';
		idx_j++;
                output_str[idx_j] = 't';
		idx_j++;
                break;

	    default:
		output_str[idx_j] = input_str[idx_i];
		idx_j++;
        }
	idx_i++;
    }
    output_str[idx_j] = '\0';
}


void Module3Task7(){

    char input_str[1000];
    char output_str[1000];

    printf("Enter input string: ");
    while(fgets(input_str, sizeof(input_str), stdin) != NULL){
	escape(input_str, output_str);
	printf("converted string is: %s", output_str);
    }
}


