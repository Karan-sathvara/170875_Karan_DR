/*
* File Name     : 170875_Karan_DR_Module4-13.c
* Description   : Write a recursive version of the function reverse(s),
*		- which reverses the string s in place.
* Author        : Karan Sathvara
* Created       : 09-03-2026
*/


#include <stdio.h>
#include "header.h"
#include <string.h>

/*
* Function Name : reverse
* Description   : this function will reverse string recursively
* Expected input: Karan
* Expected output: naraK
* Author        : Karan Sathvara
* Created       : 09-03-2026
*/

void reverse(char *input, int8_t start, int8_t end){

    if(start >= end){
	return;
    }

    char temp = input[start];
    input[start] = input[end];
    input[end] = temp;
    reverse(input, start + 1, end - 1);
}

/*
* Function Name : reverse_recursively
* Description   : this function will reverse string recursively
* Expected input: Karan
* Expected output: narak
* Author        : Karan Sathvara
* Created       : 09-03-2026
*/

void reverse_recursively(){

    char input[100];
    int8_t len;

    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    len = strlen(input);

    int8_t start = 0;
    int8_t end = len - 1;

    reverse(input, start, end);

    printf("output string: %s\n", input);
}
