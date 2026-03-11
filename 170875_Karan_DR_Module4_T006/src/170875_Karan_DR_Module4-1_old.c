/*
* File Name     : 170875_Karan_DR_Module4-1.c
* Description   : Write the function strindex(s,t)
*                -  which returns the position of the rightmost occurrence of t in s
*		 - or -1 if there is none
* Author        : Karan Sathvara
* Created       : 27-02-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>

void strindex(){

    char str[100];
    char input;
    int8_t len;
    int8_t index;

    printf("Enter input string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter character to find: ");
    scanf(" %c", &input);

    len = strlen(str);

    if(str[len - 1] == '\n'){
	len--;
    }

    for(index = len - 1; index >= 0; index--){
	if(str[index] == input){
//	    printf("character %c found at %d index\n", input, index);
	    printf("character %c is found at: %d\n", input, len - index);
	    return;
	}
    }
    printf("No duplicate characters found\n");
//    printf("Length of string %d\n", len);

}
