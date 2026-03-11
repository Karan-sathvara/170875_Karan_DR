/*
* File Name     : 170875_Karan_DR_Module4-6.c
* Description   : Add commands for handling variables.
*		- (It's easy to provide twenty-six variables with single-letter names.)
*               - Add a variable for the most recently printed value.
* Author        : Karan Sathvara
* Created       : 00-03-2026
*/

#include <stdio.h>
#include "header.h"
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

double stack[MAXVAL];
int sp = 0;

/*
* Function Name : push
* Description   : this function push values on stack
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

void push(double num){
    if(sp < MAXVAL){
        stack[sp++] = num;
    }
    else{
        printf("stack is full\n");
    }
}

/*
* Function Name : pop
* Description   : this function return top value from stack
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

double pop(void){
    if(sp == 0){
        printf("Stack empty\n");
        return 0.0;
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

    return (bufp > 0)? buf[--bufp] : getchar();
}

/*
* Function Name : ungetch
* Description   : this function will put one character into buffer
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

void ungetch(int c){

    if(bufp > BUFSIZE){
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

int getop(char s[]){

    int8_t index;
    int c;

    /* skip white space */
    while ((c = getch()) == ' ' || c == '\t');

    s[0] = c;
    s[1] = '\0';


    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    index = 0;

    if (isupper(c)){
        return c;
    }

    /* handle minus sign */
    if (c == '-') {
        int next = getch();
        if (!isdigit(next) && next != '.') {
            ungetch(next);
            return '-';
        }
        s[index++] = c;
        c = next;
    }

    /* store first digit */
    if (isdigit(c) || c == '.'){
        s[index++] = c;
    }

    /* collect remaining integer part */
    while (isdigit(c = getch())){
        s[index++] = c;
    }

    /* collect fraction part */
    if (c == '.'){
        s[index++] = c;
        while (isdigit(c = getch()))
            s[index++] = c;
    }
    s[index] = '\0';

    if (c != EOF){
        ungetch(c);
    }
    return NUMBER;

}

/*
* Function Name : assign_value_to_characters
* Description   : this function will perform operations
* Expected input: 2 A = , 3 B = will be A = 2, B = 3 , A B +
* Expected output: 5
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

void assign_value_to_characters(){

    int getop(char s[]);
    void push(double);
    double pop(void);

    double alpha[26] = {0};
    int var = -1;
    int type;
    double op2;
    char s[MAXOP];

    printf("\nEnter CTRL + D to exit\n");
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

        case '=':
	    pop();
	    double value = pop();
            alpha[var] = value;
            push(value);
	    break;


	case 'l':
	    printf("Last stored variable is %.2lf\n", value);
	    return;

        case '\n':
	    value = pop();
            printf("result: %.8g\n", value);
	    break;

        default:
            if(type >= 'A' && type <= 'Z'){
                var = type - 'A';
            	push(alpha[var]);
            }
	}
    }
}
