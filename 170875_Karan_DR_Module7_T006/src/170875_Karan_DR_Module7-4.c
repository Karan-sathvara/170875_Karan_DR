/*
* File Name     : 170875_Karan_DR_Module7-4.c
* Description   : Write a private version of scanf similar to minprintf from the previous section.
* Task 		: The custom minscanf function should process a format string and read input based on the specified format.
* Author        : Karan Sathvara
* Created       : 21-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <stdarg.h>

/*
* Function Name : minprintf
* Description   : this function will mimics standard printf function

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
    unsigned int Uval = 0;

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
            else {
                putchar('l');
                putchar(*ptr);
            }
            break;

        case 'c':
            iChar = va_arg(arg_ptr, int);
            printf("%c", iChar);
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
* Function Name : minscanf
* Description   : this function will mimics standard scanf function
*		: iterates through the format string, identifies format specifiers,
		: and reads input based on the specifier using scanf.
* Author        : Karan Sathvara
* Created       : 21-04-2026
*/

void minscanf(char *fstr, ...)
{
    va_list arg_ptr;
    char *ptr;

    va_start(arg_ptr, fstr);

    for (ptr = fstr; *ptr != '\0'; ptr++) {

        if (*ptr != '%') {
            continue;
        }

        switch (*++ptr) {

        case 'd': {
            int *ival = va_arg(arg_ptr, int *);
            scanf("%d", ival);
            break;
        }

        case 'u': {
            unsigned int *uval = va_arg(arg_ptr, unsigned int *);
            scanf("%u", uval);
            break;
        }

        case 'f': {
            float *fval = va_arg(arg_ptr, float *);
            scanf("%f", fval);
            break;
        }

	case 'l':
	    ptr++;
	    if(*ptr == 'f'){
                double *Dval = va_arg(arg_ptr, double *);
                scanf("%lf", Dval);
	    }
	    else {
                putchar('l');
                putchar(*ptr);
	    }
	    break;

        case 'c': {
            char *cval = va_arg(arg_ptr, char *);
            scanf(" %c", cval);
            break;
        }

        case 's': {
            char *sval = va_arg(arg_ptr, char *);
            scanf("%s", sval);
            break;
        }

        default:
            break;
        }
    }

    va_end(arg_ptr);
}

/*
* Function Name : custom_minscanf
* Description   : internally uses minprintf and scanf takes input from user and print
                : this is main function control execution of program
* Author        : Karan Sathvara
* Created       : 21-04-2026
*/

void custom_minscanf()
{
    int i = 0;
    float f = 0.0;
    unsigned int ui = 0;
    double d = 0.0;
    char c;
    char str[100];

    printf("Enter Integer : ");
    minscanf("%d", &i);

    printf("Enter Float : ");
    minscanf("%f", &f);

    printf("Enter Double : ");
    minscanf("%lf", &d);

    printf("Enter Unsigned Integer : ");
    minscanf("%u", &ui);

    printf("Enter Character : ");
    minscanf(" %c", &c);

    printf("Enter String : ");
    minscanf("%s", str);

    printf("\n");
    minprintf("Entered Integer is : %d\n", i);
    minprintf("Entered Float is : %f\n", f);
    minprintf("Entered Double is : %lf\n", d);
    minprintf("Entered Unsigned integer is : %u\n", ui);
    minprintf("Entered Character is : %c\n", c);
    minprintf("Entered String is : %s\n", str);
}
