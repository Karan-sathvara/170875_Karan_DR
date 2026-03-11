/*
* File Name     : 170875_Karan_DR_Module4-14.c
* Description   : Define a macro swap(t,x,y)
*		- that interchanges two arguments of type t. (Block structure will help.)
* Author        : Karan Sathvara
* Created       : 00-03-2026
*/

#include <stdio.h>
#include "header.h"

#define swap(t,x,y) \
do{ \
    t temp; \
    temp = x; \
    x = y; \
    y = temp; \
} while(0)

/*
* Function Name : swap_elements
* Description   : this function will swap two elements
* Expected input:  x = A , y = B
* Expected output: x = B , y = A
* Author        : Karan Sathvara
* Created       : 09-03-2026
*/

void swap_elements(){

    int8_t choice;

    printf("1. swap integers\n");
    printf("2. swap characters\n");
    printf("3. swap floating integers\n");

    printf("Enter choice : ");
    scanf("%hhd", &choice);

    switch(choice){

	case 1:{
	    int a,b;
	    printf("Enter two integers: ");
	    scanf("%d %d", &a, &b);

	    if(scanf("%d %d",&a,&b) != 2){
        	printf("Invalid integer input\n");
        	break;
    	    }
            swap(int,a,b);

            printf("After swap: %d %d\n",a,b);
            break;
        }

        case 2:{
            char a,b;
            printf("Enter two characters: ");

            if(scanf(" %c %c",&a,&b) != 2){
                printf("Invalid character input\n");
                break;
            }
            swap(char,a,b);

            printf("After swap: %c %c\n",a,b);
            break;
        }

        case 3:{
            float a,b;
            printf("Enter two floating integers: ");
            scanf("%f %f", &a, &b);

            if(scanf("%f %f",&a,&b) != 2){
                printf("Invalid float input\n");
                break;
            }
            swap(float,a,b);

            printf("After swap: %f %f\n",a,b);
            break;
        }
        default:
            printf("Invalid choice\n");
     }
}
