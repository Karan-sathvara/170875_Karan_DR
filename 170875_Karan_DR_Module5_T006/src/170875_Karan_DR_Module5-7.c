/*
* File Name     : 170875_Karan_DR_Module5-7.c
* Description   : Rewrite readlines to store lines in an array supplied by main,
*		: rather than calling alloc to maintain storage. How much faster is the program?
* Author        : Karan Sathvara
* Created       : 31-03-2026
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXSTORAGE 10000
#define MAXLINES 5000
#define MAXLEN   1000

clock_t start, end;
double cpu_time_used;

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int16_t maxlines);
void writelines(char *lineptr[], int8_t nlines);
void quick_sort_lines(char *lineptr[], int16_t start, int16_t end);
void swap(char *lineptr[], int16_t start, int16_t end);
int get_line(char *line, int max);

/*
* Function Name : readlines
* Description   : readlines from input using getline
* Author        : Karan Sathvara
* Created       : 31-03-2026
*/

int readlines(char *lineptr[], int16_t maxlines)
{
    int16_t len = 0;
    int8_t nlines = 0;
    char line[MAXLEN];

    static char linestore[MAXSTORAGE];
    char *startPtr = linestore;
    char *end = linestore + 10000;

    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || startPtr + len > end){
            return -1;
	}

        line[len - 1] = '\0';

        strcpy(startPtr, line);
        lineptr[nlines++] = startPtr;

	startPtr = startPtr + len;
    }
    return nlines;
}

/*
* Function Name : writelines
* Description   : this function writes lines into lineptr array
* Author        : Karan Sathvara
* Created       : 31-03-2026
*/

void writelines(char *lineptr[], int8_t nlines){

    printf("\nSorted lines : \n");
    while (nlines-- > 0){
        printf("%s\n", *lineptr++);
    }
    printf("\n");
}

/*
* Function Name : quick_sort_lines
* Description   : sorting algorithm to sort lines alphabetically pivot
* Author        : Karan Sathvara
* Created       : 31-03-2026
*/

void quick_sort_lines(char *arr[], int16_t start, int16_t end)
{
    int16_t idx;
    int16_t pivotIdx;

    if (start >= end)
        return;

    swap(arr, start, (start + end) / 2);
    pivotIdx = start;

    for (idx = start + 1; idx <= end; idx++) {
        if (strcmp(arr[idx], arr[start]) < 0)
            swap(arr, ++pivotIdx, idx);
    }

    swap(arr, start, pivotIdx);
    quick_sort_lines(arr, start, pivotIdx - 1);
    quick_sort_lines(arr, pivotIdx + 1, end);
}

/*
* Function Name : swap
* Description   : swap indexes to get sorted array
* Author        : Karan Sathvara
* Created       : 31-03-2026
*/

void swap(char *arr[], int16_t start, int16_t end)
{
    char *temp;
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

/*
* Function Name : get_line
* Description   : takes input from user
* Author        : Karan Sathvara
* Created       : 31-03-2026
*/

int get_line(char *line, int max)
{
    int16_t ch = 0, idx = 0;

    while (idx < max - 1 && (ch = getchar()) != EOF && ch != '\n') {
        line[idx++] = ch;
    }

    if (ch == '\n') {
        line[idx++] = ch;
    }

    line[idx] = '\0';
    return idx;
}

/*
* Function Name : main function
* Description   : control program execution
* Author        : Karan Sathvara
* Created       : 31-03-2026
*/

void modified_readlines()
{
    int8_t nlines = 0;

    start = clock();
    printf("Enter input : ");

    if((nlines = readlines(lineptr, MAXLINES)) >= 0){

        quick_sort_lines(lineptr, 0, nlines - 1);

        writelines(lineptr, nlines);
    }
    else{
        printf("error: input too big to sort\n");
        return;
     }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
}

