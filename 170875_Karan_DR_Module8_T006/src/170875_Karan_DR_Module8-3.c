/*
* File Name     : 170875_Karan_DR_Module8-3.c
* Description   : Design and write _flushbuf, fflush, and fclose.
*     _flushbuf : Write buffer to file
*     fflush	: Flush buffer manually
*     fclose	: Flush + close file
* Author        : Karan Sathvara
* Created       : 28-04-2026
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFSIZ 1024
#define EOF     -1
#define OPEN_MAX 20
#define PERMS 0666

/*
* Structure Name: _iobuf
* Description   : contents of structure
*               cnt   : characters left in buffer
                *ptr  : next character position
                *base : buffer start location
                flag  : mode of file access
                fd    : file descriptor
* Author        : Karan Sathvara
* Created       : 28-04-2026
*/

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    int fd;

    struct {
        unsigned int read  : 1;
        unsigned int write : 1;
        unsigned int unbuf : 1;
        unsigned int eof   : 1;
        unsigned int err   : 1;
    } flag;

} FILE;

FILE _iob[OPEN_MAX] = {0};

/*
* Macro Name    : putc
* Description   : If buffer has space then store character otherwise flush/reset buffer and then store it
*/

#define putc(idx, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (idx) : _flushbuf((idx), p))

/*
* Structure Name: _flushbuf
* Description   : writes data into buffer
*		: write old buffer -> clear it -> store new character
* Author        : Karan Sathvara
* Created       : 28-04-2026
*/

int _flushbuf(int ch, FILE *fp)
{
    int16_t n;
    int16_t bufsize;

    if (!(fp->flag.write) || fp->flag.err)
        return EOF;

    bufsize = fp->flag.unbuf ? 1 : BUFSIZ;

    if (fp->base == NULL)
    {
        if ((fp->base = (char *) malloc(bufsize)) == NULL) {
            fp->flag.err = 1;
            return EOF;
        }
	fp->ptr = fp->base;
	fp->cnt = bufsize;
    }

    if (fp->flag.unbuf)
    {
        if (write(fp->fd, &ch, 1) != 1) {
            fp->flag.err = 1;
            return EOF;
        }
        return ch;
    }
    else {
        n = fp->ptr - fp->base;

        if (write(fp->fd, fp->base, n) != n) {
            fp->flag.err = 1;
            return EOF;
        }

        fp->ptr = fp->base;
        fp->cnt = bufsize - 1;
        *fp->ptr++ = ch;

        return ch;
    }
}

/*
* Structure Name: fflush
* Description   : this function will
*               : write buffer's data into the file immediately
*		  n = number of characters currently stored in buffer
* Author        : Karan Sathvara
* Created       : 28-04-2026
*/

int8_t fflush(FILE *fp)
{
    if (fp == NULL)
        return EOF;

    if (fp->flag.write && fp->base != NULL)
    {
        int16_t n = fp->ptr - fp->base;

        if (write(fp->fd, fp->base, n) != n)
 	{
            fp->flag.err = 1;
            return EOF;
        }

        fp->ptr = fp->base;
	fp->cnt = (fp->flag.unbuf) ? 1 : BUFSIZ;
    }

    return 0;
}

/*
* Structure Name: fclose(fp)
* Description   : close the file
*               : write buffer's data into the file immediately
*                 flush data -> free buffer -> reset structure -> close file
* Author        : Karan Sathvara
* Created       : 28-04-2026
*/

int8_t fclose(FILE *fp)
{
    int8_t result = 0;

    if (fp->flag.write){
        result = fflush(fp);
    }

    if (fp->base != NULL){
        free(fp->base);
    }

    fp->cnt = 0;
    fp->ptr = NULL;
    fp->base = NULL;

    fp->flag.read = 0;
    fp->flag.unbuf = 0;
    fp->flag.write = 0;
    fp->flag.eof = 0;
    fp->flag.err = 0;

    return close(fp->fd) == -1 ? EOF : result;
}

/*
* Function Name : FILE *myfopen
* Description   : fopen replacement
*               : this function will opens a file using low-level system calls
                : and initializes a FILE structure so it can be used with buffered I/O
* Flow chart    : Check mode -> Find free slot -> Open file (OS call) -> Initialize FILE structure -> Return pointer
* Author        : Karan Sathvara
* Created       : 28-04-2026
*/

FILE *myfopen(char *name, char *mode)
{
    int8_t fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;

    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
    {
        if (fp -> flag.read == 0 && fp -> flag.write == 0)
            break;
    }

    if (fp >= _iob + OPEN_MAX){
        write(1, "too many files already opened\n", 30);
        return NULL;
    }

    if (*mode == 'w'){
        fd = creat(name, PERMS);
    }
    else if (*mode == 'a')
    {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
        {
            fd = creat(name, PERMS);
        }
        lseek(fd, 0L, 2);
    }
    else{
        fd = open(name, O_RDONLY, 0);
    }

    if (fd == -1){
        write(1, "File can't be opened\n", 21);
        return NULL;
    }

    fp -> fd = fd;
    fp -> cnt = 0;
    fp -> base = NULL;

    fp->flag.read  = (*mode == 'r');
    fp->flag.write = (*mode != 'r');
    fp->flag.unbuf = 0;
    fp->flag.eof   = 0;
    fp->flag.err   = 0;

    return fp;
}

/*
* Function Name : write_in_files
* Description   : This is main function
                : which write in files using myfopen, flushbuf, fflush, fclose
* Author        : Karan Sathvara
* Created       : 28-04-2026
*/

void write_in_files(int8_t argc, char *argv[])
{
    FILE *fp;
    char  buf[BUFSIZ];
    uint16_t idx = 0;
    int16_t n = 0;

    if (argc < 3) {
        write(1, "Usage: ./a.out [filename]\n", 27);
        return;
    }

    fp = myfopen(argv[1], "w");
//    fp1 = myfopen(argv[2], "r");

    if (fp == NULL) {
        write(1, "Error opening file\n", 19);
        return;
    }
/*
    if (fp1 == NULL) {
        write(1, "Error opening file\n", 19);
        return;
    }
*/
    write(1, "Enter input (Ctrl+D to stop):\n", 31);

    while ((n = read(0, buf, sizeof(buf))) > 0)
    {
        for (idx = 0; idx < n; idx++) {
            putc(buf[idx], fp);
        }
    }
    fclose(fp);
}
