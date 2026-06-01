/*
* File Name     : 170875_Karan_DR_Module8-8.c
* Description   : Write a routine bfree(p,n)
*               : that will free any arbitrary block p of n characters into the free list maintained by malloc and free.
*               : By using bfree, a user can add a static or external array to the free list at any time.
* Author        : Karan Sathvara
* Created       : 04-05-2026
*/

#include <stdio.h>
#include <limits.h>
#include "header.h"
#include <unistd.h>

#define MAX_ALLOC 10000
#define NALLOC 1024
#define MAGIC  0x12345678
#define MAXSIZE 1024

/*
* Name 		: union declaration
* Description   : This union contains struct and align member x
                : Align member ensures proper memory alignment.
* Author        : Karan Sathvara
* Created       : 04-05-2026
*/

typedef long Align;

union header {
    struct {
        union header *ptr;
        unsigned size;
        unsigned magic;
    } s;
    Align x;
};

typedef union header Header;

/*
* Name          : union declaration
* Description   : base   : starting point of free list
*  		  *freep : Pointer to free list : Available memory blocks
*/

static Header base;
static Header *freep = NULL;

/* function declarations */
static Header *morecore(unsigned);
void my_free(void *dp);

/*
* Name          : *my_malloc
* Description   : This function will allocates memory from the free list or requests more from OS.
*		: and returns a pointer to usable memory (after the header).
* Detailed      : First my_malloc calls morecore() because free list is empty.
		  morecore() gets memory from OS and adds it to free list.
		  Then malloc continues, finds that block, and allocates from it.
* Author        : Karan Sathvara
* Created       : 04-05-2026
*/

void *my_malloc(unsigned nbytes)
{
    Header *p, *prevp;
    unsigned nunits;

    if (nbytes == 0) {
        printf("malloc: zero size request\n");
        return NULL;
    }

    if (nbytes > UINT_MAX - sizeof(Header)) {
        printf("malloc: overflow size is too large\n");
        return NULL;
    }

    /* convert bytes into units */
    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

    /* initializing free list */
    if ((prevp = freep) == NULL)
    {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
        base.s.magic = MAGIC;
    }

    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {

        if (p->s.size >= nunits) {

            if (p->s.size == nunits) {
                prevp->s.ptr = p->s.ptr;
            } else {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }

            freep = prevp;

            p->s.magic = MAGIC;

            return (void *)(p + 1);
        }

        if (p == freep) {
            if ((p = morecore(nunits)) == NULL)
                return NULL;
        }
    }
}

/*
* Name          : *morecore
* Description   : Gets more memory from the OS and adds it to the free list.
*               : Then returns the updated free list so malloc can use it.
* Author        : Karan Sathvara
* Created       : 04-05-2026
*/

static Header *morecore(unsigned nunit)
{
    char *cp;
    Header *up;

    if (nunit < NALLOC){
        nunit = NALLOC;
    }

    cp = sbrk(nunit * sizeof(Header));

    if (cp == (char *) -1){
        return NULL;
    }

    up = (Header *) cp;
    up->s.size = nunit;
    up->s.magic = MAGIC;

    my_free((void *)(up + 1));
    return freep;
}

/*
* Name          : my_free
* Description   : Frees a previously allocated block and puts it back into the free list.
* Author        : Karan Sathvara
* Created       : 04-05-2026
*/

void my_free(void *dp)
{
    Header *bp, *p;

    if (dp == NULL) {
        printf("free: null pointer\n");
        return;
    }

    bp = (Header *)dp - 1;

    if (bp->s.size == 0 || bp->s.magic != MAGIC) {
        printf("free: invalid or corrupted block\n");
        return;
    }

    /* This block is valid and correctly allocated */
    bp->s.magic = 0;

    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;
    }

    /* A < B < C */
    /* B touching C if yes merge them and Skip C in free list */
    if (bp + bp->s.size == p->s.ptr)
    {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    }
    /* if not touching connect B -> C */
    else {
        bp->s.ptr = p->s.ptr;
    }

    /* A < B < C */
    /* A directly touching B if yes merge them and Skip B/BC in free list */
    if (p + p->s.size == bp)
    {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    }
    /* if not touching A -> B */
    else {
        p->s.ptr = bp;
    }

    freep = p;
}

/*
* Name          : bfree
* Description   : this function uses existing memory given by user if needs extra use morecore
* Author        : Karan Sathvara
* Created       : 04-05-2026
*/

void bfree(void *p, unsigned nbytes)
{
    Header *bp;

    if (nbytes < sizeof(Header)) {
        printf("bfree: block too small\n");
	printf("Using morecore\n");
        return;
    }

    /* starting free list */
    if (freep == NULL) {
        base.s.ptr = freep = &base;
        base.s.size = 0;
        base.s.magic = MAGIC;
    }

    /* convert raw memory Header|Data */
    bp = (Header *)p;

    bp->s.size = nbytes / sizeof(Header);

    bp->s.magic = MAGIC;

    my_free((void *)(bp + 1));
}

/*
* Name          : *call_malloc
* Description   : validate input and call my_malloc
* Author        : Karan Sathvara
* Created       : 04-05-2026
*/

void *call_malloc(unsigned nbytes) {

    if (nbytes <= 0 || nbytes > MAX_ALLOC) {
        printf("\tInvalid allocation size %u bytes.\n", nbytes);
        return NULL;
    }

    void *ptr = my_malloc(nbytes);

    if (ptr != NULL)
        printf("\tSuccessful allocation of %u bytes.\n", nbytes);
    else
        printf("\tAllocation failed.\n");

    return ptr;
}

/*
* Name          : modified_malloc
* Description   : added validation in malloc and free to work efficiently
* Author        : Karan Sathvara
* Created       : 04-05-2026
*/

void malloc_with_bfree() {

    static char buffer[MAXSIZE];
    int bufSize = 0;

    printf("Enter buffer for using bfree : ");
    scanf("%d", &bufSize);

    if (bufSize <= 0 || bufSize > MAXSIZE) {
        printf("Invalid buffer size\n");
        return;
    }

    bufSize = (unsigned)bufSize;

    bfree(buffer, bufSize);

    unsigned int size = 0;

    printf("Enter size : ");
    scanf("%u", &size);

    void *p1 = call_malloc(size);

    if (p1){
        my_free(p1);
    }
}
