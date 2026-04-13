/*
* File Name     : 170875_Karan_DR_Module5-6.c
* Description   : Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing.
*               : strindex
*               : getop
*		: getline
*               : reverse
*               : atoi : character to integer
*		: itoa : integer to character
* Author        : Karan Sathvara
* Created       : 31-03-2026
*/

#include <stdio.h>
#include "header.h"
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "function.h"
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

int sp = 0;
double stack[MAXVAL];

void push(double f){
    if (sp < MAXVAL){
        *(stack + sp++) = f;
    }
    else{
        printf("stack is full\n");
        return;
    }
}

double pop(void){
    if (sp > 0)
        return *(stack + --sp);
    else {
        printf("stack is empty\n");
        return 0;
    }
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    if(bufp > 0){
        return *(buf + --bufp);
    }
    else{
        return getchar();
    }
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
        return;
    }
    else{
        *(buf + bufp++) = c;
    }
}

int getop(char *s){

    int c;

    while ((c = getch()) == ' ' || c == '\t');

    *s = c;
    *(s + 1) = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    /* handle minus sign */
    if (c == '-') {
        int next = getch();
        if (!isdigit(next) && next != '.') {
            ungetch(next);
            return '-';
        }
        *s++ = c;
        c = next;
    }
    /* store first digit */
    if (isdigit(c) || c == '.'){
        *s++ = c;
    }

    while (isdigit(c = getch())){
        *s++ = c;
    }

    if (c == '.'){
        *s++ = c;
        while (isdigit(c = getch()))
            *s++ = c;
    }

    *s = '\0';

    if (c != EOF){
        ungetch(c);
    }
    return NUMBER;
}


void RPN_using_ptr(){

    int type;
    double op2;
    char s[MAXOP];

    printf("Enter digits for operation : ");
    while ((type = getop(s)) != EOF) {

        switch (type) {
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '*':
            push(pop() * pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '/':
            op2 = pop();

            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("zero divisor\n");
        break;

        case '%':
            op2 = pop();
            if (op2 != 0.0)
            push((int)pop() % (int)op2);

        else
            printf("zero divisor\n");
        break;

        case '\n':
            printf("Result : %.8g\n", pop());
            break;

        default:
            printf("Unknown command %s\n", s);
            return;
        }
    }
}



void getline_using_ptr(char *str1, int16_t max){

    int8_t idx = 0;
    int16_t ch;

    while(idx < max - 1 && (ch = getchar()) != EOF && ch != '\n'){
	*(str1 + idx) = ch;
	idx++;
    }

    *(str1 + idx) = '\0';

    printf("Entered string is : %s\n", str1);
}



void reverse_using_ptr(char *str1){

    char *input = str1;

    char *start = str1;
    char *end = str1;

    while(*end != '\0'){
	end++;
    }
    end--;

    while(start < end){
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
    printf("Output string is : %s\n", input);
}

void itoa_using_ptr(int16_t digit, char *str1){

    int16_t integer = 0;
    int16_t sign = digit;

    if(digit < 0)
        digit = -digit;

    do {
        *(str1 + integer) = (digit % 10) + '0';
        integer++;
        digit = digit / 10;
    } while(digit > 0);

    if(sign < 0){
        *(str1 + integer) = '-';
        integer++;
    }

    *(str1 + integer) = '\0';

    reverse_using_ptr(str1);

}

void atoi_using_ptr(char *str1) {

    char *input = str1;

    int16_t result = 0;
    int8_t sign = 1;

    while (*str1 == ' ' || *str1 == '\t'){
	str1++;
    }

    if (*str1 == '-') {
        sign = -1;
        str1++;
    } else if (*str1 == '+') {
        str1++;
    }

    input = str1;

    while(*input != '\0'){
	if(!isdigit(*input)){
            printf("Invalid input\n");
            return;
	}
	input++;
    }

    while (*str1 >= '0' && *str1 <= '9') {
        result = result * 10 + (*str1 - '0');
        str1++;
    }

    int16_t answer = result * sign;

    printf("Output is : %hd\n", answer);
}

void strindex_using_ptr(char *str1, char *str2){

    int16_t len1;
    int16_t len2;
    int16_t idxi;
    int16_t idxj;

    len1 = strlen(str1);
    len2 = strlen(str2);

    for(idxi = len1 - len2; idxi >= 0; idxi--){
            for(idxj = 0; idxj < len2; idxj++){
                if(tolower(*(str1 + idxi + idxj)) != tolower(*(str2 + idxj))){
                    break;
                }
            }
            if(idxj == len2){
                printf("substring %s found at index: %d from rightmost\n",str2 , len1 - idxi);
                return;
            }
    }

    printf("No substring found\n");

}


void pointer_versions_of_Functions(){

    char str1[1000];
    char str2[1000];
    int8_t choice;

    int16_t digit;
    char extra;

    printf("\t1.strindex using pointer\n");
    printf("\t2.string reverse using pointer\n");
    printf("\t3.itoa using ptr\n");
    printf("\t4.atoi using ptr\n");
    printf("\t5.getline using ptr\n");
    printf("\t6.RPN using ptr\n");

    printf("Enter choice : ");
    scanf("%hhd", &choice);

    switch(choice){
        case 1 :
            while(getchar() != '\n');
	    printf("Enter first string : ");
            fgets(str1, sizeof(str1), stdin);

            printf("Enter second string : ");
            fgets(str2, sizeof(str2), stdin);

	    str1[strlen(str1)-1] = '\0';
	    str2[strlen(str2)-1] = '\0';

            strindex_using_ptr(str1, str2);
            break;

        case 2 :
	    while(getchar() != '\n');
            printf("Enter input string : ");
            fgets(str1, sizeof(str1), stdin);
	    str1[strlen(str1)-1] = '\0';

	    reverse_using_ptr(str1);
            break;

        case 3 :
    	    printf("Enter digit : ");

    	    if (scanf("%hd%c", &digit, &extra) != 2 || extra != '\n') {
        	printf("Invalid input\n");
        	while(getchar() != '\n');
        	return;
    	    }

	    itoa_using_ptr(digit, str1);
            break;

        case 4 :
            while(getchar() != '\n');
            printf("Enter first string : ");
            fgets(str1, sizeof(str1), stdin);
            str1[strlen(str1)-1] = '\0';

	    atoi_using_ptr(str1);
            break;

        case 5 :
	    while(getchar() != '\n');
            printf("Enter input string : ");
            getline_using_ptr(str1, sizeof(str1));
            break;

        case 6 :
	    while(getchar() != '\n');
	    RPN_using_ptr();
            break;

        default :
            printf("Invalid Choice\n");
    }
}

