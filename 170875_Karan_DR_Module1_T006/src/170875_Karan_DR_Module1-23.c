/*
* File Name     : 170875_Karan_DR_Module1-23.c
* Description   : Write a program
*                 - to remove all comments from a C program.
*                 Don't forget to handle quoted strings and character constants properly.
*                 C comments don't nest.
* Author        : Karan Sathvara
* Created       : 13-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include "header.h"

typedef enum {
    NORMAL,
    IN_SINGLELINE_COMMENT,
    IN_MULTILINE_COMMENT,
    IN_STRING,
    IN_CHAR
} state;

void remove_commentsFrom_cfile(){

    int16_t ch;
    int16_t next;
    int16_t prev = 0;
    state current_state = NORMAL;

    FILE *fp = fopen("output_q23.txt", "w");

	if(fp == NULL){
 	    printf("File open failed!\n");
            return;
         }

    while ((ch = getchar()) != EOF){

	if (current_state == NORMAL){

	    if (ch == '/'){
		next = getchar();
	    	if (next == EOF){
		    putchar(ch);
		    break;
	    	}

	    	else if (next == '/'){
                    fputc('/', fp);
                    fputc('/', fp);
		    current_state = IN_SINGLELINE_COMMENT;
	    	}

	    	else if (next == '*'){
		    fputc('/', fp);
		    fputc('*', fp);
		    current_state = IN_MULTILINE_COMMENT;
	    	}
	    	else{
	            putchar(ch);
		    putchar(next);
	    	}
	    }
    	    else if(ch == '"'){
	        current_state = IN_STRING;
	        putchar(ch);
    	    }

            else if(ch == '\''){
                current_state = IN_CHAR;
                putchar(ch);
            }

	    else{
	        putchar(ch);
	    }
        }

	else if(current_state == IN_SINGLELINE_COMMENT){


		if(ch == '\n'){
		putchar('\n');
		current_state = NORMAL;
	    }
	}

        else if(current_state == IN_MULTILINE_COMMENT){


            if(prev == '*' && ch == '/'){
                current_state = NORMAL;
                prev = 0;
                continue;
            }
        }

        else if(current_state == IN_STRING){

            putchar(ch);

            if(ch == '"' && prev != '\\'){
                current_state = NORMAL;
            }
        }

        else if(current_state == IN_CHAR){

            putchar(ch);

            if(ch == '\'' && prev != '\\'){
                current_state = NORMAL;
            }
        }

        prev = ch;
    }
    fclose(fp);
}
