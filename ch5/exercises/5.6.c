// Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers
// instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa,
// and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
// (Chapter 4).

#include <stdio.h>
#include <ctype.h>

/* getline: read a line into s, return length */
 int getline(char *s,int lim)
 {
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        *(s + i) = c;
    if (c == '\n') {
        *(s + i) = c;
        ++i;
    }
    *(s + i) = '\0';
    return i;
 }

 /* atof: convert string s to double */
 double atof(char *s)
 {
    double val, power;
    int i, sign;

    for (i = 0; isspace(*(s + i)); i++) /* skip white space */
    ;
    sign = (*(s + i) == '-') ? -1 : 1;
    if (*(s + i) == '+' || *(s + i) == '-')
        i++;
    for (val = 0.0; isdigit(*(s + i)); i++)
        val = 10.0 * val + (*(s + i) - '0');
    if (*(s + i) == '.')
        i++;
    for (power = 1.0; isdigit(*(s + i)); i++) {
        val = 10.0 * val + (*(s + i) - '0');
        power *= 10;
    }

    return sign * val / power;
 }

#include <ctype.h>

 int getch(void);
 void ungetch(int);
 /* getop: get next character or numeric operand */
 int getop(char *s)
 {
    int i, c;
    while ((*(s + 0) = c = getch()) == ' ' || c == '\t')
        ;
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(*(s + ++i) = c = getch()))
        ;
    if (c == '.') /* collect fraction part */
        while (isdigit(*(s + ++i) = c = getch()))
        ;
    *(s + i) = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
 }