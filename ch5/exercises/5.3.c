//Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
//strcat(s,t) copies the string t to the end of s.

#include <stdio.h>

/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char *s, char *t)
{
    while (*s != '\0') /* find end of s */
        s++;
        //Use s++ since we're only finding the end of s
    
    while ((*s++ = *t++) != '\0') /* copy t */
    ;
}