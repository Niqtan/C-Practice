// Exercise 6-1. Our version of getword does not properly handle underscores, string constants,
// comments, or preprocessor control lines. Write a better version.

/* getword: get next word or character from input */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getword(char *word, int lim)
{
    int i, c, getch(void);
    void ungetch(int);
    char *w = word;
    char arr[20];

    while (isspace(c = getch()))
    ;
    if (c != EOF)
        *w++ = c;
    
    if (c == '_') {
        *w++ = c;
    }
    else if (c == '"') {
        while (c = getch() && c != '"') {
            *w++ = c;
        }
        *w++ = '\0';
    }
    else if(c == '/') { 
        if (c == '/') {
            //skip everything
        }
    }
    //For directive
    else {
        while (c = getch() && c != '\0') {
            *w++ = c;
        }
        *w++ = '\0';
    }
    

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
    }
    *w = '\0';
    return word[0];
}
