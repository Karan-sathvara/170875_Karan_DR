/*
* File Name     : 170875_Karan_DR_Module7-5.c
* Description   : Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do the input and number conversion.
*		: The postfix calculator evaluates expressions in Reverse Polish Notation (RPN)
* Author        : Karan Sathvara
* Created       : 21-04-2026
*/

#include <stdio.h>
#include "header.h"
#include "function.h"

/*
* Function Name : RPN_using_scanf
* Description   : this function will perform RPN calculator using scanf and sscanf
*               : scanf : takes input from user
                : sscanf (string scan formatted) : will convert string into double and it success then it will be stored in stack
* Author        : Karan Sathvara
* Created       : 21-04-2026
*/

void RPN_using_scanf(){

    double op2, num;
    char token[100];

    printf("Enter RPN Expression : ");
    while (scanf("%s", token) != EOF){

        if (sscanf(token, "%lf", &num) == 1){
            push(num);
        }
        else
	{
            switch (token[0]) {

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
                    if (op2 != 0){
                        push(pop() / op2);
		    }
		    else{
                        printf("zero divisor\n");
                        return;
                    }
                    break;

		case '%':
                    op2 = pop();
                    if (op2 != 0.0){
                        push((int)pop() % (int)op2);
		    }
                    else{
                        printf("zero divisor\n");
                	return;
		    }
		    break;

                default:
                    printf("Invalid input : %s\n", token);
                    return;
            }
        }
    }
    printf("Result = %.2f\n", pop());
}
