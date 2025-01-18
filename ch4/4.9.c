// Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
//what their properties ought to be if an EOF is pushed back, then implement your design.

#include <stdio.h>

#define BUFSIZE 100
int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    if (buf[bufp] == EOF) {
        printf("Cannot read anything.");
        return EOF;
    }

    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{

    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        if (buf[bufp] == EOF) {
        printf("Cannot read anything.");
    }
    else {
        buf[bufp++] = c;
    }
}