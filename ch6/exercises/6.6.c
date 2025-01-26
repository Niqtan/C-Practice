// Exercise 6-6. Implement a simple version of the #define processor (i.e., no arguments) suitable for
// use with C programs, based on the routines of this section. You may also find getch and ungetch
// helpful.

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
1. How do I account for the extra arguments on beyond the #define?

*/

int main(int argc, char *argv[]) {
    int i;

    while (--argc > 0) {
        while (i = *(++argv)[0]) {

        }
    }

    /*
    To do:
    1. Use the argument system in order to register define
    2. Define logic and check the logic using the functions
    3. 
    
    */
}