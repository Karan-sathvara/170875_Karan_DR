/*
* File Name     : 170875_Karan_DR_Module4-10.c
* Description   : An alternate organization uses getline to read an entire input line;
*               - this makes getch and ungetch unnecessary.
*               - Revise the calculator to use this approach
* Author        : Karan Sathvara
* Created       : saturday
*/

#include <stdio.h>
#include "header.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINE 100
#define MAXVAL 100

int sp = 0;
double stack[MAXVAL];

/*
* Function Name : push
* Description   : this function push value to stack
* Author        : Karan Sathvara
* Created       : saturday
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
* Created       : saturday
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
* Function Name : getline
* Description   : this will read an entire input line
* Author        : Karan Sathvara
* Created       : saturday
*/

int mygetline(char line[], int lim){
    int c, i = 0;

    while(i < lim-1 && (c = getchar()) != EOF && c != '\n'){
        line[i++] = c;
    }

    line[i] = '\0';
    return i;
}

/*
* Function Name : revised_calculator_using_getline
* Description   : this function will perform operations using string
* Expected input: 10 20 +
* Expected output: 30
* Author        : Karan Sathvara
* Created       : saturday
*/

void revised_calculator_using_getline(){

    char line[MAXLINE];
    int i;
    double op2;

    printf("Enter RPN expression: ");

    while(mygetline(line, MAXLINE) > 0){
        i = 0;

        while(line[i] != '\0'){

            if(line[i] == ' '){
                i++;
                continue;
            }

            if(isdigit(line[i]) || (line[i] == '-' && isdigit(line[i+1]))){

		int sign = 1;

		if(line[i] == '-'){
		    sign = -1;
		    i++;
		}

                double num = 0;

                while(isdigit(line[i])){
                    num = num * 10 + (line[i] - '0');
                    i++;
                }

                push(sign * num);
                continue;
            }
            switch(line[i]){
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
                    push(pop() / op2);
                    break;

                case '%':
                    op2 = pop();
		    if(op2 != 0){
                        push((int)pop() % (int)op2);
            	    }
		    else{
			printf("zero divisor\n");
		    }
		    break;
		}
            i++;
        }

        printf("Result: %.8g\n", pop());
    }
}
