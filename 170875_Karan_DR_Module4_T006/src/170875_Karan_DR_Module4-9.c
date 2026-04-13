/*
* File Name     : 170875_Karan_DR_Module4-9.c
* Description   : Our getch and ungetch do not handle a pushed-back EOF correctly.
*               - Decide what their properties ought to be if an EOF is pushed back, then implement your design.
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>
#include <ctype.h>
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
* Function Name : ungets
* Description   : will push back an entire string onto the input
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

void ungets(char s[]){

    int16_t i;
    for (i = strlen(s) - 1; i >= 0; i--) {
        ungetch(s[i]);
    }
}

/*
* Function Name : eof_efficient
* Description   : this will push back an entire string onto the input
* Expected input: hiii karan CTRL + D
* Expected output: hiii karan EOF encountered
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

void eof_efficient(){

    void ungets(char []);
    void ungetch(int c);
    int getch(void);
    char s[100];
    char total[100];
    int8_t c;

    printf("Enter string : ");
    while(fgets(s, 100, stdin) != NULL){
        for(int8_t i=0; s[i] != '\0'; i++){
            c = s[0];
        }
        strcat(total,s);
    }
    ungets(total);
    while((c = getch()) != EOF){
	printf("%c", c);
    }
    if(c == EOF){
	printf("EOF is Encountered\n");
	return;
    }
    printf("\n");
}





