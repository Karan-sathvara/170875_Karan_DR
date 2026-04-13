/*
* File Name     : 170875_Karan_DR_Module5-19.c
* Description   : Modify undcl so that it does not add redundant parentheses to declarations.
* Author        : Karan Sathvara
* Created       : 09-04-2026
*/


#include <stdio.h>
#include "header.h"
#include <string.h>
#include <ctype.h>

enum { NAME, PARENS, BRACKETS };

#define MAXTOKEN 1000

char temp[2000];
int tokentype;
char token[MAXTOKEN];
char out[MAXTOKEN];


int8_t errorFlag = 0;


/*
* Function Name : gettoken
* Description   : will get token and parse it
* Author        : Karan Sathvara
* Created       : 09-04-2026
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
* Function Name : undcl
* Description   : undcl program is used to convert a word description of a declaration into a C declaration.
* Author        : Karan Sathvara
* Created       : 09-04-2026
*/

void undcl(){

    int type;

    printf("Press CTRL + D to Exit...\n");
    printf("Enter input : ");

    while ((type = gettoken()) != EOF) {
        if (errorFlag) {
            printf("Skipping invalid input\n");
            errorFlag = 0;

            while (type != '\n' && type != EOF){
                type = gettoken();
	    }
            out[0] = '\0';
            continue;
        }

        if (type == '\n') continue;

        strcpy(out, token);

        while ((type = gettoken()) != '\n' && type != EOF) {

            if (errorFlag) {
                printf("Skipping invalid input\n");
                errorFlag = 0;
                while (type != '\n' && type != EOF){
                    type = gettoken();
		}
		out[0] = '\0';
		break;
            }

            if (type == PARENS || type == BRACKETS){
                strcat(out, token);
	    }

            else if (type == '*') {
                if (out[0] == '(') {
                    sprintf(temp, "*%s", out);
                }
                else if (strstr(out, "()") || strstr(out, "[]")) {
                    sprintf(temp, "(*%s)", out);
                }
                else {
                    sprintf(temp, "*%s", out);
                }
                strcpy(out, temp);
            }

            else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            }

            else {
                printf("invalid input at %s\n", token);
		errorFlag = 1;
		break;
            }
        }

	if(!errorFlag){
	    printf("%s\n", out);
	}
    }
}


/*

            else if (type == '*') {
                if (strchr(out, '(') || strchr(out, '[')) {
                    sprintf(temp, "(*%s)", out);
                }
                else {
                    sprintf(temp, "*%s", out);
                }
                strcpy(out, temp);
            }

*/
