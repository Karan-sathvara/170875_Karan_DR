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
    IN_DOUBLE_COMMENT
} state;

void push(char stack[], int *top, char ch){
    if(*top == MAX-1){
        printf("stack overflow\n");
        return;
    }
    stack[++(*top)] = ch;
}

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


void check_syntax_errors(){

    char stack[MAX];
    int top = -1;

    int16_t ch;
    int16_t next;
    int16_t prev = 0;

    state current_state = NORMAL;

    while ((ch = getchar()) != EOF){

        switch(current_state){

        case NORMAL:

            if (ch == '/'){
                next = getchar();

                if(next == '/'){
                    current_state = IN_SINGLE_COMMENT;
                    break;
                }
                else if(next == '*'){
                    current_state = IN_DOUBLE_COMMENT;
                    break;
                }
                else{
                    ungetc(next, stdin);
                }
            }

            else if(ch == '"'){
                current_state = IN_DOUBLE_QUOTE;
                break;
            }

            else if(ch == '\''){
                current_state = IN_SINGLE_QUOTE;
                break;
            }

            if (ch == '(' || ch == '{' || ch == '['){
                push(stack, &top, ch);
            }
            else if(ch == ')' || ch == '}' || ch == ']'){
                char open = pop(stack, &top);

                if(!isMatching(open, ch)){
                    printf("Syntax error: mismatched %c\n", ch);
                    return;
                }
            }

            break;


        case IN_SINGLE_COMMENT:

            if(ch == '\n'){
                current_state = NORMAL;
            }
            break;


        case IN_DOUBLE_COMMENT:

            if(prev == '*' && ch == '/'){
                current_state = NORMAL;
            }
            break;


        case IN_DOUBLE_QUOTE:

            if(ch == '"' && prev != '\\'){
                current_state = NORMAL;
            }
            break;


        case IN_SINGLE_QUOTE:

            if(ch == '\'' && prev != '\\'){
                current_state = NORMAL;
            }
            break;
        }

        prev = ch;
    }

    if(top != -1){
        printf("Syntax error: unmatched opening bracket\n");
    }
    else{
        printf("No syntax errors\n");
    }
}
