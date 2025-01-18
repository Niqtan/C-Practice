// Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse
// (decreasing) order. Be sure that -r works with -n.

/* qsort: sort v[left]...v[right] into increasing order */
#include <stdio.h>
#include <string.h>
#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right,
int (*comp)(void *, void *));
int numcmp(char *, char *);

int numeric = 0; /* 1 if numeric sort */
int reverse = 0; /* 1 if reversed sort*/

    /* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int i;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (i = *(++argv)[0]) {
            switch (i) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                default:
                    printf("No valid arguments.");
                    return 0;
            }
        }
    }
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void**) lineptr, 0, nlines-1,
            (int (*)(void*,void*))(numeric ? numcmp: strcmp));
        writelines(lineptr, nlines, reverse);
    return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
}
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int reverse)
{
    int i;
    if (reverse == 1)  {
    for (i = nlines - 1; i >= 0; i--) {
        printf("Reversed: %s\n", lineptr[i]);
    }
    }
    else {
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
    }
}