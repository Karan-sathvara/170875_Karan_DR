/*
* File Name     : 170875_Karan_DR_Module8-7.c
* Description   : malloc accepts a size request without checking its plausibility/valid
		: free believes that the block it is asked to free contains a valid size field.
		: Improve these routines so they make more pains with error checking.
* Author        : Karan Sathvara
* Created       : 04-05-2026
*/

#include <stdio.h>
#include <limits.h>
#include "header.h"
#include <unistd.h>

#define MAX_PTRS 10
#define MAX_ALLOC 10000
#define NALLOC 1024
#define MAGIC  0x12345678

void *ptrs[MAX_PTRS] = {0};

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
* Name          : modified_malloc
* Description   : added validation in malloc and free to work efficiently
* Author        : Karan Sathvara
* Created       : 04-05-2026
*/

void modified_malloc() {

    int8_t choice = 0;
    unsigned size = 0;
    int8_t index = 0;

    while (1) {

        printf("\n1. Add size\n2. Free\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%hhd", &choice);

        switch (choice) {

        case 1:
            printf("Enter size: ");
            scanf("%u", &size);

            if (size > MAX_ALLOC) {
                printf("\tInvalid allocation size %u bytes.\n", size);
                break;
            }

            for (index = 0; index < MAX_PTRS; index++) {
                if (ptrs[index] == NULL) {
                    ptrs[index] = my_malloc(size);
                    if (ptrs[index]){
                        printf("\tAllocated at index %d\n", index);
		    }
                    break;
                }
            }

            if (index == MAX_PTRS){
                printf("\tPointer storage full\n");
	    }
            break;

        case 2:
            printf("Enter index to free: ");
            scanf("%hhd", &index);

            if (index < 0 || index >= MAX_PTRS || ptrs[index] == NULL) {
                printf("\tInvalid pointer passed to free.\n");
            }
	    else{
                my_free(ptrs[index]);
                ptrs[index] = NULL;
                printf("\tFreed index %d\n", index);
            }

            break;

        case 3:
	    return;

        default:
            printf("\tInvalid choice\n");
        }
    }
}

