/*
* File Name     : 170875_Karan_DR_Module4-4.c
* Description   : Add the commands to print the top elements of the stack without popping,
*                -  to duplicate it, and to swap the top two elements
*                - Add a command to clear the stack.
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

/*
* Function Name : push
* Description   : this function push values on stack
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

int sp = 0;
double stack[MAXVAL];

void push(double f){
    if (sp < MAXVAL){
        stack[sp++] = f;
    }
    else{
        printf("stack is full\n");
        return;
    }
}

/*
* Function Name : getch
* Description   : this function will take one character from buffer and see
*               - if something pushed back then return that otherwise read from stdin
* Author        : Karan Sathvara
* Created       : 03-03-2026
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
* Created       : 03-03-2026
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
* Function Name : getop
* Description   : this function will decide that input is number or an operator
*               - if it is number then take care of positive negative and floating number
*               - if it is operator it will perform operation from main
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

int getop(char s[])
{
    int i, c;

    while ((c = getch()) == ' ' || c == '\t');

    s[0] = c;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    i = 0;

    /* handle minus sign */
    if (c == '-') {
        int next = getch();
        if (!isdigit(next) && next != '.') {
            ungetch(next);
            return '-';
        }
        s[i++] = c;
        c = next;
    }

    /* store first digit */
    if (isdigit(c) || c == '.'){
        s[i++] = c;
    }

    /* collect remaining integer part */
    while (isdigit(c = getch())){
        s[i++] = c;
    }

    /* collect fraction part */
    if (c == '.'){
        s[i++] = c;
        while (isdigit(c = getch()))
            s[i++] = c;
    }

    s[i] = '\0';

    if (c != EOF){
        ungetch(c);
    }
    return NUMBER;
}


/*
* Function Name : duplicate_swap_clear_stack
* Description   : this function will perform operations
*		  d : duplicate element
*                 s : swap top 2 element
*                 c : clear stack
*                 p : print top element of stack
* Expected input: 10 20 d
* Expected output: 20 20 10
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

void duplicate_swap_clear_stack(){

    int getop(char []);
    void push(double);
    int type;
    char s[MAXOP];

    printf("Press CTRL + D to exit..\n");
    printf("Enter digits for operation : ");
    while ((type = getop(s)) != EOF) {

        switch (type) {
        case NUMBER:
            push(atof(s));
            break;

        case 'd':
            if(sp > 0){
                double value = stack[sp-1];
                push(value);
            }
            break;

        case 'c':
            sp = 0;
	    printf("stack is empty\n");
            break;

	case 'p':
	    if(sp > 0){
		int8_t count;
		if(getop(s) == NUMBER){
		    count = atof(s);
		}
		else{
		    count = 1;
		}
                if(count > sp){
                    printf("stack is not that big.\n");
                    break;
		}

		for(int i = sp-1; i >= sp-count; i--){
		    printf("Top: %.2f\n", stack[i]);
		}
	    }
	    break;

        case '\n':
    	    printf("stack : ");
		for(int i = sp-1; i >= 0; i--){
	            printf("%.2f ", stack[i]);
    	        }
	    printf("\n");
            return;

        default:
            printf("Invalid choice\n");
            return;
        }
    }
}
