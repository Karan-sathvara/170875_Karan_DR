/*
* File Name     : 170875_Karan_DR_Module5-4.c
* Description   : Write a Function strend
*                - which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
* Author        : Karan Sathvara
* Created       : 30-03-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>

/*
* Function Name : strend
* Description   : this function finds if string 2 occurs at string 1's end or not
* Input string1 : Karan
* Input string2 : ran
* Output        : 1 or substring occurs
* Author        : Karan Sathvara
* Created       : 30-03-2026
*/

void strend(char *str1,char *str2){

    char *ptr1 = str1;
    char *ptr2 = str2;

    while(*ptr1 != '\0'){
	ptr1++;
    }

    while(*ptr2 != '\0'){
        ptr2++;
    }

    while(ptr2 > str2){
	ptr1--;
	ptr2--;

	if(*ptr1 != *ptr2){
	    printf("String 2 does not occurs at end of String 1\n");
	    return;
	}
    }
    printf("String 2 occurs at end of String 1\n");
}

/*
* Function Name : str_end
* Description   : this function takes input strings from user
* Author        : Karan Sathvara
* Created       : 30-03-2026
*/

void str_end(){

    char str1[1000];
    char str2[1000];

    printf("Enter first string : ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string : ");
    fgets(str2, sizeof(str2), stdin);

    str1[strlen(str1)-1] = '\0';
    str2[strlen(str2)-1] = '\0';

    if(strlen(str2) > strlen(str1)){
        printf("can not find substring\n");
	return;
    }

    strend(str1, str2);

}

