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
#include <ctype.h>

void strindex(){

    char str1[100];
    char str2[100];
    int8_t len1;
    int8_t len2;
    int16_t idxi;
    int16_t idxj;

    printf("Enter input string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter character to find: ");
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1 , "\n")] = '\0';
    str2[strcspn(str2 , "\n")] = '\0';

    len1 = strlen(str1);
    len2 = strlen(str2);

    for(idxi = len1 - len2; idxi >= 0; idxi--){
	    for(idxj = 0; idxj < len2; idxj++){
	        if(tolower(str1[idxi + idxj]) != tolower(str2[idxj])){
	            break;
	        }
	    }
	    if(idxj == len2){
		printf("substring %s found at index: %d\n",str2 , len1 - idxi);
	        return;
	    }
    }
    printf("No substring found\n");
}
