//Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings. For
//example, strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strncpy(char* s, char* ct, int n) {
    int i, j;

    //For loop to iterate over each character
    for (i = j = 0; i < n; i++) {
        s[j++] = ct[i];

    }
    //Since the for loop finishes first, the while loop should be good to go
    //because the for loop should evaluate the characters s[j] needs

    for (i = 0; *s < n; i++) {
        s[j] = '\0';
    }


    return s;
}

char *strncat(char* s, char* ct, int n) {
    int i;

    if (ct[0] == '\0') {
        printf("Please input a valid str");
    }

    for (i = 0; s[i] != '\0'; i++);

    for (i = 0; i < n; i++) {
        s[i] = ct[i];
    }

    s[i] = '\0';

    return s;
}

int strncmp(char *cs, char *ct, int n) {
    int i;

    //Iterate over each character in the string cs
    for (i = 0; i < n; i++) {    
        if (ct[i] != '\0' || cs[i] != '\0') {
            if (cs[i] != ct[i]) {
                return cs[i] - ct[i];
            }
        }
    }
    return 0;
} 