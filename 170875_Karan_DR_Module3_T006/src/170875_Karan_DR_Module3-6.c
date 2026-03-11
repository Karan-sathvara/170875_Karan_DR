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
#include "function.h"

/*
* Function Name : itoa_space
* Description   : This function converts integer to string
* input 1       : 12345
* input 2       : width = 10
* output        : *****12345
* Author        : Karan Sathvara
* Created       : 27-02-2026
*/

void itoa_space(int16_t digit, char str[], int8_t width){

    int16_t index = 0;
    int16_t integer = 0;
    int16_t sign = digit;
    int16_t len_digit = 0;

    if(digit < 0)
        digit = -digit;

    do {
        str[integer++] = (digit % 10) + '0';
        digit = digit / 10;
    } while(digit > 0);

    if(sign < 0)
        str[integer++] = '-';

    str[integer] = '\0';

    reverse(str);

    /* adding spaces */

    len_digit = strlen(str);

    if(width > len_digit) {
        int16_t spaces = width - len_digit;

        for(index = len_digit; index >= 0; index--){
            str[index + spaces] = str[index];
	}

        for(index = 0; index < spaces; index++){
            str[index] = '*';
	}
    }

}

/*
* Function Name : itoa
* Description   : This function converts integer to string
* input         : 123
* output        : "123"
* Author        : Karan Sathvara
* Created       : 27-02-2026
*/

void itoa(){

    int8_t width;
    int16_t digit;
    char str[50];

    printf("Enter digit : ");
    scanf("%hd", &digit);

    printf("Enter minimum field width : ");
    scanf("%hhd", &width);

    itoa_space(digit, str, width);
    printf("String is: %s\n", str);
}




