/*
* File Name     : 170875_Karan_DR_Module1-10.c
* Description   : Write a program to copy its input to its output
*                 -  replacing each tab by \t
*                 -  and each backslash by \\
* Author        : Karan Sathvara
* Created       : 09-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"

void escape_special_characters(void){
    int16_t ch;

    printf("Program Started\n");
    printf("For Exit press CTRL + D\n");

    while ((ch = getchar()) != EOF) {

        if (ch == '\t'){
	    printf("\\t");
	}

	else if (ch == '\\'){
	    printf("\\\\");
	}

	else {
	    putchar(ch);
	}
    }

    clearerr(stdin);

    ask_continue();
    escape_special_characters();
}
