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

void unescape(char original_str[], char output_str[]){

    int16_t iidx = 0;
    int16_t jidx = 0;

    while(output_str[iidx] != '\0'){
        if(output_str[iidx] == '\\') {
            iidx++;
            switch(output_str[iidx]){
	        case 'n':
		    original_str[jidx++] = '\n';
		    break;
	        case 't':
                    original_str[jidx++] = '\t';
                    break;
	        default:
		    original_str[jidx++] = output_str[iidx];
	        }
	}
	else{
	    original_str[jidx++] = output_str[iidx];
	}
	iidx++;
    }
    original_str[jidx] = '\0';
    printf("Original string is : %s", original_str);
}

void escapes_tab_newline(){

    int16_t index = 0;
    int16_t input;
    char output_str[1000];
    char original_str[1000];

    printf("Press CTRL + D to exit\n");
    printf("Enter input string: ");
    while((input = getchar()) != EOF){
    	escape(input, output_str, &index);
    }

    output_str[index] = '\0';
    printf("converted string is: %s\n", output_str);
    clearerr(stdin);

    char choice;
    printf("Do you want original input string?\n");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y'){
	unescape(original_str,output_str);
    }
    else{
	printf("Program ended\n");
    }
}




