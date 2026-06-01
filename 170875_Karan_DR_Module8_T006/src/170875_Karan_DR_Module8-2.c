/*
* File Name     : 170875_Karan_DR_Module8-2.c
* Description   : Rewrite fopen and _fillbuf with fields instead of explicit bit operations.
* 		: Compare code size and execution speed.
* Author        : Karan Sathvara
* Created       : 27-04-2026
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define EOF     -1
#define BUFSIZ  1024
#define OPEN_MAX 20
#define PERMS 0666

/*
* Structure Name: _iobuf
* Description   : contents of structure
*	        cnt   : characters left in buffer
	        *ptr  : next character position
		*base : buffer start location
		flag  : mode of file access
		fd    : file descriptor
* Author        : Karan Sathvara
* Created       : 27-04-2026
*/

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    int8_t fd;

    struct {
        uint8_t read  : 1;
        uint8_t write : 1;
        uint8_t unbuf : 1;
        uint8_t eof   : 1;
        uint8_t err   : 1;
    } flag;

} FILE;

FILE _iob[OPEN_MAX] = {0};

int _fillbuf(FILE *fp);

/*
* Macro Name    : getc
* Description   : tries to read from buffer if buffer is empty call fillbuf
*/

#define getc(p) (--(p)->cnt >= 0 ? (unsigned char)*(p)->ptr++ : _fillbuf(p))

/*
* Function Name : _fillbuf
* Description   : fill buffer
*		: This function fills the buffer from the file and returns the next character,
		: or EOF if no data is available.
* Author        : Karan Sathvara
* Created       : 27-04-2026
*/

int _fillbuf(FILE *fp)
{
    uint16_t bufsize;

    if (!(fp->flag.read) || fp->flag.eof || fp->flag.err){
        return EOF;
    }

    bufsize = (fp->flag.unbuf) ? 1 : BUFSIZ;

    if (fp->base == NULL)
    {
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;
    }

    fp->ptr = fp->base;

    fp->cnt = read(fp->fd, fp->ptr, bufsize);

    if (--fp->cnt < 0)
    {
        if (fp->cnt == -1)
	{
	    fp->flag.eof = 1;
	}
        else
	{
	    fp->flag.err = 1;
	}
        fp->cnt = 0;
        return EOF;
    }

    return (unsigned char) *fp->ptr++;
}

/*
* Function Name : FILE *myfopen
* Description   : fopen replacement
*               : this function will opens a file using low-level system calls
                : and initializes a FILE structure so it can be used with buffered I/O
* Flow chart    : Check mode -> Find free slot -> Open file (OS call) -> Initialize FILE structure -> Return pointer
* Author        : Karan Sathvara
* Created       : 27-04-2026
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
        write(1, "Too many files already opened\n", 30);

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
    fp->ptr = NULL;

    fp->flag.read  = (*mode == 'r');
    fp->flag.write = (*mode != 'r');
    fp->flag.unbuf = 0;
    fp->flag.eof   = 0;
    fp->flag.err   = 0;

    return fp;
}

/*
* Function Name : fopen_with_fields
3* Description   : This is main function
                : which implement fopen and fillbuff with fields instead of bitfields
* Author        : Karan Sathvara
* Created       : 27-04-2026
*/

void fopen_with_fields(int argc, char *argv[])
{
    FILE *fp;
    int16_t ch = 0;

    if (argc < 2) {
        write(1, "Usage: ./a.out file\n", 21);
        return;
    }

    fp = myfopen(argv[1], "r");

    if (fp == NULL) {
        write(2, "Error opening file\n", 19);
        return;
    }

    while ((ch = getc(fp)) != EOF) {
        write(1, &ch, 1);
    }
}
