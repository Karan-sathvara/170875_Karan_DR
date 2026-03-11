/*
* File Name     : 170875_Karan_DR_Module1-7.c
* Description   : Write a program to print the value of EOF.
* Author        : Karan Sathvara
* Created       : 06-02-2026
*/

#include <stdio.h>
#include "header.h"
#include "function.h"

void value_of_EOF(void){
	printf("The value of EOF is: %d\n", EOF);

	ask_continue();
	value_of_EOF();
}
