/*
* File Name     : 170875_Karan_DR_Module5-5.c
* Description   : Write a Function
* strncpy       : strncpy : copies at most n characters from one to another
* strncat       : strncat : concatenates at most n characters from one to another
* strncmp       : strncmp : compare at most n characters from one to another
* Author        : Karan Sathvara
* Created       : 30-03-2026
*/

#include <stdio.h>
#include "header.h"
#include <string.h>

/*
* Function Name : my_strncpy
* Description   : this function copies at most n characters from one to another
* Author        : Karan Sathvara
* Created       : 30-03-2026
*/

void my_strncpy(char *str1, char *str2, int8_t n){

    char *start = str1;

    while(n-- && *str2 != '\0'){
	*str1++ = *str2++;
    }
    printf("Updated string 1 is : %s\n", start);
}

/*
* Function Name : my_strncat
* Description   : this function concatenates at most n characters from one to another
* Author        : Karan Sathvara
* Created       : 30-03-2026
*/

void my_strncat(char *str1, char *str2, int8_t n){

    char *start = str1;

    while(*str1 != '\0'){
	str1++;
    }

    while(n-- && *str2 != '\0'){
        *str1++ = *str2++;
    }
    *str1 = '\0';

    printf("Updated string 1 is : %s\n", start);
}

/*
* Function Name : my_strncmp
* Description   : this function compare at most n characters from one to another
* Author        : Karan Sathvara
* Created       : 30-03-2026
*/

void my_strncmp(char *str1, char *str2, int8_t n){

    while(n-- > 0){
	if(*str1 != *str2){
	    printf("No match found\n");
	    return;
	}

	if(*str1 == '\0'){
	    break;
	}

	str1++;
	str2++;
    }
    printf("Match Found\n");
}

/*
* Function Name : versions_of_libFunctions
* Description   : this function uses strncmp , strncat, strncpy pointer version
* Author        : Karan Sathvara
* Created       : 30-03-2026
*/

void versions_of_libFunctions(){

    char str1[1000];
    char str2[1000];
    int8_t n;
    int8_t choice;

    printf("Enter first string : ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string : ");
    fgets(str2, sizeof(str2), stdin);

    printf("Enter value of n : ");
    scanf("%hhd", &n);

    str1[strlen(str1)-1] = '\0';
    str2[strlen(str2)-1] = '\0';

    printf("\t1.String Copy\n");
    printf("\t2.String Concatenate\n");
    printf("\t3.String Compare\n");

    printf("Enter choice : ");
    scanf("%hhd", &choice);

    switch(choice){
	case 1 :
	    my_strncpy(str1, str2, n);
	    break;

        case 2 :
            my_strncat(str1, str2, n);
            break;

        case 3 :
            my_strncmp(str1, str2, n);
            break;

	default :
	    printf("Invalid Choice\n");
    }
}

