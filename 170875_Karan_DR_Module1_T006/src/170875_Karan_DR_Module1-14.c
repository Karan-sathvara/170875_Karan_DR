/*
* File Name     : 170875_Karan_DR_Module1-14.c
* Description   : Write a program to
*                 - print a histogram of the frequencies of different characters in its input.
* Author        : Karan Sathvara
* Created       : 10-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"

void print_histogram_ofWord_frequency(void){
    int16_t ch;
    uint32_t freq[256] = {0};

    printf("\nProgram Started\n");
    printf("For Exit press CTRL + D\n");

    while ((ch = getchar()) != EOF){
	freq[ch]++;
    }

//hello :  104 101 108 108 111 (Enter : \n)10

    for (int i = 0; i < 256; i++){
	if (freq[i] > 0){

	    if (i == '\n'){
	        printf("\\n : ");
	    }

	    else if (i == '\t'){
         	printf("\\t : ");
	    }

	    else if (i == ' '){
	        printf("space : ");
	    }

	    else{
		printf ("%c : ", i);
	    }

	    for (int j = 0; j < freq[i]; j++){
                printf("*");
	    }

            printf("\n");

        }
    }


    clearerr(stdin);

    ask_continue();
    print_histogram_ofWord_frequency();

}



