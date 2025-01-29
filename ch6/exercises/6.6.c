// Exercise 6-6. Implement a simple version of the #define processor (i.e., no arguments) suitable for
// use with C programs, based on the routines of this section. You may also find getch and ungetch
// helpful.

#include <stdio.h>
#include <string.h>

void ungetch(int);
int getch(void);

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; /* found */
    return NULL; /* not found */
}

struct nlist *lookup(char *);
char *strdup(char *);
/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
    } else /* already there */
        free((void *) np->defn); /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

/*
To do:
1. How do I account for the extra text beyond the #define?
    -  For example: #define AGE <- replacement text 1241421 <- VAL

*/

void define(char* replacement, char* val){
    struct nlist *ikaw;

    //Look if the replacement text is not in the hashtable
    if ((ikaw = lookup(replacement)) == NULL) {
        //If not, then we install it accordingly to the arguments passed
            install(replacement, val);
    }
}