/*
* File Name     : 170875_Karan_DR_Module5-17.c
* Description   : Add a field-searching capability, so sorting may bee done on fields within lines
*               : each field sorted according to an independent set of options.
*               : (The index for this book was sorted with -df for the index category and -n for the page numbers.)
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 100
#define MAXLEN 100

int16_t nlines;
int16_t inumericFlag = 0;
int16_t ireverseFlag = 0;
int16_t ifoldFlag = 0;
int16_t idirectoryFlag = 0;

char *lineptr[MAXLINES];

/*
* Function Name : getline_custom
* Description   : takes input from user
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

int getline_custom(char *s, int16_t max)
{
    int16_t ch, idx;
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

int readlines(char *lineptr[], int16_t maxlines)
{
    int16_t len, nlines = 0;
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

void writelines(char *lineptr[], int16_t nlines)
{
    printf("Result is : \n");
    for (int16_t idx = 0; idx < nlines; idx++)
        printf("%s\n", lineptr[idx]);
}

/*
* Function Name : numcmp
* Description   : this function compares two numbers and returns
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

int16_t numcmp(char *s1, char *s2)
{
    double ivar1 = atof(s1);
    double ivar2 = atof(s2);

    if (ivar1 < ivar2)
        return -1;
    else if (ivar1 > ivar2)
        return 1;
    else
        return 0;
}

/*
* Function Name : strcmp_fold
* Description   : this function converts two strings into lowercase and then compare
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

int16_t strcmp_fold(char *s1, char *s2){

    int16_t ich1, ich2;

    while(*s1 && *s2){
	ich1 = tolower((unsigned char)*s1);
	ich2 = tolower((unsigned char)*s2);

        if (ich1 != ich2){
            return ich1 - ich2;
        }
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

/*
* Function Name : strcmp_dir
* Description   : this function compare two string in directory format (only lettes, digits and spaces are valid)
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

int strcmp_dir(char *s1, char *s2)
{
    char ch1, ch2;

    while (1) {

        while (*s1 && !isalnum((unsigned char)*s1) && *s1 != ' ')
            s1++;
        while (*s2 && !isalnum((unsigned char)*s2) && *s2 != ' ')
            s2++;

	if (ifoldFlag){
    	    ch1 = tolower((unsigned char)*s1);
	}else{
    	    ch1 = *s1;
	}

  	if (ifoldFlag){
    	    ch2 = tolower((unsigned char)*s2);
	}else{
	    ch2 = *s2;
	}

	if (ch1 != ch2)
            return ch1 - ch2;

        if (ch1 == '\0')
            return 0;

        s1++;
        s2++;
    }
}

/*
* Function Name : split_fields
* Description   : this function split fields
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

#define MAXFIELDS 50

int split_fields(char *line, char *fields[]) {
    int8_t count = 0;
    char *save;

    char *token = strtok_r(line, ",", &save);
    while (token != NULL && count < MAXFIELDS) {

        while (*token == ' ') token++;
        fields[count++] = token;

        token = strtok_r(NULL, ",", &save);
    }

    return count;
}

/*
* Function Name : compare_fields
* Description   : This function Identify and sort specific fields within each line
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

int compare_lines(void *a, void *b)
{
    char temp1[1000], temp2[1000];
    strcpy(temp1, (char *)a);
    strcpy(temp2, (char *)b);

    char *fields1[MAXFIELDS];
    char *fields2[MAXFIELDS];

    int8_t n1 = split_fields(temp1, fields1);
    int8_t n2 = split_fields(temp2, fields2);

    int8_t n = (n1 < n2) ? n1 : n2;

    for (int i = 0; i < n; i++) {

        int8_t result = 0;

	if (inumericFlag)
            result = numcmp(fields1[i], fields2[i]);
        else
            result = strcmp(fields1[i], fields2[i]);

        if (result != 0)
            return result;
    }

    return n1 - n2;
}

/*
* Function Name : swap
* Description   : swap indexes to get sorted array
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

void swap(void *arr[], int16_t start, int16_t end)
{
    void *temp;
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

/*
* Function Name : quick_sort_lines
* Description   : sorting algorithm to sort lines alphabetically and reverse using pivot
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

void my_qsort(void *arr[], int16_t start, int16_t end, int (*comp)(void *, void *), int16_t reverseFlag)
{
    int16_t idx, pivotIdx;

    void swap(void *arr[], int16_t start, int16_t end);

    if (start >= end)
        return;

    swap(arr, start, (start + end) / 2);
    pivotIdx = start;

    for (idx = start + 1; idx <= end; idx++) {

        int result = (*comp)(arr[idx], arr[start]);

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
* Function Name : addedDir_order_sort
* Description   : uses CLI from user with -f for folding
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

void sort_specific_fields(int8_t argc, char *argv[])
{
    if (argc > 1) {
        if (strcmp(argv[1], "-n") == 0){
            inumericFlag = 1;
	}
        else if (strcmp(argv[1], "-f") == 0){
            ifoldFlag = 1;
        }
        else if (strcmp(argv[1], "-r") == 0){
            ireverseFlag = 1;
	}
        else if (strcmp(argv[1], "-d") == 0){
            idirectoryFlag = 1;
        }
        else if (strcmp(argv[1], "-nr") == 0) {
            inumericFlag = 1;
            ireverseFlag = 1;
        }
        else if (strcmp(argv[1], "-fr") == 0) {
            ifoldFlag = 1;
            ireverseFlag = 1;
        }
        else if (strcmp(argv[1], "-fd") == 0) {
            idirectoryFlag = 1;
	    ifoldFlag = 1;
        }
	else{
	    printf("\nInvalid : use [-n] [-f] [-r] [-d] [-nr] [-fr] or [-fd] only\n");
	    return;
	}
    }

    printf("inumericFlag = %hhd ", inumericFlag);
    printf("ireverseFlag = %hhd ", ireverseFlag);
    printf("ifoldFlag = %hhd ", ifoldFlag);
    printf("idirectoryFlag = %hhd\n", idirectoryFlag);

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

        int (*comp)(void *, void *);

	comp = compare_lines;

        my_qsort((void **)lineptr, 0, nlines - 1, comp, ireverseFlag);

        writelines(lineptr, nlines);

        for (int16_t idx = 0; idx < nlines; idx++){
            free(lineptr[idx]);
	}
    }
    else {
        printf("input too big to sort\n");
    }
}
