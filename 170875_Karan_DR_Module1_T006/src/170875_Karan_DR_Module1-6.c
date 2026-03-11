/*
* File Name     : 170875_Karan_DR_Module1-6.c
* Description   : Verify that the expression getchar() != EOF is 0 or 1.
* Author        : Karan Sathvara
* Created       : 05-02-2026
*/


#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include "function.h"

void verify_EOF(void){

	int16_t result;

        result = (getchar() != EOF);
        printf("%d\n", result);

	ask_continue();
	verify_EOF();
}

