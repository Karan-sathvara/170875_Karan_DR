/*
* File Name     : 170875_Karan_DR_Module1-13.c
* Description   : Write a program to
*                 - print a Horizontal histogram of the lengths of words in its input.
*                 - print a Vertical histogram of the lengths of words in its input.
* Author        : Karan Sathvara
* Created       : 10-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"

/* Horizontal Histogram */

static void horizontal_histogram(void){
    int16_t ch;
    int8_t state = 0;

    while ((ch = getchar()) != EOF){

	if ((ch == ' ') || (ch == '\n') || (ch == '\t')){

	    if (state == 1){
		printf("\n");
		state = 0;
	    }
	}
        else {
	        printf ("* ");
		state = 1;
	}
    }
}

/* Vertical Histogram */

#define MAXWORDS 50
static void vertical_histogram(void){


    int16_t ch;
    int8_t state = 0;
    int words[MAXWORDS];
    int32_t len = 0;
    int32_t count = 0;
    int32_t max = 0;

    while((ch = getchar()) != EOF){

        if(ch == ' ' || ch == '\n' || ch == '\t'){
            if(state == 1){
		if(count >= MAXWORDS){
    		    fprintf(stderr,"Error: Maximum word limit (%d) exceeded.\n", MAXWORDS);
        	    return;
		}

                words[count++] = len;

                if(len > max)
                    max = len;

                len = 0;
                state = 0;
            }
        }
        else{
            len++;
            state = 1;
        }
    }

    for(int i = max; i > 0; i--){
        for(int j = 0; j < count; j++){

            if(words[j] >= i)
                printf(" * ");
            else
                printf("   ");
        }
        printf("\n");
    }

}

/*    User Choice     */

void histogram() {

    int8_t choice;

    printf("\nEnter choice:\n");
    printf("1. Horizontal\n");
    printf("2. Vertical\n");
    scanf("%hhd", &choice);

    if(choice == 1){
        horizontal_histogram();

	clearerr(stdin);
	ask_continue();
	histogram();
    }
    else if(choice == 2){
        vertical_histogram();

        clearerr(stdin);
        ask_continue();
        histogram();
    }
    else{
        printf("Enter only 1 or 2\n");
    }
}
