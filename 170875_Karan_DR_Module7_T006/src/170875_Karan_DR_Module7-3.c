/*
* File Name     : 170875_Karan_DR_Module7-3.c
* Description   : Revise minprintf to handle more of the other facilities of printf.
* 		: minprintf function mimics standard printf function
* Task 		: but minprintf supports only %d, %f, %s only we have to modify for more functionality
* Author        : Karan Sathvara
* Created       : 21-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <stdarg.h>

/*
* Function Name : minprintf
* Description   : this function will mimics standard printf function
                : this is extended version which provides more functionalities

* stdarg.h lib  :
		va_list  : pointer to argument
		va_arg   : Fetches the next argument and moves pointer forward
		va_start : initialization : points to last unnamed argument
		va_end   : finishes using variable arguments

* Author        : Karan Sathvara
* Created       : 21-04-2026
*/

void minprintf(char *fstr, ...)
{
    va_list arg_ptr;

    char *ptr, *Sval, iChar;
    int Ival = 0;
    float Fval = 0.0;
    double Dval = 0.0;
    long int Lval = 0;
    unsigned int Uval = 0;
    unsigned long int uLval = 0;
    void *iptr = NULL;

    va_start(arg_ptr, fstr);

    for (ptr = fstr; *ptr != '\0'; ptr++) {
        if (*ptr != '%') {
            putchar(*ptr);
            continue;
        }

        switch (*++ptr) {

        case 'd':
            Ival = va_arg(arg_ptr, int);
            printf("%d", Ival);
            break;

        case 'u':
            Uval = va_arg(arg_ptr, unsigned int);
            printf("%u", Uval);
            break;

        case 'f':
            Fval = va_arg(arg_ptr, double);
            printf("%f", Fval);
            break;

        case 'l':
	    ptr++;
            if(*ptr == 'f'){
                Dval = va_arg(arg_ptr, double);
                printf("%lf", Dval);
            }
	    else if(*ptr == 'd'){
	        Lval = va_arg(arg_ptr, long);
                printf("%ld", Lval);
	    }
            else if(*ptr == 'u'){
                uLval = va_arg(arg_ptr, unsigned long);
                printf("%lu", uLval);
            }
    	    else {
		putchar('l');
		putchar(*ptr);
    	    }
    	    break;

        case 'c':
            iChar = va_arg(arg_ptr, int);
            printf("%c", iChar);
            break;

        case 'p':
            iptr = va_arg(arg_ptr, void *);
            printf("%p", iptr);
            break;

        case 's':
            for (Sval = va_arg(arg_ptr, char *); *Sval != '\0'; Sval++){
                putchar(*Sval);
	    }
            break;

        default:
            putchar(*ptr);
            break;
        }
    }

    va_end(arg_ptr);
}

/*
* Function Name : extended_minprintf
* Description   : this function will have all features of printf
                : added : %p, %ld, %lf, %lu, %c, %u
* Author        : Karan Sathvara
* Created       : 21-04-2026
*/

void extended_minprintf()
{

    int8_t x = 10;

    minprintf("\tInteger : %d %d\n", 10, 20);
    minprintf("\tFloat : %f\n", 12.54);
    minprintf("\tlong int : %ld\n", 12345678);
    minprintf("\tDouble : %lf\n", 82.67890);
    minprintf("\tunsigned long int : %lu\n", 9898207382);
    minprintf("\tchar : %c\n", 'a');
    minprintf("\tHello %s\n", "Karan");
    minprintf("\tpointer : %p\n", &x);
    minprintf("\tunsigned int : %u\n", 12);

}
