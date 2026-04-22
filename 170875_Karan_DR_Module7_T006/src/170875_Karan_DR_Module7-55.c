/*
* File Name     : 170875_Karan_DR_Module7-5_V2.c
* Description   : Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do the input and number conversion.
*		: The postfix calculator evaluates expressions in Reverse Polish Notation (RPN) with newline
* Author        : Karan Sathvara
* Created       : 21-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>

#define MAXVAL 100

int8_t sp = 0;
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

double pop(void){
    if (sp > 0)
        return stack[--sp];
    else {
        printf("stack is empty\n");
        return 0;
    }
}


// sscanf = string scan formatted

void RPN_interactive()
{
    char line[1000], token[100];
    double num, op2;

    printf("Enter RPN Expression:\n");

    while (fgets(line, sizeof(line), stdin) != NULL) {

        int pos = 0;
        sp = 0;

        while (sscanf(line + pos, "%s", token) == 1) {

            if (sscanf(token, "%lf", &num) == 1) {
                push(num);
            }
            else {
                switch (token[0]) {
                    case '+': push(pop() + pop()); break;
                    case '*': push(pop() * pop()); break;
                    case '-': op2 = pop(); push(pop() - op2); break;
                    case '/':
                        op2 = pop();
                        if (op2 != 0)
                            push(pop() / op2);
                        else {
                            printf("zero divisor\n");
                            break;
                        }
                        break;
		    default :
			printf("Invalid Input\n");
                }
            }

            pos += strlen(token);
            while (line[pos] == ' ') pos++;
        }

        if (sp > 0)
            printf("Result = %.2f\n", pop());
    }
}
