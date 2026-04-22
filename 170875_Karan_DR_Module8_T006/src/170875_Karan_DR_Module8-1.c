/*
* File Name     : 170875_Karan_DR_Module8-1.c
* Description   : Rewrite the program cat from Chapter 7
                : using read, write, open, and close instead of their standard library equivalents.
		: Perform experiments to determine the relative speeds of the two versions.
* earlier 	: fopen -> fgets -> printf -> close
* current	: open -> read -> write -> close
* Author        : Karan Sathvara
* Created       : 00-04-2026
*/

#include <stdio.h>
#include "header.h"
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024

/*
* Function Name : file_write
* Description   : this function will write file's content without using fopen, fgets, printf
*		: fd : file Descriptors , n : no of bytes stored
* Author        : Karan Sathvara
* Created       : 20-04-2026
*/

void file_write(int8_t argc, char *argv[]) {

    int8_t fd;
    int16_t n;
    char buf[BUFSIZE];

    if(argc == 1){
        while ((n = read(0, buf, BUFSIZE)) > 0) {
            write(1, buf, n);
        }
	return;
    }

    while (--argc > 0) {
        fd = open(*++argv, O_RDONLY);

        if (fd < 0) {
            write(2, "Error opening file\n", 19);
            continue;
        }

        while ((n = read(fd, buf, BUFSIZE)) > 0) {
            write(1, buf, n);
        }

        close(fd);
    }
}
