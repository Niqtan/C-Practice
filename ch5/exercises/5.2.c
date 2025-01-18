//Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does
//getfloat return as its function value?

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

double getfloat(double *pn) {
    int c;
    double sign;
    while (isspace(c = getch())) /* skip white space */
    ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0.0;
        }

    sign = (c == '-') ? -1.0 : 1.0;
    if (c == '+' || c == '-')
        c = getch();
        if (!isdigit(c)) {
            ungetch((sign == 1.0) ? '+': '-');
        }

    if (c == '.') {
        getch();
    }

    for (*pn = 0.0; isdigit(c), c = getch())
        *pn = 10.0 * *pn + (c - '0');
    *pn *= sign;
    
    if (c != EOF)
        ungetch(c);
    return c; //Big issue; Returning c which is int
}