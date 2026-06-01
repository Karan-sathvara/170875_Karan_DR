/*
* File Name     : 170875_Karan_DR_Module7-2.c
* Description   : Write a program that will print arbitrary input in a sensible way.
		: As a minimum, it should print non-graphic characters in octal or hexadecimal
		: according to local custom and break long text lines.
* Task		: 1. Handling Non-graphic Characters : should be displayed in octal or hexadecimal format.
		: 2. Line Breaking: Long lines of text should be broken to fit within a specified maximum line length.
* Author        : Karan Sathvara
* Created       : 20-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <ctype.h>

#define MAXLINE 100

/*
* Function Name : handle_nonGraphic_chars
* Description   : this function will display non graphic characters in [hex|octal] format
		: lines greater than 100 handle_nonGraphic_chars
* Author        : Karan Sathvara
* Created       : 20-04-2026
*/

void handle_nonGraphic_chars(){

    int8_t ch = 0;
    int8_t count = 0;
    char buffer[MAXLINE];
    int8_t idxK = 0;

    printf("Enter input : ");
    while ((ch = getchar()) != EOF){
        buffer[idxK++] = ch;
    }

    for(int8_t idxS = 0; idxS < idxK; idxS++){
        if (isprint(buffer[idxS])) {
            putchar(buffer[idxS]);
            count++;
        }
	else{
            printf("[0x%02x|%04o]", buffer[idxS], buffer[idxS]);
                count += 11;
        }

        if (count >= MAXLINE) {
            printf("\n");
            count = 0;
        }
    }
    putchar('\n');
}
