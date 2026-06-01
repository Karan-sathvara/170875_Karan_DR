/*
* File Name     : 170875_Karan_DR_Module7-6.c
* Description   : Write a program to compare two files, printing the first line where they differ
*		: If the files are identical, the program should indicate that.
*		: If the files have different lengths, it should also detect and report that.
* Author        : Karan Sathvara
* Created       : 21-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>

/*
* Function Name : file_compare
* Description   : this function compare two files from command line and checks
*               : 1. Files are identical or not
		: 2. If the files have different lengths
		: 3. If both files differ then from which line gives line no
* Author        : Karan Sathvara
* Created       : 21-04-2026
*/

void file_compare(int8_t argc, char *argv[]){

    int8_t lineNo = 1;
    char line1[100] = "";
    char line2[100] = "";

    FILE *fp1, *fp2;

    if (argc < 3) {
        printf("Usage: file1 file2\n");
        return;
    }

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");

    if (!fp1 || !fp2) {
        printf("Error opening files\n");
        return;
    }

    while(1) {

        char *file1 = fgets(line1, sizeof(line1), fp1);
        char *file2 = fgets(line2, sizeof(line2), fp2);

        if (file1 == NULL && file2 == NULL){
	    printf("\tFiles are identical.\n");
            break;
	}

        if (file1 == NULL || file2 == NULL) {
            printf("\tFiles have different lengths.\n");
            break;
        }

	if(strcmp(line1, line2) != 0){
	    printf("\tfiles differ at line %d\n",lineNo);
	    printf("\tFile1: %s", line1);
    	    printf("\tFile2: %s", line2);

	    break;
        }
	lineNo++;
    }

    fclose(fp1);
    fclose(fp2);
}
