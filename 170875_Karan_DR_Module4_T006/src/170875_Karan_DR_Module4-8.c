/*
* File Name     : 170875_Karan_DR_Module4-8.c
* Description   : Suppose that there will never be more than one character of pushback.
*               - Modify getch and ungetch accordingly.
* Author        : Karan Sathvara
* Created       : 00-03-2026
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
double stack[MAXVAL];

/*
* Function Name : push
* Description   : this function push value to stack
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

void push(double f){
    if (sp < MAXVAL){
        stack[sp++] = f;
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
* Created       : 06-03-2026
*/

double pop(void){
    if (sp > 0)
        return stack[--sp];
    else {
        printf("stack empty\n");
        return 0.0;
    }
}

/*
* Function Name : getch (modified) - will only use one variable named buf
* Description   : this function will take one character from buffer and see
*               - if something pushed back then return that otherwise read from stdin
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

int8_t buf = EOF;

int getch(void){
    int8_t c;
    if (buf != EOF){
	c = buf;
	buf = EOF;
        return c;
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
    if (buf != EOF){
        printf("ungetch: buffer is full\n");
	return;
    }
    else{
        buf = c;
    }
}

/*
* Function Name : getop
* Description   : this function will decide that input is number or an operator
*               - if it is number then take care of positive negative and floating number
*               - if it is operator it will perform operation from main
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

int getop(char s[])
{
    int i, c;

    /* skip white space */
    while ((c = getch()) == ' ' || c == '\t');

    s[0] = c;
    s[1] = '\0';

    /* collect first digit */
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
* Function Name : modified_getch
* Description   : this function will give output as input
* Expected input: 12 3 +
* Expected output: 15
* Author        : Karan Sathvara
* Created       : 06-03-2026
*/

void modified_getch(){

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
	    printf("unknown command %s\n", s);
	    return;
	    break;
        }
    }
}


