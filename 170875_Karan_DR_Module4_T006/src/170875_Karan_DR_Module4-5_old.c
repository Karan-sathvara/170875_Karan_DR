/*
* File Name     : 170875_Karan_DR_Module4-5.c
* Description   : Add access to library functions like sin, exp, and pow.
* Author        : Karan Sathvara
* Created       : 03-03-2026
*/

#include <stdio.h>
#include "header.h"
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

double stack[MAX];
int sp = 0;

void push(double num){
    if(sp < MAX){
        stack[sp++] = num;
    }
    else{
	printf("error : stack is full\n");
    }
}

double pop(){
    if(sp == 0){
        printf("Stack empty\n");
        return 0.0;
    }
    return stack[--sp];
}

void display(){
    if(sp == 0){
        printf("Stack is empty\n");
        return;
    }
    printf("Evaluated stack: \n");
    for(int i=sp-1; i >= 0; i--){
        printf("%.5f ", stack[i]);
    }
    printf("\n");
}

void Module4Task5(){

    int c;
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
            printf("Error : Unkown command %c\n", c);
            return;
        }
    }
    printf("\nPress s for sine operation\n");
    printf("Press p for power operation\n");
    printf("press e for exponential operation\n");
    char ch;
    printf("\nEnter choice: ");
    scanf(" %c", &ch);

    switch(ch){

        case 's':
            if(sp > 0){
                double val = pop();
 		double sine = sin(val);
                push(sine);
            }
            break;

        case 'p':
            if(sp >=2){
                double exponent = pop();
		double base = pop();
            	push(pow(base, exponent));
	    }
            break;

        case 'e':
            if(sp > 0){
		double val = pop();
		push(exp(val));
            }
	    break;

        default:
            printf("Invalid choice\n");
    }


    display();
}
