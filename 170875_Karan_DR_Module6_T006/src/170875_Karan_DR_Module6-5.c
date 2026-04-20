/*
* File Name     : 170875_Karan_DR_Module6-5.c
* Description   : Write a function undef
                : that will remove a name and definition from the table maintained by lookup and install.
*		: hash table is a data structure used to store data in key -> value form
* Author        : Karan Sathvara
* Created       : 17-04-2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define HASHSIZE 100

/*
* Description   : Structure Declaration
* Author        : Karan Sathvara
* Created       : 17-04-2026
*/

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

/*
* Function Name : unsigned hash
* Description   : This function will compute hash index
* Author        : Karan Sathvara
* Created       : 17-04-2026
*/

unsigned hash(char *str)
{
    unsigned hashval;

    for (hashval = 0; *str != '\0'; str++){
        hashval = *str + 31 * hashval;
    }

    return hashval % HASHSIZE;
}

/*
* Function      : lookup
* Description   : This function will checks if at that node key is present or not
* Author        : Karan Sathvara
* Created       : 17-04-2026
*/

struct nlist *lookup(char *str)
{
    struct nlist *nodePtr;

    for (nodePtr = hashtab[hash(str)]; nodePtr != NULL; nodePtr = nodePtr->next)
    {
        if (strcmp(str, nodePtr->name) == 0){
            return nodePtr;
	}
    }

    return NULL;
}

/*
* Function      : strdup_custom
* Description   : This function will duplicate string
* Author        : Karan Sathvara
* Created       : 17-04-2026
*/

char *strdup_custom(char *str)
{
    char *ptr = (char *)malloc(strlen(str) + 1);

    if (ptr != NULL){
        strcpy(ptr, str);
    }
    return ptr;
}

/*
* Function      : install
* Description   : will insert key value pair in linkedlist and if key is present update the value
* Author        : Karan Sathvara
* Created       : 17-04-2026
*/

struct nlist *install(char *name, char *defn)
{
    struct nlist *nodePtr;
    unsigned hashval;

    if ((nodePtr = lookup(name)) == NULL)
    {
        nodePtr = (struct nlist *)malloc(sizeof(*nodePtr));

        if (nodePtr == NULL){
            return NULL;
	}
        nodePtr->name = strdup_custom(name);

        if (nodePtr->name == NULL){
            return NULL;
	}

        hashval = hash(name);
        nodePtr->next = hashtab[hashval];
        hashtab[hashval] = nodePtr;
    }
    else {
        free(nodePtr->defn);
    }

    nodePtr->defn = strdup_custom(defn);

    if (nodePtr->defn == NULL)
        return NULL;

    return nodePtr;
}

/*
* Function      : undef
* Description   : will delete key value pair in linkedlist and free memory
* Author        : Karan Sathvara
* Created       : 17-04-2026
*/

void undef(char *name){

    struct nlist *found = lookup(name);

    if (found == NULL) {
        printf("Invalid: Key '%s' not found. Please enter a valid key.\n", name);
        return;
    }

    unsigned hashval = hash(name);
    struct nlist *curr, *prev;

    prev = NULL;
    curr = hashtab[hashval];

    while(curr != NULL){
	if(strcmp(name, curr -> name) == 0)
	{
            if (prev == NULL) {
                hashtab[hashval] = curr->next;
            } else {
                prev->next = curr->next;
            }

            free(curr->name);
            free(curr->defn);
            free(curr);

            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

/*
* Function      : print_table
* Description   : This function will print the hash table
* Author        : Karan Sathvara
* Created       : 17-04-2026
*/

void print_table()
{
    for (int8_t idx = 0; idx < HASHSIZE; idx++)
    {
        struct nlist *nodePtr = hashtab[idx];

        while (nodePtr != NULL)
	{
            printf("Index %d: %s -> %s\n", idx, nodePtr->name, nodePtr->defn);
            nodePtr = nodePtr->next;
        }
    }
}

/*
* Function      : print_table
* Description   : This function will print the hash table
* Author        : Karan Sathvara
* Created       : 17-04-2026
*/

void hash_table()
{
    install("Arduino", "Open-source platform");
    install("MSP430", "Texas LP board");
    install("STM32F401", "Developed by STMicroElec");

    printf("\nHash Table : Before\n\n");
    print_table();

    undef("MSP430");

    printf("\nHash Table : After\n\n");
    print_table();
    printf("\n");
}








