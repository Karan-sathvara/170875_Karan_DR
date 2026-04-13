/*
* File Name     : 170875_Karan_DR_Module5-14.c
* Description   : Modify the sort program to handle a -r flag,
*               : which indicates sorting in reverse (decreasing) order. Be sure that -r works with -n.
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>
#include <stdlib.h>

#define MAXLINES 100
#define MAXLEN 100

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int8_t nlines);
void writelines(char *lineptr[], int8_t nlines);
void my_qsort(void *lineptr[], int8_t start, int8_t end, int8_t (*comp)(void *, void *), int8_t reverseFlag);
int numcmp(char *, char *);


/*
* Function Name : getline_custom
* Description   : takes input from user
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

int getline_custom(char *s, int8_t max)
{
    int8_t ch, idx;
    for (idx = 0; idx < max - 1 && (ch = getchar()) != EOF && ch != '\n'; idx++){
        s[idx] = ch;
    }

    if (ch == '\n'){
        s[idx++] = ch;
    }

    s[idx] = '\0';
    return idx;
}

/*
* Function Name : readlines
* Description   : readlines from input using getline
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

int readlines(char *lineptr[], int8_t maxlines)
{
    int8_t len, nlines = 0;
    char *ptr, line[MAXLEN];

    printf("Enter input : \n");
    while ((len = getline_custom(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (ptr = malloc(len)) == NULL){
            return -1;
	}
        line[len - 1] = '\0';
        strcpy(ptr, line);
        lineptr[nlines++] = ptr;
    }
    return nlines;
}

/*
* Function Name : writelines
* Description   : this function writes lines into lineptr array
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

void writelines(char *lineptr[], int8_t nlines)
{
    printf("Result is : \n");
    for (int8_t idx = 0; idx < nlines; idx++){
        printf("%s\n", lineptr[idx]);
    }
}

/*
* Function Name : numcmp
* Description   : this function compares two numbers and returns
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

int numcmp(char *s1, char *s2)
{
    double var1 = atof(s1);
    double var2 = atof(s2);

    if (var1 < var2)
        return -1;
    else if (var1 > var2)
        return 1;
    else
        return 0;
}

/*
* Function Name : quick_sort_lines
* Description   : sorting algorithm to sort lines alphabetically and reverse using pivot
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

void my_qsort(void *arr[], int8_t start, int8_t end, int8_t (*comp)(void *, void *), int8_t reverseFlag)
{
    int8_t idx, pivotIdx;

    void swap(void *arr[], int8_t, int8_t);

    if (start >= end)
        return;

    swap(arr, start, (start + end) / 2);
    pivotIdx = start;

    for (idx = start + 1; idx <= end; idx++) {

        int8_t result = (*comp)(arr[idx], arr[start]);

        if ((!reverseFlag && result < 0) || (reverseFlag && result > 0))
        {
            swap(arr, ++pivotIdx, idx);
        }
    }

    swap(arr, start, pivotIdx);

    my_qsort(arr, start, pivotIdx - 1, comp, reverseFlag);
    my_qsort(arr, pivotIdx + 1, end, comp, reverseFlag);
}

/*
* Function Name : swap
* Description   : swap indexes to get sorted array
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

void swap(void *arr[], int8_t start, int8_t end)
{
    void *temp;
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

/*
* Function Name : modified_sort
* Description   : uses CLI from user with -n -r and -nr flag enabled
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

void modified_sort(int8_t argc, char *argv[])
{
    int8_t nlines;
    int8_t inumericFlag = 0;
    int8_t ireverseFlag = 0;

    if (argc > 1) {
        if (strcmp(argv[1], "-n") == 0){
            inumericFlag = 1;
	}
        else if (strcmp(argv[1], "-r") == 0){
            ireverseFlag = 1;
	}
        else if (strcmp(argv[1], "-nr") == 0) {
            inumericFlag = 1;
            ireverseFlag = 1;
        }
	else{
	    printf("\nInvalid : use [-n] [-r] or [-nr] only\n");
	    return;
	}
    }

    printf("inumericFlag = %hhd ", inumericFlag);
    printf("ireverseFlag = %hhd\n", ireverseFlag);

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

        int8_t (*comp)(void *, void *);

        if (inumericFlag){
            comp = (int8_t (*)(void *, void *))numcmp;
	}
        else{
            comp = (int8_t (*)(void *, void *))strcmp;
	}

        my_qsort((void **)lineptr, 0, nlines - 1, comp, ireverseFlag);

        writelines(lineptr, nlines);

        for (int8_t idx = 0; idx < nlines; idx++){
            free(lineptr[idx]);
	}
    }
    else {
        printf("input too big to sort\n");
    }
}
