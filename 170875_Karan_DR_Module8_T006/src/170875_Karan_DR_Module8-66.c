/*
* File Name     : 170875_Karan_DR_Module8-6.c
* Description   : The standard library function calloc(n,size) returns a pointer to n objects of size size,
		: with the storage initialized to zero.
		: Write calloc, by calling malloc or by modifying it.
		- We have to write our own calloc.
* Author        : Karan Sathvara
* Created       : 30-04-2026
*/

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
* Function Name : *calloc_using_malloc
* Description   : This function allocate memory through malloc and initialize it with zero
		: and return pointer to located memory
* Author        : Karan Sathvara
* Created       : 30-04-2026
*/

void *calloc_using_malloc(size_t num, size_t size) {

    size_t total = num * size;

    if(num == 0 || size == 0){
	printf("\tInvalid input. Please enter a positive integer.\n");
	return NULL;
    }

    if (num != 0 && total / num != size){
	printf("\tinteger Overflow\n");
        return NULL;
    }

    void *ptr = malloc(total);
    if (ptr == NULL){
        return NULL;
    }

    unsigned char *p = ptr;
    for (size_t idx = 0; idx < total; idx++) {
        p[idx] = 0;
    }

    return ptr;
}

/*
* Function Name : my_calloc
* Description   : This function takes user input calloc(n,size)
                : validate and print result in hexadecimal
* Author        : Karan Sathvara
* Created       : 30-04-2026
*/

void my_calloc() {

    size_t num, size;

    printf("\tEnter the number of elements: ");
    scanf("%zu", &num);

    printf("\tEnter the size of each element (in bytes): ");
    scanf("%zu", &size);

    unsigned char *ptr = calloc_using_malloc(num, size);

    if (ptr == NULL) {
        printf("\tMemory allocation failed\n");
        return;
    }

    printf("\tMemory allocated and initialized to zero\n");
    printf("\tMemory content in hex : \n\t");

    for (size_t idx = 0; idx < num * size; idx++) {
        printf("%02x ", ptr[idx]);
    }
    printf("\n");

    free(ptr);
}

