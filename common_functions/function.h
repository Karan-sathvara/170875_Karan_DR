/*
* File Name     : header.h
* Description   : contains function declaration of all reusable functions.
* Author        : Karan Sathvara
* Created       : 04-02-2026
*/

#include <stdint.h>

#ifndef FUNCTION_H
#define FUNCTION_H

float temp_helper(int16_t temp);
void reverse_s(char input[]);
void ask_continue(void);
void reverse(char str[]);

int ask_to_continue(void);

/* Stack functions */

void push(double f);
double pop(void);
int getch(void);
void ungetch(int8_t c);

#endif
