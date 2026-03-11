/*
* File Name     : 170875_Karan_DR_Module1-22.c
* Description   : Write a program
*                 - ``fold'' long input lines into two or more shorter lines,
*                 after the last non-blank character that occurs before the n-th column of input.
*                 Make sure your program does something intelligent with very long lines,
*                 and if there are no blanks or tabs before the specified column.
* Author        : Karan Sathvara
* Created       : 12-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"

#define MAXLINE 1000
#define FOLD 10

void fold_after_tenchars(){

    int16_t ch;
    int16_t col = 0;
    char input[MAXLINE];
    int16_t last_blank = -1;

    printf("\nPress CTRL + D to exit the program\n");
    printf("Program started\n\n");

    while ((ch = getchar()) != EOF){

         if (ch == '\n') {
             for (int i = 0; i < col; i++){
                putchar(input[i]);
            }
            putchar('\n');
            col = 0;
            last_blank = -1;
            continue;
         }

	input[col] = ch;
        if(ch == ' ' || ch == '\t'){
	    last_blank = col;
	}
        col++;

	if (col > FOLD){
            	if (last_blank >= 0){
	            for(int i = 0; i <= last_blank; i++){
		        putchar(input[i]);
		    }
	            putchar('\n');

		    /* Find remaining charcters to store after folding */
		    col = col - last_blank - 1;
		    for(int i = 0; i < col; i++){
			input[i] = input[last_blank + 1 + i];
		    }

	        }

 	        else{

		    for(int j = 0; j < col; j++){
		        putchar(input[j]);
		    }

		    putchar('\n');
		    col = 0;
		}
		last_blank = -1;
	 }
    }
}



