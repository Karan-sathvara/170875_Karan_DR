/*
* File Name     : 170875_Karan_DR_Module8-11.c
* Description   : cat
                : using read, write, open, and close instead of their standard library equivalents.
		: Perform experiments to determine the relative speeds of the two versions.
* current	: fopen -> fgets -> printf -> close
* Author        : Karan Sathvara
* Created       : 23-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <time.h>

#define BUFSIZE 1024

void library_cat(int8_t argc, char *argv[]) {

    FILE *fp;
    char buf[BUFSIZE];
    int n;

    clock_t start, end;
    double timeTaken = 0.0;

    start = clock();

    if (argc == 1) {
        printf("Enter input : \n");
        while ((n = fread(buf, 1, BUFSIZE, stdin)) > 0) {
            fwrite(buf, 1, n, stdout);
        }
    }
    else {
        for (int8_t i = 1; i < argc; i++){
            fp = fopen(argv[i], "r");

            if (fp == NULL) {
                printf("Error in opening File\n");
                continue;
            }
            while ((n = fread(buf, 1, BUFSIZE, fp)) > 0) {
                fwrite(buf, 1, n, stdout);
            }
            fclose(fp);
        }
    }
    end = clock();

    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Library version : %f seconds\n", timeTaken);
}
