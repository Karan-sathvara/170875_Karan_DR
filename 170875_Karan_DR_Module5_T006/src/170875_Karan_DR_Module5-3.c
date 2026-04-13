/*
* File Name     : 170875_Karan_DR_Module5-3.c
* Description   : Write a Function strcat
*                - strcat(s,t) copies the string t to the end of s.
* Author        : Karan Sathvara
* Created       : 00-03-2026
*/

#include <stdio.h>
#include "header.h"

void strcat_without_library(char *str1,char *str2){

    while(*str1 != '\0'){

	if(*str1 == '\n'){
	    *str1-- = '\0';
	}

	*str1++;
    }

    while(*str2 != '\0'){

        if(*str2 == '\n'){
            *str2-- = '\0';
	    *str2++;
        }

        *str1++ = *str2++;

    }

//   *str1 = '\0';
}

//     *str1 = '\0';     need of this.
// 5.7 check

void str_cat(){

    char str1[1000];
    char str2[1000];

    printf("Enter first string : ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string : ");
    fgets(str2, sizeof(str2), stdin);

    strcat_without_library(str1,str2);

    printf("Resulted string is : %s\n", str1);
}

