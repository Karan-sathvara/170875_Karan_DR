/*
* File Name     : 170875_Karan_DR_Module7-8.c
* Description   : Write a program to print a set of files, starting each new one on a new page,
		: with a title and a running page count for each file.
* Author        : Karan Sathvara
* Created       : 22-04-2026
*/

#include <stdio.h>
#include "header.h"

#define PAGE_LENGTH 20

/*
* Function Name : print_files_pageWise
* Description   : main function prints files content pagewise with title
*               : title = name of file and page length is 20
                : means in file after 20 lines page will break
* Author        : Karan Sathvara
* Created       : 22-04-2026
*/

void print_files_pageWise(int8_t argc, char *argv[]){

    int8_t lineCount = 0;
    int8_t pageCount = 1;
    char line[100];

    if (argc < 2) {
        printf("\nUsage: [filename]\n");
        return;
    }

    FILE *fp = fopen(argv[1], "r");
    printf("\nTitle : %s\n", argv[1]);

    while (fgets(line, sizeof(line), fp) != NULL){
        printf("%s", line);
        lineCount++;

        if(lineCount == PAGE_LENGTH){
            printf("\t ----- Page %d -----\n", pageCount);
            pageCount++;
            lineCount = 0;

	    int8_t nextChar = fgetc(fp);

	    if (nextChar != EOF) {
    		ungetc(nextChar, fp);
    		printf("Press Enter to continue...");
    		getchar();
	    }
        }
    }

    printf("\nEnd of File\n");
    fclose(fp);
}

