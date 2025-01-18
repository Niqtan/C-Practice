//Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify
//getch and ungetch accordingly. 

// New Function:
#define BUFSIZE 1
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp == 1) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
    {
    if (bufp > 1)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}