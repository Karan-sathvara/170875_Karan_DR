/*
* File Name     : 170875_Karan_DR_Module5-18.c
* Description   : Make dcl recover from input errors.
* Author        : Karan Sathvara
* Created       : 08-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

/*
* Datatype Name : tokentype : type of last token
		  token[]   : last token string
		  name[]    : identifier name
		  datatype[]: data type
		  out[]     : output string
* Description   : takes input from user
* Author        : Karan Sathvara
* Created       : 08-04-2026
*/

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];


int gettoken(void);
void dcl(void);
void dirdcl(void);

int8_t errorFlag = 0;

/*
* Function Name : dcl
* Description   : count number of pointer
* Author        : Karan Sathvara
* Created       : 08-04-2026
*/

void dcl(void)
{
    int8_t idx;

    for (idx = 0; gettoken() == '*'; )
        idx++;

    dirdcl();

    if(errorFlag){
	return;
    }

    while (idx-- > 0)
        strcat(out, " pointer to");
}

/*
* Function Name : dircl
* Description   : check for name , [] , ()
* Author        : Karan Sathvara
* Created       : 08-04-2026
*/

void dirdcl(void)
{
    int type;

    if (tokentype == '(') {
        dcl();
        if (tokentype != ')'){
            printf("Syntax error : missing closing )\n");
	    errorFlag = 1;
	    return;
	}
    }
    else if (tokentype == NAME) {
        strcpy(name, token);
    }
    else {
        printf("Syntax error : expected name here\n");
	errorFlag = 1;
        return;
    }

    while (!errorFlag) {
	type = gettoken();

        if (type == PARENS)
            strcat(out, " function returning");
        else if(type == BRACKETS) {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
	else if (type == '(') {
            strcat(out, " function returning");

        	while ((type = gettoken()) != ')' && type != EOF && type != '\n');
    	}
    	else {
            break;
    	}
    }
}

/*
* Function Name : gettoken
* Description   : will get token and parse it
* Author        : Karan Sathvara
* Created       : 08-04-2026
*/

int gettoken(void)
{
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
        } else {
            ungetc(c, stdin);
            return tokentype = '(';
        }

    }
    else if (c == '[') {
	*p++ = c;
        while ((c = getchar()) != ']' && c != EOF && c != '\n') {
            *p++ = c;
        }
        if (c == ']'){
            *p++ = c;
	}
	else{
	    printf("Syntax error : missing ]\n");
	    errorFlag = 1;
	    return tokentype = '\n';
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
* Created       : 08-04-2026
*/

void recover(void)
{
    int c;

    if (tokentype == '\n')
        return;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
* Function Name : modified_dcl
* Description   : this function will handle errors and take next input
* Author        : Karan Sathvara
* Created       : 08-04-2026
*/

void modified_dcl()
{
    while (1)
    {
        printf("Enter input : ");

        if (gettoken() == EOF)
            break;

        errorFlag = 0;

        out[0] = '\0';
        name[0] = '\0';
        datatype[0] = '\0';

	if ((tokentype != NAME ) ||
    	(tokentype == NAME &&
     	strcmp(token, "int") != 0 &&
     	strcmp(token, "char") != 0 &&
     	strcmp(token, "float") != 0 &&
     	strcmp(token, "double") != 0 &&
	strcmp(token, "void") != 0)) {

    	    printf("Invalid datatype\n");
	    return;
	}

        strcpy(datatype, token);

        dcl();

        if (errorFlag) {
            recover();
            continue;
        }

        if (tokentype != '\n' && tokentype != EOF) {
            printf("Invalid : syntax error\n");
            recover();
            continue;
        }

        printf("%s: %s %s\n", name, out, datatype);
    }
}

