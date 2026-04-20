/*
* File Name     : 170875_Karan_DR_Module6-3.c
* Description   : Write a cross-referencer that prints a list of all words in a document,
*               : and for each word, a list of the line numbers on which it occurs.
*               : Remove noise words like ``the,'' ``and,'' and so on.
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

int16_t lineno = 1;

/*
* Description   : array of pointers
* Author        : Karan Sathvara
* Created       : 15-04-2026
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
* Created       : 15-04-2026
*/

int is_noise(char *word) {
    int16_t idx = 0;
    while (noise[idx] != NULL) {
        if (strcmp(word, noise[idx]) == 0){
            return 1;
	}
        idx++;
    }
    return 0;
}

/*
* Description   : Structure Declaration & Function prototypes
* Author        : Karan Sathvara
* Created       : 15-04-2026
*/

struct tnode {
    char *word;
    uint16_t word_count;
    int16_t lines[1000];
    uint16_t line_count;
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
        ptr->word_count = 1;
	ptr->lines[0] = lineno;
	ptr->line_count = 1;
        ptr->left = ptr->right = NULL;
    }
    else if ((condition = strcmp(word, ptr->word)) == 0) {
        ptr->word_count++;

        if (ptr->lines[ptr->line_count - 1] != lineno) {
            ptr->lines[ptr->line_count++] = lineno;
        }
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

    if (ptr != NULL) {

        treeprint(ptr->left);
        printf("%d : %s ", ptr->word_count, ptr->word);

        for (int16_t idx = 0; idx < ptr->line_count; idx++) {
            printf("%d ", ptr->lines[idx]);
        }

        printf("\n");

        treeprint(ptr->right);
    }
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
	    if(ch == '\n'){
		lineno++;
	    }

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
* Created       : 15-04-2026
*/

void word_freq_withoutNoise_withLineNo_using_BST() {

    struct tnode *root = NULL;
    char word[MAXWORD];

    printf("Enter input : \n");
    while (getword(word, MAXWORD) != EOF) {

	if (word[0] == '\n') {
       	    lineno++;
    	}

        if (isalpha(word[0]) && !is_noise(word)){
            root = addtree(root, word);
	}
    }

    printf("\nWord Frequency\n");
    treeprint(root);

}






/* To convert all in Lower case */
/*      for (int16_t idx = 0; word[idx]; idx++) {
            word[idx] = tolower(word[idx]);
        }
*/
