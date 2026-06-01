/*
* File Name     : 170875_Karan_DR_Module5-11.c
* Description   : Modify the program entab and detab (written as exercises in Chapter 1)
*               : to accept a list of tab stops as arguments.
*		: Use the default tab settings if there are no arguments.
* Author        : Karan Sathvara
* Created       : 02-04-2026
*/


#include <stdio.h>
#include <header.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

/*
* Function Name : next_tabstop
* Description   : This function will count next tabstop and return it's value
* Author        : Karan Sathvara
* Created       : 02-02-2026
*/

int16_t next_tabstop(int8_t col, int16_t tabstops[], int16_t ntab) {

    if (ntab == 1) {
        int8_t step = tabstops[0];
        return ((col / step) + 1) * step;
    }

    return col + (8 - col % 8);
}

/*
* Function Name : CLI_entab
* Description   : This function performs entab that replaces spaces to tab
* Author        : Karan Sathvara
* Created       : 02-02-2026
*/

void CLI_entab(int16_t tabstops[], int16_t ntab){

    int16_t ch;
    int16_t space_count = 0;
    int16_t col = 0;
    int16_t spaces_to_tab;

    printf("\nPress CTRL + D to exit the program\n");
    printf("Program started\n\n");

    while ((ch = getchar()) != EOF){
	if (ch == ' '){
	    space_count++;
	    col++;

	    int16_t next = next_tabstop(col - space_count, tabstops, ntab);
	    spaces_to_tab = next - (col - space_count);

            if (space_count == spaces_to_tab) {
		printf("\\t");
		col = next;
                space_count = 0;
            }
        }
        else {
            while (space_count > 0) {
                putchar('&');
                space_count--;
            }

            putchar(ch);

            if (ch == '\n')
                col = 0;
            else
                col++;
        }
    }
}

/*
* Function Name : CLI_detab
* Description   : This function performs detab that replaces tab to equivalent spaces
* Author        : Karan Sathvara
* Created       : 02-02-2026
*/

void CLI_detab(int16_t tabstops[], int16_t ntab){

    int16_t ch;
    int16_t col = 0;
    int16_t spaces;

    printf("\nPress CTRL + D to exit the program\n");
    printf("Program started\n\n");

    while ((ch = getchar()) != EOF){

        if (ch == '\t'){

	    int16_t next = next_tabstop(col, tabstops, ntab);
	    spaces = next - col;

	    for (int8_t idx = 0; idx < spaces; idx++){

		putchar('*');
		col++;
	    }
	}
	else if (ch == '\n'){

	    putchar(ch);
	    col = 0;
	}

	else{
	    putchar(ch);
	    col++;
	}
    }
}

/*
* Function Name : entab_detab_CLI
* Description   : This function performs detab and entab through command line
* Author        : Karan Sathvara
* Created       : 02-02-2026
*/

void entab_detab_CLI(int8_t argc, char *argv[]){

    int16_t tabstops[100];
    int16_t ntab = 0;

    if (argc < 2 || argc > 3) {
        printf("Usage: ./Exercise_5_11 [en|de] [tabstop]\n");
        return;
    }

    if (argc == 3) {
	tabstops[ntab++] = abs(atoi(argv[2]));
    }
    else {
        tabstops[ntab++] = 8;
    }

    if (strcmp(argv[1], "en") != 0 && strcmp(argv[1], "de") != 0){
        printf("Invalid entry\n");
	return;
    }

    if (strcmp(argv[1], "en") == 0) {
        CLI_entab(tabstops, ntab);
    }
    else if (strcmp(argv[1], "de") == 0) {
        CLI_detab(tabstops, ntab);
    }

    else {
        printf("Invalid option. Use 'en' or 'de'\n");
    }
}

