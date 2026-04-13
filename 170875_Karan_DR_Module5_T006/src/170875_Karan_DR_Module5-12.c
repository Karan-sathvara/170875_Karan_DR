/*
* File Name     : 170875_Karan_DR_Module5-12.c
* Description   : Extend entab and detab to accept the shorthand
*               : entab -m +n to mean tab stops every n columns,
*		: starting at column m. Choose convenient (for the user) default behavior.
* Author        : Karan Sathvara
* Created       : 03-04-2026
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
* Created       : 03-04-2026
*/

int8_t next_tabstop(int8_t col, int8_t idxM, int8_t idxN) {

    if (col < idxM) {
        return idxM;
    }
    return idxM + ((col - idxM) / idxN + 1) * idxN;
}

/*
* Function Name : Mn_CLI_entab
* Description   : This function performs entab that replaces spaces to tab
* Author        : Karan Sathvara
* Created       : 03-04-2026
*/

void Mn_CLI_entab(int8_t idxM, int8_t idxN){

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

	    int16_t next = next_tabstop(col - space_count, idxM, idxN);
	    spaces_to_tab = next - (col - space_count);

            if (space_count == spaces_to_tab) {
		printf("\\t");
		col = next;
                space_count = 0;
            }
        }
        else {
            while (space_count > 0) {
                putchar(' ');
                space_count--;
            }

            putchar(ch);

            if (ch == '\n')
                col = 0;
            else
                col++;
        }
    }
    while (space_count > 0) {
        putchar(' ');
        space_count--;
    }
}

/*
* Function Name : Mn_CLI_detab
* Description   : This function performs entab that replaces spaces to tab
* Author        : Karan Sathvara
* Created       : 03-04-2026
*/

void Mn_CLI_detab(int8_t idxM, int8_t idxN){

    int16_t ch;
    int16_t col = 0;
    int16_t spaces;

    printf("\nPress CTRL + D to exit the program\n");
    printf("Program started\n\n");

    while ((ch = getchar()) != EOF){

        if (ch == '\t'){

	    int16_t next = next_tabstop(col, idxM, idxN);
	    spaces = next - col;

	    for (int i = 0; i < spaces; i++){

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
* Function Name : modified_entab_detab_CLI
* Description   : This function performs detab and entab through command line
* Author        : Karan Sathvara
* Created       : 03-04-2026
*/

void modified_entab_detab_CLI(int argc, char *argv[]){

    if (argc < 2) {
        printf("Not enough arguments\n");
        return;
    }

    if (strcmp(argv[1], "en") != 0 && strcmp(argv[1], "de") != 0){
        printf("Invalid entry\n");
	return;
    }

    if (argc < 3) {
        printf("Usage: ./Exercise_5_11 [en|de] [tabstops..]\n");
        return;
    }

    int8_t idxM = 1;
    int8_t idxN = 8;

    for (int8_t i = 2; i < argc; i++) {

        if (argv[i][0] == '-') {
            idxM = atoi(&argv[i][1]);
        }
        else if (argv[i][0] == '+') {
            idxN = atoi(&argv[i][1]);
        }
	else{
	    printf("Give input like [en/de] -m +n\n");
	    return;
	}
    }

    if (idxM < 1){
        idxM = 1;
    }
    if (idxN <= 0){
        idxN = 8;
    }

    if (strcmp(argv[1], "en") == 0) {
        Mn_CLI_entab(idxM, idxN);
    }
    else if (strcmp(argv[1], "de") == 0) {
        Mn_CLI_detab(idxM, idxN);
    }

    else {
        printf("Invalid option. Use 'en' or 'de'\n");
    }
}

