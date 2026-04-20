/*
* File Name     : 170875_Karan_DR_Module6-1.c
* Description   : Write a better version.
*                - Our version of getword does not properly handle underscores,
*                - string constants, comments, or preprocessor control lines.
* Author        : Karan Sathvara
* Created       : 13-04-2026
*/

#include <stdio.h>
#include <ctype.h>
#include "header.h"
#include "function.h"
#include <string.h>


#define MAXWORD 100
#define BUFSIZE 100


/*
* Structure 	: key
* Description   : this structure has counter and char pointer
		: keytab is an array of 32 inbuilt keywords in c
* Author        : Karan Sathvara
* Created       : 14-04-2026
*/

struct key {
    char *word;
    uint8_t count;
};

struct key keytab[] = { {"auto", 0}, {"break", 0}, {"case", 0}, {"char", 0}, {"const", 0}, {"continue", 0},
    {"default", 0}, {"do", 0}, {"double", 0}, {"else", 0}, {"enum", 0}, {"extern", 0}, {"float", 0}, {"for", 0},
    {"goto", 0}, {"if", 0}, {"int", 0}, {"long", 0}, {"register", 0}, {"return", 0}, {"short", 0}, {"signed", 0},
    {"sizeof", 0}, {"static", 0}, {"struct", 0}, {"switch", 0}, {"typedef", 0}, {"union", 0}, {"unsigned", 0},
    {"void", 0}, {"volatile", 0}, {"while", 0}
};

#define NKEYS (sizeof keytab / sizeof keytab[0])

int getword(char *, int8_t);
int binsearch(char *, struct key *, int8_t);

/*
* Function Name : binarysearch
* Description   : this function perform binary search
* Author        : Karan Sathvara
* Created       : 14-04-2026
*/

int binsearch(char *word, struct key tab[], int8_t num)
{
    int8_t condition = 0;
    int8_t low = 0;
    int8_t high = num - 1;
    int8_t mid = 0;

    while (low <= high) {

        mid = (low + high) / 2;
        condition = strcmp(word, tab[mid].word);

        if (condition < 0){
            high = mid - 1;
	}
        else if (condition > 0){
            low = mid + 1;
	}
        else{
            return mid;
	}
    }
    return -1;
}

/*
* Function Name : getword
* Description   : get next word or character from input
		: modification : not include comments , preprocessor and strings
* Author        : Karan Sathvara
* Created       : 14-04-2026
*/

int getword(char *word, int8_t lim)
{
    int8_t ch;
    char *w = word;

    while(1){

        while (isspace(ch = getch()))
            ;

	if (ch == '#') {
    	    while ((ch = getch()) != '\n' && ch != EOF)
        	;
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

        if (!isalpha(ch)) {
            *w = '\0';
            return ch;
        }

        while(--lim > 0){
	    ch = getch();
            if (!isalnum(ch)) {
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
* Function Name : modified_getword
* Description   : This function prints keyword occurances
                : internally uses getword and binarysearch
* Author        : Karan Sathvara
* Created       : 14-04-2026
*/

void modified_getword()
{
    int8_t idx = 0;
    char word[MAXWORD];

    printf("Enter input : \n");

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((idx = binsearch(word, keytab, NKEYS)) >= 0){
                keytab[idx].count++;
	    }
        }
    }

    printf("Keywords count : \n");
    for (idx = 0; idx < NKEYS; idx++) {
        if (keytab[idx].count > 0){
            printf("%s : %d\n", keytab[idx].word, keytab[idx].count);
	}
    }
}
