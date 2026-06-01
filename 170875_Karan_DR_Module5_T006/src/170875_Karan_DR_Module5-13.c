/*
* File Name     : 170875_Karan_DR_Module5-13.c
* Description   : Write the program tail, which prints the last n lines of its input.
*               : By default, n is set to 10, but it can be changed by an optional argument
*		: tail -n : prints the last n lines
* Author        : Karan Sathvara
* Created       : 06-04-2026
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
* Created       : 06-04-2026
*/

void print_n_lines(char *str, int8_t nlines) {

    int8_t len = strlen(str);
    int8_t line_Count = 0;
    int8_t idx = len - 1;

    while (idx >= 0) {
        if (str[idx] == '\n') {
            line_Count++;
            if (line_Count == nlines + 1) {
                idx++;
                break;
            }
        }
        idx--;
    }

    if (idx < 0){
        idx = 0;
    }

    printf("output lines : \n");
    for (; idx < len; idx++) {
        putchar(str[idx]);
    }
}

/*
* Function Name : tail
* Description   : This function validate command line args and take input
* Author        : Karan Sathvara
* Created       : 06-04-2026
*/

void tail(int8_t argc, char *argv[]){

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

    int16_t ch;
    int16_t idx = 0;
    char *str = NULL;
    uint16_t size = 0;

    printf("\nEnter input lines : \n");
    while((ch = getchar()) != EOF){

        if (idx >= size) {
            size = (size == 0) ? 1024 : size * 2;
            str = realloc(str, size);

            if (str == NULL) {
                printf("Memory allocation failed\n");
                return;
            }
    	}
        str[idx++] = ch;
    }
    str[idx] = '\0';

    print_n_lines(str, nlines);

    free(str);
}
