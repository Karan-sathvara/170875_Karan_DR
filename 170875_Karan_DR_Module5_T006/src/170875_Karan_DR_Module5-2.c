/*
* File Name     : 170875_Karan_DR_Module5-2.c
* Description   : Write a Function getfloat
* 		 - the floating-point analog of getint.
*                - What type does getfloat return as its function value?
* Author        : Karan Sathvara
* Created       : 27-03-2026
*/

#include <stdio.h>
#include "header.h"
#include <ctype.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

void ungetch(int c)
{
    if (bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
        return;
    }
    else{
        buf[bufp++] = c;
    }
}


int getch(void){
    if(bufp > 0){
        return buf[--bufp];
    }
    else{
        return getchar();
    }
}

void getfloat_fun(double *num){

    double ch;
    double next;
    int8_t sign;

    printf("Enter Input : ");

    while(isspace(ch = getch()));

    if (!isdigit(ch) && ch != EOF && ch != '+' && ch != '-') {
	ungetch(ch);
        printf("Not a number\n");
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

	if(!isdigit(next) && next != '.'){
	    printf("Not valid input\n");

	    ungetch(next);
	    ungetch(ch);

	    return;
	}
    ch = next;
    }

    while (isdigit(ch)){
        int8_t digit = ch - '0';
        *num = (*num * 10) + digit;
        ch = getch();
    }

    if (ch == '.') {
        float power = 1.0;
        ch = getch();

        while (isdigit(ch)) {
            *num = (*num * 10) + (ch - '0');
            power = power * 10;
            ch = getch();
        }

        *num = *num / power;
    }

    if(ch != EOF && !isspace(ch)){
	printf("Invalid input\n");
	return;
    }

    *num = *num * sign;

    if (ch != EOF){
        ungetch(ch);
    }

    printf("Output : %lf\n", *num);
}

void getfloat(){

    double num = 0;
    getfloat_fun(&num);

}
