/*
* File Name     : 170875_Karan_DR_Module4-5.c
* Description   : Add access to library functions like sin, exp, and pow.
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

int sp = 0;
double stack[MAXVAL];

/*
* Function Name : push
* Description   : this function push values on stack
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

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
* Function Name : pop
* Description   : this function return top value from stack
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

double pop(){
    if(sp == 0){
        printf("Stack empty\n");
        return 0;
    }
    return stack[--sp];
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
* Function Name : sin_exp_pow_stack
* Description   : this function will perform operations
*                 s : sine of element
*                 e : exponent of element
*                 p : power of top 2 elements
* Expected input: 2 3 p
* Expected output: 8
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

void sin_exp_pow_stack(){

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

        case 's':
	    if(sp > 0){
		double temp1 = pop();
		double sine = sin(temp1);
		push(sine);
	    }
	    break;

        case 'e':
            if(sp > 0){
		double temp2 = pop();
		push(exp(temp2));
	    }
            break;

	case 'p':
	    if(sp >= 2){
		double exponent = pop();
		double base = pop();
		push(pow(base, exponent));
	    }
	    break;

        case '\n':
    	    printf("stack : ");
		for(int i = sp-1; i >= 0; i--){
	            printf("%.5f ", stack[i]);
    	        }
	    printf("\n");
            return;

        default:
            printf("Unknown command %c\n", type);
            return;
        }
    }
}
