/*
* File Name     : function.c
* Description   : contains function calling of all reusable functions
* Author        : Karan Sathvara
* Created       : 04-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "function.h"
#include <stdlib.h>
#include <ctype.h>

/* Common function for q4 and q15 */

float temp_helper(int16_t temp){

     float fahrenheit = (9.0/5.0) * temp + 32;

     return fahrenheit;

}


/* Function for q19 */

#define MAXLINE 50
void reverse_s(char input[]){

    int16_t len = strlen(input);

    if(input[len-1] == '\n'){
        input[len-1] = '\0';
        len--;
    }

    int16_t start = 0;
    int16_t end = len - 1;

    while(start < end){
	char temp = input[start];
	input[start] = input[end];
	input[end] = temp;

	start++;
	end--;
    }
}

/* function for user asking want to continue or not */

void ask_continue(void){

	char choice [10];

	while (1){
	    printf("Do you want to continue(y/n): ");
	    fgets(choice, sizeof(choice), stdin);

       	    if (choice[0] == 'y'){
	        return;
	    }

	    else if (choice[0]  == 'n'){
		exit(0);
	    }
	    else{
		printf("Enter y or n only\n");
	    }
	}
}

/*
* Function Name : reverse
* Description   : This function reverse string
* input         : 123
* output        : 321
* Author        : Karan Sathvara
* Created       : 26-02-2026
*/

void reverse(char str[]){

    int32_t start = 0;
    int32_t end = strlen(str) - 1;
    char temp;

    while(start < end){

        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}


#define BUFSIZE 100

/*
* Function Name : getch
* Description   : this function will take one character from buffer and see
*               - if something pushed back then return that otherwise read from stdin
* Author        : Karan Sathvara
* Created       : 14-04-2026
*/

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    if (bufp > 0){
        return buf[--bufp];
    }
    else{
        return getchar();
    }
}

/*
* Function Name : ungetch
* Description   : this function will push one character back into buffer
* Author        : Karan Sathvara
* Created       : 14-04-2026
*/

void ungetch(int8_t c)
{
    if (bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    }
    else{
        buf[bufp++] = c;
    }
}
