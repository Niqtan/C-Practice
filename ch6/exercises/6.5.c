// Exercise 6-5. Write a function undef that will remove a name and definition from the table maintained
// by lookup and install.

#include <stdio.h>
#include <string.h>

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};
#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)

{
    struct nlist *np;
    
    for (np = hashtab[hash(s)]; np != NULL; np = np->next) // Linked List
        if (strcmp(s, np->name) == 0)
            return np; /* found: return pointer */
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

void freeshit(struct nlist *someshit) {
    free(someshit->name);
    free(someshit->defn);
    free(someshit);
}

void undef(char* name) {

    struct nlist *np;

    //Assigns np to a pointer in the hashtable
    while ((np = lookup(name)) != NULL) /*Tells us that it should have a val*/ {
        //Assign a temporary variable for comparison
        struct nlist *temp = np;
        //If the hashtable value is equal to the argument passed
        if (strcmp(temp->defn, name) == 0) {
            //Then we unlink np to be the next value
            np = temp->next;
            //This can be another function for freeing both
            //name and defn, but that can be for another time
            freeshit(temp);
            break;
        }
        else {
            np = np->next;
        }

    }
    
}