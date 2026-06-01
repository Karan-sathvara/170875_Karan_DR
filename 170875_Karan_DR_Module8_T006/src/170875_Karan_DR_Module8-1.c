/*
* File Name     : 170875_Karan_DR_Module8-1.c
* Description   : Rewrite the program cat from Chapter 7
                : using read, write, open, and close instead of their standard library equivalents.
                : Perform experiments to determine the relative speeds of the two versions.
* earlier       : fopen -> fgets -> printf -> close
* current       : open -> read -> write -> close
* Author        : Karan Sathvara
* Created       : 23-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024

/*
* Function Name : sysCall_cat
* Description   : this function will write file's content without using fopen, fgets, printf
*               : fd : file Descriptors , n : no of bytes stored
* Library used  : fcntl  : file control (fd : file descriptor for opening file)
                : unistd : unix standard header file for system calls (read, write, close)
* fd            : is integer number that the OS uses to represent an open file.
* Author        : Karan Sathvara
* Created       : 23-04-2026
*/

void sysCall_cat(int8_t argc, char *argv[]) {

    int8_t fd = 0;
    char buf[BUFSIZE];
    ssize_t written = 0, n = 0;

    if(argc == 1){

	printf("Enter input : \n");
        while ((n = read(0, buf, BUFSIZE)) > 0) {
            write(1, buf, n);
        }
        return;
    }

    for (int8_t idx = 1; idx < argc; idx++)
    {
        fd = open(argv[idx], O_RDONLY);

	printf("------------------------\n");
	printf("%s Content\n", argv[idx]);

        if (fd < 0){
            write(1, "Error opening file\n", 19);
            continue;
        }

        while ((n = read(fd, buf, BUFSIZE)) > 0)
	{
	    ssize_t total = 0;
            while (total < n)
	    {
                written = write(1, buf + total, n - total);

                if (written <= 0){
		    break;
		}
                total += written;
            }
        }
        if (n < 0) {
            write(2, "Read error\n", 11);
        }
        close(fd);
    }
}
