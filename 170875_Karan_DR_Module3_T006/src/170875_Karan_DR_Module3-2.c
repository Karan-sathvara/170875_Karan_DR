/*
* File Name     : 170875_Karan_DR_Module3-2.c
* Description   : Write a function escape(s,t)
*                - that converts characters like newline and tab into visible escape sequences
*                - like \n and \t as it copies the string t to s. Use a switch
* Author        : Karan Sathvara
* Created       : 25-02-2026
*/


#include <stdio.h>
#include "header.h"
#include <stdint.h>


void escape(int16_t input, char output_str[], int16_t *index){

	switch (input){
	    case '\n':
		output_str[(*index)++] = '\\';
		output_str[(*index)++] = 'n';
	        break;

            case '\t':
                output_str[(*index)++] = '\\';
                output_str[(*index)++] = 't';
                break;

	    default:
		output_str[(*index)++] = input;
        }
}


void escapes_tab_newline(){

    int16_t index = 0;
    int16_t input;
    char output_str[1000];

    printf("Press CTRL + D to exit\n");
    printf("Enter input string: ");
    while((input = getchar()) != EOF){
    	escape(input, output_str, &index);
    }

    output_str[index] = '\0';
    printf("converted string is: %s\n", output_str);
}




