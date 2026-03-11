/*
* File Name     : 170875_Karan_DR_Module1-17.c
* Description   : Write a program to
*                 - print all input lines that are longer than 8 characters.
* Author        : Karan Sathvara
* Created       : 11-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <header.h>
#include "function.h"

#define MAXLINE 100
#define MAXLINES 100

void print_lines_longer_than_8char(){

    char line[MAXLINES];
    char long_line[MAXLINES];
    int16_t length;
    int16_t idx;

    printf("\npress CTRL + D to exit the program\n\n");

    while(fgets(line, sizeof(line), stdin) != NULL){

    if (line[idx] == '\t' || line[idx] == ' '){
	idx--;
    }
	length = strlen(line);

    if (length > 8){
	strcat(long_line,line);
    }
    }

    if (strlen(long_line) > 0){
	printf("Line longer than 8 character is:\n%s", long_line);
    }

    clearerr(stdin);
    ask_continue();
    print_lines_longer_than_8char();
}

