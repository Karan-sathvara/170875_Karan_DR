/*
* File Name     : 170875_Karan_DR_Module6-2.c
* Description   : Write a program that reads a C program and prints in alphabetical order ,
*               : each group of variable names that are identical in the first 6 characters , but different somewhere thereafter.
*               : Don't count words within strings and comments. Make 6 a parameter that can be set from the command line.
* Author        : Karan Sathvara
* Created       : 15-04-2026
*/

#include <stdio.h>
#include "header.h"
#include "function.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

int8_t prefix_len = 6;

char prev[MAXWORD] = "";
int8_t group_started = 0;

/*
* Structure     : tnode
* Description   : this structure has counter and char pointer
                : left and right are self refrential structure
* Author        : Karan Sathvara
* Created       : 15-04-2026
*/

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

/*
* Description   : Function prototypes
* Author        : Karan Sathvara
* Created       : 15-04-2026
*/

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
* Created       : 15-04-2026
*/

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/*
* Function      : strdup_custom
* Description   : This function will duplicate string
* Author        : Karan Sathvara
* Created       : 15-04-2026
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
* Created       : 15-04-2026
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
* Function      : treeprint
* Description   : This function will print the binary search tree
		: inOrder traversal : L.S.T -> Root -> R.S.T
* Author        : Karan Sathvara
* Created       : 15-04-2026
*/

void treeprint(struct tnode *ptr) {

    if (ptr != NULL)
    {
        treeprint(ptr->left);
        printf("\t %d %s\n", ptr->count, ptr->word);
        treeprint(ptr->right);
    }
}

/*
* Function      : print_groups_inorder
* Description   : This function will prints groups containing 'n' same characters together
                : inOrder traversal : L.S.T -> Root -> R.S.T
* Author        : Karan Sathvara
* Created       : 15-04-2026
*/

void print_groups_inorder(struct tnode *ptr) {

    if (ptr == NULL){
 	 return;
    }

    print_groups_inorder(ptr->left);

    if (prev[0] != '\0' && strncmp(prev, ptr->word, prefix_len) == 0) {

        if (!group_started) {
            char prefix[MAXWORD];
            strncpy(prefix, prev, prefix_len);
            prefix[prefix_len] = '\0';

            printf("\n%s\n", prefix);
            printf("\t %d %s\n", ptr->count, prev);

            group_started = 1;
        }

        printf("\t %d %s\n", ptr->count, ptr->word);
    }
    else {
        group_started = 0;
    }

    strcpy(prev, ptr->word);

    print_groups_inorder(ptr->right);
}

/*
* Function Name : getword
* Description   : get next word or character from input
* Author        : Karan Sathvara
* Created       : 15-04-2026
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
* Function Name : word_freq_group_using_BST
* Description   : count word frequency and group n characters using Binary search tree
* Author        : Karan Sathvara
* Created       : 15-04-2026
*/

void word_freq_group_using_BST(int argc, char *argv[]) {

    struct tnode *root = NULL;
    char word[MAXWORD];

    if (argc > 1){
        prefix_len = atoi(argv[1]);
    }

    printf("Enter input : \n");
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])){
            root = addtree(root, word);
	}
    }

    printf("\nWord Frequency\n");
    treeprint(root);

    printf("\nGroups (first %d chars same)\n", prefix_len);
    print_groups_inorder(root);

}
