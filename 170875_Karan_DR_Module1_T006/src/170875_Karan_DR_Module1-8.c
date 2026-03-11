/*
* File Name     : 170875_Karan_DR_Module1-8.c
* Description   : Write a program to
*		  - count blanks, tabs, and newlines.
* Author        : Karan Sathvara
* Created       : 06-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"

//int32_t iName

void count_blanks_tabs_newlines(void){
	int16_t input;
	uint32_t blanks = 0;
	uint32_t tabs = 0;
	uint32_t newlines = 0;

	printf("Program Started\n");
	printf("For Exit press CTRL + D\n");

	while ((input = getchar()) != EOF){

		if (input == ' '){
			blanks=blanks+1;
		}

		else if (input == '\t'){
			tabs=tabs+1;
		}

		else if (input == '\n'){
			newlines=newlines+1;
		}
	}

	printf("Program Ended\n");
	printf("\nTotal Blanks = %u\nTotal Tabs = %u\nTotal Newlines = %u\n", blanks, tabs, newlines);

	/* clear error to ask user again */
	clearerr(stdin);

	ask_continue();
	count_blanks_tabs_newlines();
}
