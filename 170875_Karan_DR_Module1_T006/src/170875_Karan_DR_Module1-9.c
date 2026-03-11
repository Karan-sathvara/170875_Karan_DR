/*
* File Name     : 170875_Karan_DR_Module1-9.c
* Description   : Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
* Author        : Karan Sathvara
* Created       : 06-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"

void removeMultipleSpaces(void){
    int16_t ch;
    uint8_t last_space = 0;

    printf("Program Started\n");
    printf("For Exit press CTRL + D\n");

    while ((ch = getchar()) != EOF) {

	if (ch == '\n'){
            printf("\nNew line detected\n");
        }
        if (ch == ' ' || ch == '\t' ) {

            if (!last_space) {
                printf("%c", ch);
                last_space = 1;
            }
         }

         else {
                printf("%c", ch);
                last_space = 0;
         }
    }

    clearerr(stdin);

    ask_continue();
    removeMultipleSpaces();
}

