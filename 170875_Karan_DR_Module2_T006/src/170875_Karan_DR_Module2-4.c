/*
* File Name     : 170875_Karan_DR_Module2-4.c
* Description   : Write an alternative version of squeeze(s1,s2)
*                - that deletes each character in s1 that matches any character in the string s2.
* Author        : Karan Sathvara
* Created       : 18-02-2026
*/


#include <stdio.h>
#include "header.h"
#include <ctype.h>
#include "function.h"

void squeeze(){

    char str1[1000];
    char str2[1000];

    uint32_t freq[256] = {0};
    unsigned char c;

    printf("\nPress CTRL + D to exit\n");
    printf("Enter first string: ");
    fgets(str1, 1000, stdin);

    printf("Enter second string: ");
    fgets(str2, 1000, stdin);

    for(int i = 0; str1[i] != '\0'; i++){
	c=str1[i];
	freq[tolower(c)]=1;
    }

    for(int i = 0; str2[i] != '\0'; i++){
        c=str2[i];
        freq[tolower(c)]=0;
    }
    printf("output string is: ");
    for(int i = 0; str1[i] != '\0'; i++){
	c=str1[i];
        if(str1[i] && freq[tolower(c)]){
	    printf("%c", str1[i]);
	}
	else{
	    continue;
	}
    }
    putchar('\n');

    ask_continue();
    squeeze();
}





