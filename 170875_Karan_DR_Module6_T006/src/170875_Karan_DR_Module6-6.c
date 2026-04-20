/*
* File Name     : 170875_Karan_DR_Module6-6.c
* Description   : Implement a simple version of the #define processor (i.e., no arguments)
                : suitable for use with C programs, based on the routines of this section.
                : You may also find getch and ungetch helpful.
* Author        : Karan Sathvara
* Created       : 20-04-2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "function.h"
#include <ctype.h>

#define HASHSIZE 100
#define MAXWORD 100

/*
* Description   : Structure Declaration
* Author        : Karan Sathvara
* Created       : 20-04-2026
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
* Created       : 20-04-2026
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
* Created       : 20-04-2026
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
* Created       : 20-04-2026
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
* Description   : this function will insert key value pair in linkedlist and if key is present update the value
* Author        : Karan Sathvara
* Created       : 20-04-2026
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
* Function      : print_table
* Description   : This function will print the hash table
* Author        : Karan Sathvara
* Created       : 20-04-2026
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
* Function Name : getword
* Description   : get next word or character from input
* Author        : Karan Sathvara
* Created       : 20-04-2026
*/

int getword(char *word, int16_t lim)
{
    int16_t ch;
    char *w = word;

    while(1){

        while (isspace(ch = getch()))
	    ;

	if (ch == EOF)
    	    return EOF;

	if (ch == '#') {
    	    *w++ = ch;

    	    while (--lim > 0 && isalpha(ch = getch())) {
                *w++ = ch;
    	    }

    	    *w = '\0';

    	    if (ch != EOF)
                ungetch(ch);

    	    if (strcmp(word, "#define") == 0)
                return word[0];

    	    while ((ch = getch()) != '\n' && ch != EOF)
                ;

    	    w = word;
    	    continue;
	}

        if (ch == '/') {
            int8_t next = getch();

            if (next == '/') {
                while ((ch = getch()) != '\n' && ch != EOF)
                    ;
                continue;
            }

            else if (next == '*') {
                int8_t prev = 0;
                while ((ch = getch()) != EOF) {
                    if (prev == '*' && ch == '/'){
                        break;
                    }
                    prev = ch;
                }
                continue;
            }
            else {
                ungetch(next);
            }
        }

        if (ch == '"') {
            while ((ch = getch()) != '"' && ch != EOF) {
                if (ch == '\\'){
                    getch();
                }
                // "hello \"world\""
            }
            continue;
        }

        if (ch != EOF){
            *w++ = ch;
        }

        if (!isalnum(ch)) {
            *w = '\0';
            return ch;
        }

        while(--lim > 0){
            ch = getch();
            if (!isalnum(ch) && ch != '-' && ch != '_'){
                ungetch(ch);
                break;
            }
        *w++ = ch;
        }

        *w = '\0';
        return word[0];
    }
}

/*
* Function      : hashtable_with_macro
* Description   : This function will print the hash table of words only starting with #define
		: ignore other words
* Author        : Karan Sathvara
* Created       : 20-04-2026
*/

void hashtable_with_macro()
{
    char word[MAXWORD];
    char name[MAXWORD];
    char defn[MAXWORD];

    printf("Enter Input : \n");

    while (getword(word, MAXWORD) != EOF) {

        if (strcmp(word, "#define") == 0) {

            if (getword(name, MAXWORD) == EOF)
                break;

            if (getword(defn, MAXWORD) == EOF)
                break;

            install(name, defn);
        }
    }

    printf("\nStored Macros:\n");
    print_table();

}



