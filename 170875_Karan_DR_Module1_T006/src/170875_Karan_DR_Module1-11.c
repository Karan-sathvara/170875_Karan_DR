/*
* File Name     : 170875_Karan_DR_Module1-11.c
* Description   : Write a program to
*                 - test the word count program
* Author        : Karan Sathvara
* Created       : 09-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"

void word_counter(void){
    int16_t ch;
    int32_t wc = 0;
    int8_t state = 0;

    printf("\nProgram Started\n");
    printf("For Exit press CTRL + D\n");

    while ((ch = getchar()) != EOF) {
	if (ch == ' ' || ch == '\n' || ch == '\t'){
	    state = 0;
	}

	else {

	if (!state){
	    ++wc;
            state=1;
	}
	}

    }

    printf("Word Count is: %d\n", wc);

    clearerr(stdin);

    ask_continue();
    word_counter();
}
