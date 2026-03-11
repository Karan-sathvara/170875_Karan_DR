/*
* File Name     : 170875_Karan_DR_Module4-4.c
* Description   : Add the commands to print the top elements of the stack without popping,
*                -  to duplicate it, and to swap the top two elements
*                - Add a command to clear the stack.
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

double stack[MAX];
int8_t sp = 0;

void push(double num){
    if(sp < MAX){
	stack[sp++] = num;
    }
    else{
        printf("error : stack is full\n");
    }
}

int8_t peek(){
    if(sp == 0){
        printf("Stack empty\n");
        return 0.0;
    }
    return stack[sp - 1];
}

void printTopN(int8_t n){
    if(sp == 0){
        printf("Stack is empty\n");
        return;
    }

    if(n > sp){
        printf("Only %d elements in stack\n", sp);
        return;
    }

    printf("\nTop %d elements:\n", n);

    for(int8_t i = 0; i < n; i++){
        printf("%.2f\n", stack[sp - 1 - i]);
    }
}

void display(){
    if(sp == 0){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: \n");
    for(int8_t i = sp - 1; i >= 0; i--){
	printf("%.2f ", stack[i]);
    }
    printf("\n");
}

void Module4Task4(){

    int8_t c;
    int8_t n;
    int8_t index = 0;
    char buffer[20];

    printf("\nEnter CTRL + D to exit\n");
    printf("\nEnter elements: ");

    while((c = getchar()) != EOF){

        if(c == '\n'){
            if(index > 0){
                buffer[index] = '\0';
                push(atof(buffer));
                index = 0;
            }
            break;
        }

        else if(c == ' '){
            if(index > 0){
                buffer[index] = '\0';
                push(atof(buffer));
                index = 0;
            }
        }

        else if(isdigit(c) || c == '.'){
            buffer[index++] = c;
        }

        else{
            printf("Invalid character: %c\n", c);
	    return;
        }
    }

    printf("\nPress d to duplicate top\n");
    printf("Press s to swap top two\n");
    printf("press c to clear the stack\n");
    char ch;
    printf("Enter choice: ");
    scanf(" %c", &ch);

    switch(ch){

	case 'd':
	    if(sp > 0){
	        double value = stack[sp-1];
	    	push(value);
	    }
	    break;

	case 's':
	    if(sp >=2){
	        double temp = stack[sp-1];
	        stack[sp-1] = stack[sp-2];
	        stack[sp-2] = temp;
	    }
	    break;

	case 'c':
	    sp = 0;
	    break;

        default:
            printf("Invalid choice\n");
    }
    clearerr(stdin);

    char choice;
    printf("\nDo you want top elements (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y'){
        printf("\nEnter number of top elements: ");
        scanf("%hhd", &n);

        printTopN(n);
    }
    else{
        display();
    }
}
