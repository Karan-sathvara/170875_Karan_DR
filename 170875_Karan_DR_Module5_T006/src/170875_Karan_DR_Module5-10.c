/*
* File Name     : 170875_Karan_DR_Module5-10.c
* Description   : RPN using CLI
* Author        : Karan Sathvara
* Created       : 01-04-2026
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
* Description   : this function push one char on stack
* Author        : Karan Sathvara
* Created       : 31-03-2026
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

int stack_size() {
    return sp;
}

double pop(void){
    if (sp > 0)
        return stack[--sp];
    else {
        printf("stack is empty\n");
        return 0;
    }
}

/*
* Function Name : RPN_using_CLI
* Description   : This function perfoms RPN calculation using command line args
* Author        : Karan Sathvara
* Created       : 01-04-2026
*/

void RPN_using_CLI(int8_t argc, char *argv[]) {

    void push(double);
    double pop(void);

    double op2;
    for (int8_t i = 1; i < argc; i++) {

/*
        if (isdigit(argv[i][0]) || (argv[i][0] == '-' && isdigit(argv[i][1]))) {

            push(atof(argv[i]));
        }
*/

	char *end;
	double val = strtod(argv[i], &end);

	if (end != argv[i] && *end == '\0') {
    	    push(val);
	}
        else {

            switch (argv[i][0]) {

            case '+':
    		if (stack_size() < 2) {
        	    printf("insufficient operands for operator '+'\n");
        	    return;
    		}
                push(pop() + pop());
                break;

            case '*':
                if (stack_size() < 2) {
                    printf("insufficient operands for operator '*'\n");
                    return;
                }
		push(pop() * pop());
                break;

            case '-':
                if (stack_size() < 2) {
                    printf("insufficient operands for operator '-'\n");
                    return;
                }
                op2 = pop();
                push(pop() - op2);
                break;

            case '/':
                if (stack_size() < 2) {
                    printf("insufficient operands for operator '/'\n");
                    return;
                }
                op2 = pop();
                if (op2 != 0.0){
                    push(pop() / op2);
		}
                else{
                    printf("zero divisor\n");
		    return;
		}
                break;

            case '%':
                if (stack_size() < 2) {
                    printf("insufficient operands for operator '%%'\n");
                    return;
                }
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("zero divisor\n");
                break;

            default:
                printf("Invalid input : %s\n", argv[i]);
                return;
            }
        }
    }
    if (stack_size() > 1) {
        printf("operands are remaining\n");
    }
    else if (stack_size() == 1) {
        printf("Result : %.8g\n", pop());
    }
}
