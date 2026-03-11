/*
* File Name     : 170875_Karan_DR_Module1-17.c
* Description   : Write a program to
*                 - print all input lines that are longer than 80 characters.
* Author        : Karan Sathvara
* Created       : 11-02-2026
*/

/*
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <header.h>

#define MAXLINE 81

//void Module1Task17(){

char input[MAXLINE];
int16_t len = 0;
int16_t longline = 0;

printf("\npress CTRL + D to exit the program\n\n");

    if(fgets(input,MAXLINE,stdin) != NULL){

	len = strlen(input);

	longline = (len > 0 && input[len-1] != '\n');

	while(len > 0 && input[len-1] != '\n'){
            char extra[MAXLINE];

	    if(fgets(extra,MAXLINE,stdin) == NULL){
		break;
	    }

	    len += strlen(extra);

	    if(extra[strlen(extra)-1] == '\n'){
		break;
	    }
        }


        if (longline){
            printf("Line longer than 80 characters: %hd = %s\n", len, input);
        }
        else{
            printf("Line is not longer than 80 characters: %hd = %s\n", len, input);
        }
    }
}


*/
