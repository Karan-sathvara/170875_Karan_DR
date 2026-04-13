/*
* File Name     : 170875_Karan_DR_Module3-1.c
* Description   : Our binary search makes two tests inside the loop,
*                -  when one would suffice (at the price of more tests outside)
*   		 -  Write a version with only one test inside the loop and measure the difference in run-time.
* Author        : Karan Sathvara
* Created       : 24-02-2026
*/

#include <stdio.h>
#include "header.h"

void binarysearch(){

    int16_t index;
    int16_t number;
    int16_t element;

    printf("Enter the number of Elements: ");
    scanf("%hd", &number);

    int arr[number];

    for(index = 0; index < number; index++){
	scanf("%d", &arr[index]);
    }

    for(index = 0; index < number - 1; index++){
        if(arr[index] > arr[index + 1]){
	    printf("Array is not sorted\n");

	    char choice;
	    printf("Do you want to sort Array? (y/n)\n");
	    scanf(" %c", &choice);

 	    if(choice == 'y' || choice == 'Y') {
		for(index = 0; index < number - 1; index++){
		    int16_t smallestidx = index;
		    int16_t idxj;
		    for(idxj = index+1; idxj < number; idxj++){
			if(arr[idxj] < arr[smallestidx]){
			    smallestidx = idxj;
			}
		    }

		    int16_t temp;
		    temp = arr[index];
		    arr[index] = arr[smallestidx];
		    arr[smallestidx] = temp;
		}
	    }

	    else{
	        printf("Binary search required sorted array\n");
		return;
	    }
	}
    }
    printf("Array is sorted\n");

    printf("Your array is: ");
    for(index = 0; index < number; index++){
        printf("%d ", arr[index]);
    }


    int16_t size = sizeof(arr)/sizeof(arr[0]);
    printf("\nArray size is: %d\n", size);

    printf("Enter Element to find: ");
    scanf("%hd", &element);

    int16_t low = 0;
    int16_t high = size - 1;
    int16_t mid;

    while(low <= high){
	mid = (low + high)/2;

	if(arr[mid] < element){
	    low = mid + 1;
	}

	else{
	    high = mid - 1;
	}

    }

    if(arr[mid] == element){
        printf("Element %d found in array at index : %d\n",element, mid);
        return;
    }
    else{
	printf("Element is not found in array\n");
    }
}







