/*
* File Name     : 170875_Karan_DR_Module4-11.c
* Description   : Modify getop so that it doesn't need to use ungetch.
*               - Hint: use an internal static variable.
* Author        : Karan Sathvara
* Created       : saturday
*/

#include <stdio.h>
#include "header.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];


/*
* Function Name : push
* Description   : this function push values on stack
* Author        : Karan Sathvara
* Created       : saturday
*/

void push(double f){
    if (sp < MAXVAL){
        val[sp++] = f;
    }
    else{
        printf("stack is full\n");
	return;
    }
}

/*
* Function Name : pop
* Description   : this function return top value from stack
* Author        : Karan Sathvara
* Created       : saturday
*/

double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf("stack is empty\n");
        return 0;
    }
}

/*
* Function Name : getop
* Description   :
*		-
*		- if it is operator it will perform operation from main.
* Author        : Karan Sathvara
* Created       : saturday
*/

int getop(char s[])
{
    int i, c;
    static int buf = EOF;

    if (buf != EOF) {
        c = buf;
        buf = EOF;
    } else {
        c = getchar();
    }

    while ((c == ' ' || c == '\t'))
	c = getchar();

    s[0] = c;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    i = 0;

    if (c == '-') {
        int next = getchar();

        if (!isdigit(next) && next != '.') {
            buf = next;
            return '-';
        }

        s[i++] = c;
        c = next;
    }

    /* store first digit */
    if (isdigit(c)){
        s[i++] = c;
        while (isdigit(c = getchar()))
            s[i++] = c;
    }

    if (c == '.'){
        s[i++] = c;
        while (isdigit(c = getchar()))
            s[i++] = c;
    }

    s[i] = '\0';

    if (c != EOF){
	buf = c;
    }
    return NUMBER;
}

/*
* Function Name : reverse_Polish_calculator
* Description   : this function will perform operations
* Expected input: 10 20 +
* Expected output: 30
* Author        : Karan Sathvara
* Created       : saturday
*/

void modified_getop(){

    int getop(char []);
    void push(double);
    double pop(void);

    int type;
    double op2;
    char s[MAXOP];

    printf("Press CTRL + D to exit..\n");
    printf("Enter digits for operation : ");
    while ((type = getop(s)) != EOF) {

	switch (type) {
	case NUMBER:
	    push(atof(s));
	    break;

	case '+':
	    push(pop() + pop());
	    break;

	case '*':
	    push(pop() * pop());
	    break;

	case '-':
 	    op2 = pop();
	    push(pop() - op2);
	    break;

	case '/':
	    op2 = pop();
	    if (op2 != 0.0)
	    push(pop() / op2);

	else
	    printf("zero divisor\n");
	break;

	case '%':
    	    op2 = pop();
    	    if (op2 != 0.0)
            push((int)pop() % (int)op2);

    	else
            printf("zero divisor\n");
    	break;

	case '\n':
	    printf("Result : %.8g\n", pop());
	    break;

	default:
	    printf("Unknown command %s\n", s);
	    return;
	    break;
        }
    }
}


