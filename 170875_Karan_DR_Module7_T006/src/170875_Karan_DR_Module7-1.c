/*
* File Name     : 170875_Karan_DR_Module7-1.c
* Description   : Write a program that converts upper case to lower or lower case to upper,
		: depending on the name it is invoked with, as found in argv[0].
* Author        : Karan Sathvara
* Created       : 20-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <ctype.h>
#include "string.h"

/*
* Function Name : converter
* Description   : this function will convert Upper string to lower and lower to upper
* Author        : Karan Sathvara
* Created       : 20-04-2026
*/

void converter(char *str, int8_t flag){

    char output_str[100];
    int8_t idx = 0;

    while (*str != '\0'){
	if(flag){
	    output_str[idx] = toupper(*str);
	}
	else{
            output_str[idx] = tolower(*str);
	}
	str++;
	idx++;
    }
    output_str[idx] = '\0';

    printf("%s\n",output_str);

}

/*
* Function Name : case_reverse
* Description   : this function will take input from user & control flow
* Author        : Karan Sathvara
* Created       : 20-04-2026
*/

void case_reverse(int8_t argc, char *argv[]){

    if(argc != 2){
	printf("Usage : Exercise_7_1 <upper|lower>\n");
	return;
    }

    if (strcmp(argv[1], "lower") != 0 && strcmp(argv[1], "upper") != 0) {
        printf("Invalid input\n");
	printf("Usage : Exercise_7_1 <upper|lower>\n");
        return;
    }

    char str[100];

    printf("Enter input : \n");
    fgets(str, sizeof(str), stdin);

    if (strcmp(argv[1], "lower") == 0) {
	converter(str, 0);
    }
    else if (strcmp(argv[1], "upper") == 0) {
        converter(str, 1);
    }
}
