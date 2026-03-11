/*
* File Name     : 170875_Karan_DR_Module1-24.c
* Description   : Write a program
*                 - for rudimentary syntax errors
*                   like unmatched parentheses, brackets and braces.
*                   Don't forget about quotes, both single and double, escape sequences, and comments.
* Author        : Karan Sathvara
* Created       : 13-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"

#define MAX 100

typedef enum{

    NORMAL,
    IN_SINGLE_QUOTE,
    IN_DOUBLE_QUOTE,
    IN_SINGLE_COMMENT,
    IN_MULTI_COMMENT

} state;

    /* puts an item on top */
    void push(char stack[], int *top, char ch){

        if(*top == MAX-1){
            printf("stack overflow\n");
            return;
        }

        stack[++(*top)] = ch;
    }

    /* remove the top item */
    char pop(char stack[], int *top){
        if(*top == -1)
	    return '\0';
        return stack[(*top)--];

    }

int isMatching(char open, char close){

    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


//void Module1Task24(){

    char stack[MAX];
    int top = -1;
    int ch;
    int next;
    int prev = 0;
    state current_state = NORMAL;

    while ((ch = getchar()) != EOF){
	if(current_state == NORMAL){

	    if (ch == '/'){
		next = getchar();
                if (next == EOF){
                    putchar(ch);
                    break;
                }
	        if(next == '/'){
	            current_state = IN_SINGLE_COMMENT;
		    continue;
	        }

                else if(next == '*'){
        	    current_state = IN_MULTI_COMMENT;
	            continue;
		}

    	        else{
	        /* put charcter back into input stream */
		    ungetc(next, stdin);
	        }
	    }
	}
	else if(ch == '"'){
    	    current_state = IN_DOUBLE_QUOTE;
	    continue;
	}

	else if(ch == '\''){
    	    current_state = IN_SINGLE_QUOTE;
	    continue;
	}

	if (ch == '(' || ch == '{' || ch == '['){
	    push(stack, &top, ch);
	}

	else if(ch == ')' || ch == '}' || ch == ']'){
	    char open = pop(stack, &top);

	    if(!isMatching(open, ch)){
		printf("syntax error: mismatched %c\n", ch);
	        return;
	    }
	}
	    else if(current_state == IN_SINGLE_COMMENT){


                if(ch == '\n'){
                putchar('\n');
                current_state = NORMAL;
                }
        }
	}
        	else if(current_state == IN_MULTI_COMMENT){

            	    if(prev == '*' && ch == '/'){
                    current_state = NORMAL;
                    prev = 0;
                    continue;
            	    }
        	}

        else if(current_state == IN_DOUBLE_QUOTE){

            putchar(ch);

            if(ch == '"' && prev != '\\'){
                current_state = NORMAL;
            }
        }

        else if(current_state == IN_SINGLE_QUOTE){

            putchar(ch);

            if(ch == '\'' && prev != '\\'){
                current_state = NORMAL;
            }
        }
	prev = ch;
    }

    if(top != -1){
        printf("Syntax error: unmatched opening bracket\n");
    }
    else{
        printf("No syntax errors ✅\n");
    }
}
