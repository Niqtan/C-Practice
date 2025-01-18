//Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
//Should ungets know about buf and bufp, or should it just use ungetch?

//Ungetch should be used in order to push back the entire string to an input

void ungets(char* s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
    ungetch(s[i]);
    }
}