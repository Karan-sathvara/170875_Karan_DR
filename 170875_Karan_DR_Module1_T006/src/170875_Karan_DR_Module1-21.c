/*
* File Name     : 170875_Karan_DR_Module1-21.c
* Description   : Write a program
*                 - entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing.
* Author        : Karan Sathvara
* Created       : 12-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"

#define TAB 8

void entab(){

    int16_t ch;
    int16_t space_count = 0;
    int16_t col = 0;
    int16_t spaces_to_tab;

    printf("\nPress CTRL + D to exit the program\n");
    printf("Program started\n\n");

    while ((ch = getchar()) != EOF){
	if (ch == ' '){
	    space_count++;
	    col++;

            spaces_to_tab = TAB - (col - space_count) % TAB;

            if (space_count == spaces_to_tab) {
                putchar('*');
                space_count = 0;
            }
        }
        else {

            while (space_count > 0) {
                putchar(' ');
                space_count--;
            }

            putchar(ch);

            if (ch == '\n')
                col = 0;
            else
                col++;
        }
    }
    while (space_count > 0) {
        putchar(' ');
        space_count--;
    }

    clearerr(stdin);
    ask_continue();
    entab();
}
