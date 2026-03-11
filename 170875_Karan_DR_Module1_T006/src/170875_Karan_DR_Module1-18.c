/*
* File Name     : 170875_Karan_DR_Module1-18.c
* Description   : Write a program to
*                 - remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
* Author        : Karan Sathvara
* Created       : 11-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <header.h>
#include "function.h"

#define MAXLINE 100

void remove_trailing_TabsSpace(){

int16_t len = 0;
int16_t idx = 0;
int16_t new_len;
char input[MAXLINE];

    printf("\nPress CTRL + D to exit\n");
    while(fgets(input, MAXLINE, stdin) != NULL){

	if (input[0] == '\t' || input[0] == ' '){
            printf("\nEmpty string\n");
            return;
        }

	len = strlen(input);

	idx = len - 1;

	if (input[idx] == '\n'){
	    idx--;
	}

	while(idx >= 0 && (input[idx] == '\t' || input[idx] == ' ')){
	    idx--;
	}

	input[idx+1] = '\0';

	new_len = strlen(input);

	printf("%s\n", input);
        printf("Before length: %d\n", len);
        printf("After length : %d\n", new_len);
    }
    clearerr(stdin);
    ask_continue();
    remove_trailing_TabsSpace();
}

