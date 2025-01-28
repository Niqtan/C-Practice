// 6.4 Pointers to Structures
/* count C keywords; pointer version */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

main()
{
    char word[MAXWORD];
    struct key *p;
    
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((p=binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;
    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word, struck key *tab, int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;
    
    while (low < high) {
        mid = low + (high-low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
    else if (cond > 0)
        low = mid + 1;
    else
        return mid;
    }
    return NULL;
}

//How pointers affect the original 
mid = (low+high) / 2 /* WRONG */

//Correct
mid = low + (high-kow) / 2

//Size of structure

//Unnnamed holes
struct {
    char c;
    int i;
};
//There may be an instance where c (char) would be 1 and int (4) i would be 4
//Thus 5, but it may also become 8 bytes


//Example program of accessing structure variables

struct abc {
    int x;
    int y;
};

int main() {
    struct abc a = {0,1};
    //Pointer to some type struct abc
    struct abc *ptr = &a;

    //ptr->x = (*ptr).x
    printf("%d %d", ptr->x, ptr->y);
    return 0;
}

//6.5 Self referential Structures

//Example code of a tree node 
struct tnode { /* the tree node: */
    char *word; /* points to the text */
    int count; /* number of occurrences */
    struct tnode *left; /* left child */
    struct tnode *right; /* right child */
};

//Sample program of a tree
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
/* word frequency count */

main()
{
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}

/* Addtree is a recursion because it will need to break down each word
accordingly*/

//Storage for a new node
struct tnode *talloc(void);

//Example code
struct code {
    int i;
    char c;
    struct code *ptr;
};

//Sample usage

var1.ptr = &var2;
var.ptr-> i, var1.ptr->c

//This is possible because the ptr refers to the structure itself 
