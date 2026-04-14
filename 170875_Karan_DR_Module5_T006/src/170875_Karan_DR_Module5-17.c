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
* Function Name : compare_fields
* Description   : This function Identify and sort specific fields within each line
* Author        : Karan Sathvara
* Created       : 07-04-2026
*/

int16_t compare_fields(void *a, void *b)
{
    char *line1 = (char *)a;
    char *line2 = (char *)b;

    char temp1[1000], temp2[1000];
    strcpy(temp1, line1);
    strcpy(temp2, line2);

    char *save1, *save2;

    /* Category: Science, Page: 42  */
    /* Category: Maths, Page: 4  */

    char *field1_1 = strtok_r(temp1, ",", &save1);
    char *field1_2 = strtok_r(NULL, ",", &save1);

    char *field2_1 = strtok_r(temp2, ",", &save2);
    char *field2_2 = strtok_r(NULL, ",", &save2);

    if (!field1_2 || !field2_2)
        return strcmp(line1, line2);

    char *cat1 = strchr(field1_1, ':');
    char *cat2 = strchr(field2_1, ':');
    char *page1 = strchr(field1_2, ':');
    char *page2 = strchr(field2_2, ':');

    if (!cat1 || !cat2 || !page1 || !page2)
        return 0;

    cat1++; cat2++;
    page1++; page2++;

    while (*cat1 == ' ') cat1++;
    while (*cat2 == ' ') cat2++;
    while (*page1 == ' ') page1++;
    while (*page2 == ' ') page2++;

    if (inumericFlag)
        return numcmp(page1, page2);

    int8_t result = 0;

    if (idirectoryFlag && ifoldFlag)
        result = strcmp_dir(cat1, cat2);
    else if (ifoldFlag)
        result = strcmp_fold(cat1, cat2);
    else
        result = strcmp(cat1, cat2);

    if (result != 0)
        return result;

    if (inumericFlag)
        return numcmp(page1, page2);
    else
        return strcmp(page1, page2);
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

void my_qsort(void *arr[], int16_t start, int16_t end, int16_t (*comp)(void *, void *), int16_t reverseFlag)
{
    int16_t idx, pivotIdx;

    void swap(void *arr[], int16_t start, int16_t end);

    if (start >= end)
        return;

    swap(arr, start, (start + end) / 2);
    pivotIdx = start;

    for (idx = start + 1; idx <= end; idx++) {

        int16_t result = (*comp)(arr[idx], arr[start]);

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

        int16_t (*comp)(void *, void *);

	comp = compare_fields;

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
