/*
* File Name     : 170875_Karan_DR_Module1-19.c
* Description   : Write a
*                 - function reverse(s) that reverses the character string s.
*		  - Use it to write a program that reverses its input a line at a time.
* Author        : Karan Sathvara
* Created       : 11-02-2026
*/

#include <stdio.h>
#include "header.h"
#include "function.h"

#define MAXLINE 50

void print_reverse_string(){

char input[MAXLINE];

    printf("\nPress CTRL + D to exit the program\n");
    printf("Program started\n\n");

    while(fgets(input, MAXLINE, stdin) != NULL){

        if (input[0] == '\n'){
            printf("Empty string\n");
            return;
        }

        reverse_s(input);
        printf("Reverse string is: %s\n", input);

    }
}
