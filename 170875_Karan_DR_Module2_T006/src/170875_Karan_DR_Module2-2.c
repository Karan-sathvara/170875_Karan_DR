/*
* File Name     : 170875_Karan_DR_Module2-2.c
* Description   : Write a loop
*		 - equivalent to the for loop above without using && or ||.
* Author        : Karan Sathvara
* Created       : 18-02-2026
*/


#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include <string.h>
#include "function.h"

void printFirst_tenChar(){

    char input[100];
    int16_t len = 0;
    int16_t idx = 0;

    printf("\nPress CTRL + D to exit\n");
    while(fgets(input, 100, stdin) != NULL){

	len = strlen(input);
	idx = len - 1;

  	if(input[idx] == '\n'){
	    idx--;
	}
        while(idx > 9){
	    idx--;
	}

	input[idx+1] = '\0';

    }

    printf("string is: %s\n", input);

    clearerr(stdin);
    ask_continue();
    printFirst_tenChar();
}
