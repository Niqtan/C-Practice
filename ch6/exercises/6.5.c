// Exercise 6-5. Write a function undef that will remove a name and definition from the table maintained
// by lookup and install.

#include <stdio.h>

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

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
    
    } 
    else /* already there */
        undef(np->defn)/*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

struct nlist *undef(char* name, char* defn) {
    /*
    To do:
    1. Some important stuff:

    Lookup function determines whether the name is already present or no
    Install will only dictate a rightful result if there is any
    reason there is no room for new entry (NULL)

    The two functions work hand-in-hand, which means the first
    one used (lookup) should be the one in which we should do first,
    then do the following

    2. We need to REMOVE and possibly reallocate it back into memory
    (using the free function (Also, we may also free those memory
    allocated))

    3. Check this article: https://stackoverflow.com/questions/45387465/how-to-undeclare-delete-a-variable-in-c

    */
    
    struct nlist *np;

    
    
}