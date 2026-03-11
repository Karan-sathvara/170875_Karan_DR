/*
* File Name     : 170875_Karan_DR_Module1-20.c
* Description   : Write a program
*                 - detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop.
* Author        : Karan Sathvara
* Created       : 12-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"

#define TAB 4
#define MAXLINE 100

void detab(){

int16_t ch;
int16_t col = 0;
int16_t spaces;
int8_t prev_space = 0;

    printf("\nPress CTRL + D to exit the program\n");
    printf("Program started\n\n");

    while ((ch = getchar()) != EOF){

        if (ch == '\t'){

            spaces = TAB - (col % TAB);

	    for (int i = 0; i < spaces; i++){

		putchar('*');
		col++;
	    }
	}

	else if (ch == ' '){

	    if (!prev_space){

		putchar(ch);
		col++;
		prev_space = 1;
	    }
	}

	else if (ch == '\n'){

	    putchar(ch);
	    col = 0;
	}

	else{

	    putchar(ch);
	    col++;
	    prev_space = 0;
	}
    }

    clearerr(stdin);
    ask_continue();
    detab();
}
