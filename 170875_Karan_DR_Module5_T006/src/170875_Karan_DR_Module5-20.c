/*
* File Name     : 170875_Karan_DR_Module5-20.c
* Description   : Expand dcl to handle declarations with function argument types, qualifiers like const, and so on.
* Author        : Karan Sathvara
* Created       : 20-04-2026
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS, QUALIFIER };


int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int8_t errorFlag = 0;

int gettoken(void);
void dcl(void);
void dirdcl(void);
void recover(void);

/*
* Function Name : dcl
* Description   : count number of pointer
* Author        : Karan Sathvara
* Created       : 10-04-2026
*/

void dcl(void) {
    int ns = 0;

    while (tokentype == '*') {
        ns++;
        gettoken();
    }

    dirdcl();

    while (ns-- > 0)
        strcat(out, " pointer to");
}

/*
* Function Name : undcl
* Description   : undcl program is used to convert a word description of a declaration into a C declaration.
* Author        : Karan Sathvara
* Created       : 10-04-2026
*/

void dirdcl(void) {
    if (tokentype == '(') {
        gettoken();
        dcl();
        if (tokentype != ')') {
            printf("Syntax error: missing )\n");
            errorFlag = 1;
        }
    }
    else if (tokentype == NAME) {
        strcpy(name, token);
    }
    else if (tokentype == '\n') {
    }
    else {
        printf("Syntax error: Invalid Input\n");
        errorFlag = 1;
        return;
    }

    while (gettoken() == PARENS || tokentype == BRACKETS || tokentype == '(') {
        if (tokentype == PARENS) {
            strcat(out, " function returning");
        }
	else if (tokentype == BRACKETS) {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");

        }
	else if (tokentype == '(') {
            strcat(out, " function (");
            while (gettoken() != ')' && tokentype != EOF && tokentype != '\n') {
                if (tokentype == ','){
		    strcat(out, ", ");
		}
		else if (tokentype == BRACKETS){
		    strcat(out,"array");
		}
                else if (tokentype == NAME || tokentype == QUALIFIER) {
                    strcat(out, token);
                    strcat(out, " ");
                }
		else if (tokentype == '*') {
                    strcat(out, "pointer to ");
                }
            }
            strcat(out, ") returning");
        }
    }
}

/*
* Function Name : gettoken
* Description   : will get token and parse it
* Author        : Karan Sathvara
* Created       : 10-04-2026
*/

int gettoken(void) {
    int c;
    char *p = token;

    while ((c = getchar()) == ' ' || c == '\t');

    if (c == '/') {
        int next = getchar();

        if (next == '/') {

            while ((c = getchar()) != '\n' && c != EOF);

            return tokentype = '\n';
        }
        else {
            ungetc(next, stdin);
            return tokentype = '/';
        }
    }

    if (c == '(') {
        if ((c = getchar()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
	else {
            ungetc(c, stdin);
            return tokentype = '(';
        }
    }
    else if (c == '[') {
        *p++ = c;
        while ((c = getchar()) != ']' && c != EOF && c != '\n'){
            *p++ = c;
        }
        if (c == ']'){
            *p++ = c;
        }
        else{
            printf("Syntax error : missing ]\n");
            errorFlag = 1;
            return 0;
        }
        *p = '\0';

        return tokentype = BRACKETS;
    }
    else if (isalpha(c)) {
        *p++ = c;
        while ((c = getchar()) != EOF && isalnum(c)) {
            *p++ = c;
        }

        *p = '\0';

        if(c != EOF){
            ungetc(c, stdin);
        }

        if (strcmp(token, "const") == 0 || strcmp(token, "volatile") == 0 ||
		strcmp(token, "short") == 0 || strcmp(token, "long") == 0){
            return tokentype = QUALIFIER;
	}
        return tokentype = NAME;
    }
    else {
        return tokentype = c;
    }
}

/*
* Function Name : recover
* Description   : Skips the rest of the current input line after an error
* Author        : Karan Sathvara
* Created       : 10-04-2026
*/

void recover(void) {
    int c;
    while (tokentype != '\n' && (c = getchar()) != '\n' && c != EOF);
}

/*
* Function Name : modified_dcl_for_args
* Description   : This function will take function arguments and const keywod also and convert equation to english
* Author        : Karan Sathvara
* Created       : 10-04-2026
*/

void modified_dcl_for_args() {

    printf("Enter input : ");

    while (gettoken() != EOF) {

	errorFlag = 0;
        strcpy(datatype, token);
        out[0] = '\0';
        name[0] = '\0';

        while (gettoken() == NAME || tokentype == QUALIFIER) {

            int next = getchar();
            ungetc(next, stdin);

            if (tokentype == NAME && (next == '(' || next == '[' || next == '*' || next == ';' || next == '\n')) {
		strcpy(name, token);
                break;
            }
            strcat(datatype, " ");
            strcat(datatype, token);
        }

        dcl();

        if (!errorFlag) {
            if (name[0] == '\0') strcpy(name, "unknown");
            printf("%s: %s %s", name, out, datatype);
        }

        if (tokentype != '\n' && tokentype != EOF) recover();
        printf("\nEnter input: ");
    }
}
