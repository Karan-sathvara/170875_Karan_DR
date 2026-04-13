/*
* File Name     : 170875_Karan_DR_Module3-6.c
* Description   : Write a version of itoa that accepts three arguments instead of two.
*                - The third argument is a minimum field width
*                - the converted number must be padded with blanks on the left if necessary to make it wide enough.
* Author        : Karan Sathvara
* Created       : 27-02-2026
*/


#include <stdio.h>
#include "header.h"
#include <stdint.h>
#include <string.h>


void Module3Task8(){

    int8_t index=0;
    int8_t width;
    char digit[50];
    int8_t len_digit=0;

    printf("Enter digit : ");
    scanf("%s", digit);

    printf("Enter minimum field width : ");
    scanf("%hhd", &width);

    len_digit = strlen(digit);

//    printf("Length of digit : %hhd\n", len_digit);

    if(width > len_digit){

        printf("Padded String: ");

        int8_t space = width - len_digit;

        for(index=0; index < space; index++){
            printf("*");
        }
        printf("%s\n", digit);
    }
    else{
        printf("String is: %s\n", digit);
    }
}
