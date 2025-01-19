// Exercise 6-1. Our version of getword does not properly handle underscores, string constants,
// comments, or preprocessor control lines. Write a better version.

/* getword: get next word or character from input */

#include <stdio.h>
#include <ctype.h>

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
    ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) || c != '_') {
        *w = '\0';
        return c;
    }

    /*
    Use a switch case statement to check for each pattern
    
    */
   switch(c) {
    case '_':
        //Do something
    case '#':
        //do something
    case '""':
        //Do something with string constants
    case '//':
        //do something
   }

    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
    }
    *w = '\0';
    return word[0];
}