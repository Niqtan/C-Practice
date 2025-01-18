//Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
//an integer into a string by calling a recursive routine.

#include <stdio.h>
/* printd: print n in decimal */
void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{   
    int i = 0;
    itoa_recursive(n, s, i);

}

/* itoa: convert n to characters in s */
int itoa_recursive(int n, char s[], int return_val)
{
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);

    if (n == 0) /* Base Case */ {
        return return_val;
    }
    else {
        itoa_recursive((n /= 10), s, return_val); /* delete it */
        s[i++] = n % 10 + '0'; /* get next digit */
        return return_val++;
    }
}

//UNSOLVED
