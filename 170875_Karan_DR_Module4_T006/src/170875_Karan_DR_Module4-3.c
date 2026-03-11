/*
* File Name     : 170875_Karan_DR_Module4-3.c
* Description   : Given the basic framework,
*                -   it's straightforward to extend the calculator.
*                - Add the modulus (%) operator and provisions for negative numbers.
* Author        : Karan Sathvara
* Created       : 03-03-2026
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
* Created       : 03-03-2026
*/

void push(double f){
    if (sp < MAXVAL){
        val[sp++] = f;
    }
    else{
        printf("stack full, can't push %g\n", f);
	return;
    }
}

/*
* Function Name : pop
* Description   : this function return top value from stack
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf("stack empty\n");
        return 0.0;
    }
}

/*
* Function Name : getch
* Description   : this function will take one character from buffer and see
*		- if something pushed back then return that otherwise read from stdin
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
*		- if it is number then take care of positive negative and floating number
*		- if it is operator it will perform operation from main
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

    while (isdigit(c = getch())){
	s[i++] = c;
    }

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
* Function Name : reverse_Polish_calculator
* Description   : this function will perform operations
* Expected input: 10 20 +
* Expected output: 30
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

void reverse_Polish_calculator(){

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


