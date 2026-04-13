/*
* File Name     : 170875_Karan_DR_Module3-3.c
* Description   : Write a function expand(s1,s2) that expands shorthand notation
*                - like a-z in the string s1 into the equivalent complete list abc...xyz in s2
*                -  Allow for letters of either case and digits
* Author        : Karan Sathvara
* Created       : 25-02-2026
*/


#include <stdio.h>
#include "header.h"
#include <stdint.h>
#include <string.h>

/*
* Function Name : leading_dash
* Description   : This function removes leading dash
* input		: --------Karan
* output	: Karan
* Author        : Karan Sathvara
* Created       : 25-02-2026
*/

void leading_dash(char str[]){

        int16_t count = 0;
        while(str[count] == '-'){
            count++;
        }
        if(count != 0){
            int16_t idx=0;
            while(str[idx + count] != '\0'){
                str[idx]= str[idx + count];
                    idx++;
            }
            str[idx] = '\0';
        }
}

/*
* Function Name : trailing_dash
* Description   : This function removes trailing dash
* input         : Karan---------
* output        : Karan
* Author        : Karan Sathvara
* Created       : 25-02-2026
*/

void trailing_dash(char str[]){

        int16_t len;
        int16_t idx = 0;

        len = strlen(str);
        idx = len - 1;
        if(str[idx] == '\n'){
            idx--;
        }
        while(str[idx] == '-'){
            idx--;
        }
        str[idx+2] = '\0';
}

/*
* Function Name : expand
* Description   : This function expands notations
* input         : 0-9
* output        : 0123456789
* Author        : Karan Sathvara
* Created       : 25-02-2026
*/

void expand(){

    char str[1000];
    int16_t index = 0;
    printf("Enter input string: ");

    while(fgets(str, sizeof(str), stdin) != NULL){

        trailing_dash(str);
        leading_dash(str);

	for(index=0; str[index] != '\0'; index++){
	    if(str[index+1] == '-' && str[index+2] != '\0'){

		char start = str[index];
		char end = str[index+2];

		if ((start >= '0' && start <= '9' && end >= '0' && end <= '9') ||
                   (start >= 'A' && start <= 'Z' && end >= 'A' && end <= 'Z') ||
		   (start >= 'a' && start <= 'z' && end >= 'a' && end <= 'z')){

		    char final_end = end;
                    int16_t temp_idx = index + 2;
	            while(str[temp_idx + 1] == '-' && str[temp_idx + 2] != '\0'){

		        char next = str[temp_idx + 2];

                        if ((start >= '0' && start <= '9' && next >= '0' && next <= '9') ||
                           (start >= 'A' && start <= 'Z' && next >= 'A' && next <= 'Z') ||
                           (start >= 'a' && start <= 'z' && next >= 'a' && next <= 'z')){

   		            final_end = next;
		            temp_idx += 2;
		        }
		        else{
			    break;
 		        }
		    }

		    if(start <= final_end){
  		        for(char ch=start; ch<=final_end; ch++){
			    printf("%c", ch);
		        }
		    }
		    else{
                        for(char ch=start; ch>=final_end; ch--){
                            printf("%c", ch);
                        }
		    }
		    index = temp_idx;
                    continue;
                }

            }
	printf("%c", str[index]);

	}
    }

}



