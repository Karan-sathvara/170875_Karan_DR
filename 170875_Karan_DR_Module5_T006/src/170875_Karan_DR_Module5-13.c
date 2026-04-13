/*
* File Name     : 170875_Karan_DR_Module5-13.c
* Description   : Write the program tail, which prints the last n lines of its input.
*               : By default, n is set to 10, but it can be changed by an optional argument
*		: tail -n : prints the last n lines
* Author        : Karan Sathvara
* Created       : 00-04-2026
*/


#include <stdio.h>
#include <header.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
* Function Name : print_n_lines
* Description   : This function will print last n lines
* Author        : Karan Sathvara
* Created       : 00-04-2026
*/

void print_n_lines(char *str, int8_t nlines) {

    int8_t total_lines = 0;
    int8_t idx = 0;

    while (str[idx] != '\0') {
        if (str[idx] == '\n')
            total_lines++;
        idx++;
    }

    if (idx > 0 && str[idx - 1] != '\n')
        total_lines++;

    int8_t skip = total_lines - nlines;
    if (skip < 0){
        printf("Not enough lines are there\n");
	return;
    }

    int8_t current_line = 0;
    idx = 0;

    while (str[idx] != '\0' && current_line < skip) {
        if (str[idx] == '\n')
            current_line++;
        idx++;
    }

    printf("\nOutput is : \n");
    while (str[idx] != '\0') {
        putchar(str[idx]);
        idx++;
    }
}

/*
* Function Name : tail
* Description   : This function validate command line args and take input
* Author        : Karan Sathvara
* Created       : 00-04-2026
*/

void tail(int8_t argc, char *argv[]){

    char str[1000];
    int16_t ch;
    int16_t idx = 0;

    int8_t nlines = 10;

    if (argc > 1 && strcmp(argv[1], "tail") == 0) {
        if (argc > 2){
	    if(argv[2][0] == '-' && isdigit(argv[2][1])) {
                nlines = abs(atoi(argv[2]));
            }
	    else{
		printf("Give input like tail -n\n");
		return;
	    }
	}
    }
    else if (argc > 1) {
        printf("Give input like tail -n\n");
        return;
    }

    printf("\nEnter input lines : \n");
    while((ch = getchar()) != EOF){
	str[idx++] = ch;
    }
    str[idx] = '\0';

    print_n_lines(str, nlines);

}
