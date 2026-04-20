/*
* File Name     : 170875_Karan_DR_Module5-1.c
* Description   : Write a Function getint
* 		 - getint treats a + or - not followed by a digit as a valid representation of zero.
*                - Fix it to push such a character back on the input.
* Author        : Karan Sathvara
* Created       : 27-03-2026
*/

#include <stdio.h>
#include "header.h"
#include <ctype.h>
#include "function.h"

/*
* Function Name : getint_fun
* Description   : this function validate user input and take only integer as input
* Author        : Karan Sathvara
* Created       : 27-03-2026
*/

void getint_fun(int16_t *num){

    int16_t ch;
    int16_t next;
    int8_t sign;

    printf("Enter Input : ");

    while(isspace(ch = getch()));

    if (!isdigit(ch) && ch != EOF && ch != '+' && ch != '-') {
	ungetch(ch);
        printf("Not valid input\n");
        return;
    }

    if (ch == '-'){
	sign = -1;
    }
    else{
	sign = 1;
    }

    if (ch == '+' || ch == '-'){
        next = getch();

	if(!isdigit(next)){
	    printf("Not valid input\n");

	    ungetch(next);
	    ungetch(ch);

	    return;
	}
    ch = next;
    }

    while (isdigit(ch)){
        int16_t digit = ch - '0';
        *num = (*num * 10) + digit;
        ch = getch();
    }

    if(ch != EOF && !isspace(ch)){
	printf("Not valid input\n");
	return;
    }

    *num = *num * sign;

    if (ch != EOF){
        ungetch(ch);
    }

    printf("Output : %d\n", *num);
}

/*
* Function Name : getint
* Description   : this function pass int arg to another function
* Author        : Karan Sathvara
* Created       : 27-03-2026
*/

void getint(){

    int16_t num = 0;
    getint_fun(&num);

}
