/*
* File Name     : 170875_Karan_DR_Module6-4.c
* Description   : Write a program
                : that prints the distinct words in its input sorted into decreasing order of frequency of occurance.
*               : Precede each word by its count.
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

#include <stdio.h>
#include "header.h"
#include "function.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode *arr[100];
int8_t idx = 0;

/*
* Description   : array of pointers
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

char *noise[] = {
    "a", "an", "the", "i", "am", "is", "are", "was", "were",
    "to", "of", "in", "on", "for", "with", "from", "by","live",
    "and", "or", "but", "being", "be", "this", "that", "those",
    "he", "she", "it", "we", "they", "me", "us", "have", "has",
    "my", "as", "at", NULL
};

/*
* Function Name : is_noise
* Description   : ignore noise words
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

int is_noise(char *word) {
    int16_t idx = 0;
    while (noise[idx] != NULL) {
        if (strcasecmp(word, noise[idx]) == 0){
            return 1;
	}
        idx++;
    }
    return 0;
}

/*
* Description   : Structure Declaration & Function prototypes
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

struct tnode {

    char *word;
    uint16_t count;
    struct tnode *left;
    struct tnode *right;
};


struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
void print_groups_inorder(struct tnode *);
int getword(char *, int16_t);
struct tnode *talloc(void);
char *strdup_custom(char *);


/*
* Structure     : talloc
* Description   : This function allocates memory to node
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/*
* Function      : strdup_custom
* Description   : This function will duplicate string
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

char *strdup_custom(char *str) {

    char *ptr = (char *) malloc(strlen(str) + 1);
    if (ptr != NULL){
        strcpy(ptr, str);
    }
    return ptr;
}

/*
* Function      : addtree
* Description   : This function will insert word in BST
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

struct tnode *addtree(struct tnode *ptr, char *word) {

    int16_t condition = 0;

    if (ptr == NULL) {
        ptr = talloc();
        ptr->word = strdup_custom(word);
        ptr->count = 1;
        ptr->left = ptr->right = NULL;
    }
    else if ((condition = strcmp(word, ptr->word)) == 0) {
        ptr->count++;
    }
    else if (condition < 0) {
        ptr->left = addtree(ptr->left, word);
    }
    else {
        ptr->right = addtree(ptr->right, word);
    }

    return ptr;
}

/*
* Function      : store
* Description   : This function will store Binary Search Tree into Array
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

void store(struct tnode *ptr) {

    if (ptr == NULL)
        return;

    store(ptr->left);
    arr[idx++] = ptr;
    store(ptr->right);
}

/*
* Function      : sort_by_count
* Description   : This function will sort BST Array by word count
* BST Array	: Apple (3) -> Banana (1) -> Cat (2)
* Sorted BST_arr: Apple (3) -> Cat (2) -> Banana (1)
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

void sort_by_count() {

    for (int8_t start = 0; start < idx - 1; start++)
    {
        for (int8_t next = start + 1; next < idx; next++)
	{
            if (arr[start]->count < arr[next]->count)
	    {
                struct tnode *temp = arr[start];
                arr[start] = arr[next];
                arr[next] = temp;
            }
        }
    }
}

/*
* Function      : print_sorted
* Description   : This function will print array in descending order
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

void print_sorted()
{
    for (int8_t idxK = 0; idxK < idx; idxK++)
    {
        printf("%d : %s\n", arr[idxK]->count, arr[idxK]->word);
    }
}

/*
* Function      : treeprint
* Description   : This function will print the binary search tree
                : inOrder traversal : L.S.T -> Root -> R.S.T
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

void treeprint(struct tnode *ptr) {

    if (ptr != NULL) {

        treeprint(ptr->left);
        printf("%d : %s ", ptr->count, ptr->word);

        printf("\n");

        treeprint(ptr->right);
    }
}

/*
* Function Name : getword
* Description   : get next word or character from input
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

int getword(char *word, int16_t lim)
{
    int16_t ch;
    char *w = word;

    while(1){

        while (isspace(ch = getch()))
	    ;

        if (ch == '#') {
            while ((ch = getch()) != '\n' && ch != EOF)
                ;
            continue;
        }

        if (ch == '/') {
            int8_t next = getch();

            if (next == '/') {
                while ((ch = getch()) != '\n' && ch != EOF)
                    ;
                continue;
            }

            else if (next == '*') {
                int8_t prev = 0;
                while ((ch = getch()) != EOF) {
                    if (prev == '*' && ch == '/'){
                        break;
                    }
                    prev = ch;
                }
                continue;
            }
            else {
                ungetch(next);
            }
        }

        if (ch == '"') {
            while ((ch = getch()) != '"' && ch != EOF) {
                if (ch == '\\'){
                    getch();
                }
                // "hello \"world\""
            }
            continue;
        }

        if (ch != EOF){
            *w++ = ch;
        }

        if (!isalpha(ch)) {
            *w = '\0';
            return ch;
        }

        while(--lim > 0){
            ch = getch();
            if (!isalnum(ch) && ch != '-' && ch != '_'){
                ungetch(ch);
                break;
            }
        *w++ = ch;
        }

        *w = '\0';
        return word[0];
    }
}

/*
* Function Name : word_freq_withoutNoise_withLineNo_using_BST
* Description   : count word frequency and group n characters using Binary search tree
* Author        : Karan Sathvara
* Created       : 16-04-2026
*/

void word_freq_decreasing_order_using_BST() {

    struct tnode *root = NULL;
    char word[MAXWORD];

    printf("Enter input : \n");
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]) && !is_noise(word)){
            root = addtree(root, word);
	}
    }

    printf("\nWord Frequency from BST\n");
    treeprint(root);

    printf("\nWord Frequency in decending word count order\n");
    store(root);
    sort_by_count();
    print_sorted();
}
