/*
* File Name     : 170875_Karan_DR_Module7-7.c
* Description   : Write a program to find pattern from given file
		: if no files are named as arguments, from the standard input.
* Author        : Karan Sathvara
* Created       : 22-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>

/*
* Function Name : search
* Description   : this function will find pattern from files or stdin
*               : if pattern present then return filename : lineno : line
                : otherwise return pattern not found in filename
* Author        : Karan Sathvara
* Created       : 22-04-2026
*/

int search(FILE *fp, char *pattern, char *filename){

    char line[100];
    int8_t lineNo = 1;
    int8_t found = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, pattern) != NULL) {
            printf("\t%s : %d : %s", filename, lineNo, line);
	    found = 1;
        }
        lineNo++;
    }
    return found;
}

/*
* Function Name : searchPatternInFiles
* Description   : main function controls the execution of program
*               : takes pattern and filename from command line argument
                : if filename was not given in CL then it will take input from stdin
* Author        : Karan Sathvara
* Created       : 22-04-2026
*/

void searchPatternInFiles(int8_t argc, char *argv[]){

    if (argc < 2) {
        printf("\nUsage: pattern [filenames]\n");
        return;
    }

    char *pattern = argv[1];

    if (argc == 2) {

	printf("\nEnter input : \n");
        int8_t found = search(stdin, pattern, "stdin");

        if (found == 0) {
            printf("\t%s not found in stdin\n", pattern);
        }
    }
    else {

	for (int8_t idx = 2; idx < argc; idx++) {
    	    FILE *fp = fopen(argv[idx], "r");

    	    if (!fp) {
        	printf("\nError opening file %s\n", argv[idx]);
        	continue;
    	    }

    	    int8_t found = search(fp, pattern, argv[idx]);

            if(found == 0){
                printf("\t%s not found from file %s\n", pattern, argv[idx]);
            }
    	    fclose(fp);
	}
    }
}


