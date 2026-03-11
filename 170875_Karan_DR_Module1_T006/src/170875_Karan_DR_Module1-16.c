/*
* File Name     : 170875_Karan_DR_Module1-16.c
* Description   : Write a program to
*                 - longest-line program so it will correctly print the length of arbitrary long input lines,
*		  - as much as possible of the text.
* Author        : Karan Sathvara
* Created       : 11-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "header.h"
#include "function.h"

#define MAXLINE 100

void print_longest_line(){

char line[MAXLINE];
char longest[MAXLINE];
int16_t max = 0;
int16_t len = 0;

    printf("\nProgram Started\n");
    printf("For Exit press CTRL + D\n");

    while(fgets(line,MAXLINE,stdin) != NULL){

	len = strlen(line);

	if(len > max){
	    max = len;
	    strcpy(longest,line);
	}
    }

    if(max > 0){

	printf(	"Longest line length: %hd\n", max);
	printf("Longest line is: %s\n", longest);

    }
    clearerr(stdin);
    ask_continue();
    print_longest_line();
}
