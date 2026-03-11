/*
* File Name     : 170875_Karan_DR_Module2-10.c
* Description   :  Rewrite the function lower
*                - which converts upper case letters to lower case, with a conditional expression instead of if-else.
* Author        : Karan Sathvara
* Created       : 20-02-2026
*/

#include <stdio.h>
#include "header.h"


void lower(){

    char str[100];

/*    int16_t ch;

    while((ch = getchar()) != EOF){

        (ch >= 'A'  && ch <= 'Z')? putchar(ch + 'a' - 'A'):putchar(ch);
    }
*/
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
	for(int i = 0; str[i] != '\0'; i++){
	    str[i] = (str[i] >= 'A'  && str[i] <= 'Z')? (str[i] + 'a' - 'A'): (str[i]);
	}

	printf("string is: %s\n", str);
}

