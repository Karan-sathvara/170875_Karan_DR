/*
* File Name     : 170875_Karan_DR_Module4-8.c
* Description   : Our getch and ungetch do not handle a pushed-back EOF correctly.
*               - Decide what their properties ought to be if an EOF is pushed back, then implement your design.
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

#include <stdio.h>
#include "header.h"
#include <stdlib.h>

/*
* Function Name : getch (modified) - will able to handle EOF because of int buf[]
* Description   : EOF value is -1 which is handle by int
*               - if something pushed back then return that otherwise read from stdin
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void){

    if (bufp > 0){
	return buf[--bufp];
    }
    else{
        return getchar();
    }
}

/*
* Function Name : ungetch
* Description   : this function will put one character into buffer
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

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

/*
* Function Name : eof_efficient
* Description   : this will push back an entire string onto the input
* Expected input: hiii karan CTRL + D
* Expected output: hiii karan
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

void modified_getch(){

    char s[100];
    int16_t c;
    int16_t i = 0;

    printf("Enter string : ");
    while((c = getch()) != EOF){
	s[i++] = c;
    }
    s[i] = '\0';

    printf("%s\n", s);
}





