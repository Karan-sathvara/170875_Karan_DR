/*
* File Name     : 170875_Karan_DR_Module2-5.c
* Description   : alternative version of squeeze(s1,s2)
*                - that deletes each character in s1 that matches any character in the string s2.
* Author        : Karan Sathvara
* Created       : 19-02-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>
#include <ctype.h>
#include "function.h"

void any(){

    char str1[1000];
    char str2[1000];
    uint32_t freq[256] = {0};
    unsigned char c;
    int16_t idx1 = 0;
    int16_t idx2 = 0;
    int16_t len1 = 0;
    int16_t len2 = 0;

    printf("\nPress CTRL + D to exit\n");
    printf("Enter first string: ");
    fgets(str1, 1000, stdin);

    len1 = strlen(str1);
    idx1 = len1 - 1;

    if(str1[idx1] == '\n'){
	idx1--;
    }
    str1[idx1+1] = '\0';

    printf("Enter second string: ");
    fgets(str2, 1000, stdin);

    len2 = strlen(str2);
    idx2 = len2 - 1;

    if(str2[idx2] == '\n'){
        idx2--;
    }
    str2[idx2+1] = '\0';

    for(int i=0; str1[i] != '\0'; i++){
        c=str1[i];
	if(freq[tolower(c)] == 0){
	    freq[tolower(c)] = i+1;
	}
    }

    for(int i=0; str2[i] != '\0'; i++){
	c=str2[i];

	if(freq[tolower(c)] != 0){
	    printf("Duplicate character is found at position %d in string 1\n", freq[tolower(c)]);
	    return;
	}
    }
    printf("No duplicate characters found\n");

    ask_continue();
    any();
}














