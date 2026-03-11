/*
* File Name     : 170875_Karan_DR_Module1-12.c
* Description   : Write a program to
*                 - prints its input one word per line.
* Author        : Karan Sathvara
* Created       : 09-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"

void print_words_per_line(void){
    int16_t ch;

    printf("\nProgram Started\n");
    printf("For Exit press CTRL + D\n");

    while ((ch = getchar()) != EOF) {

        if ((ch == ' ') || (ch == '\t')){
            putchar('\n');
        }

	else {
	    putchar(ch);
	}
    }

    clearerr(stdin);

    ask_continue();
    print_words_per_line();
}
