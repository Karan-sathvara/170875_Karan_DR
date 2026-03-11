/*
* File Name     : 170875_Karan_DR_Module4-7.c
* Description   : Write a routine ungets(s),
*                - that will push back an entire string onto the input.
*                - Should ungets know about buf and bufp, or should it just use ungetch?
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUMBER '0'
#define MAXVAL 100

/*
* Function Name : getch
* Description   : this function will take one character from buffer and see
*               - if something pushed back then return that otherwise read from stdin
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void){

    return (bufp > 0) ? buf[--bufp] : getchar();
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
* Function Name : string_using_ungets
* Description   : this will push back an entire string onto the input
* Expected input: hiii karan
* Expected output: hiii karan
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

void string_using_ungets(){

    int8_t c;
    void ungets(char []);
    void push(char);
    char pop(void);
    char s[100];
    char total[100];

    printf("Press CTRL + D to exit..\n");
    printf("Enter string : ");
    while(fgets(s, 100, stdin) != NULL){
	strcat(total,s);
    }
    ungets(total);
    while((c = getch()) != EOF){
	printf("%c",c);
    }
    printf("\n");
}



