//Exercise 2.4
#include <stdio.h>

char* squeeze(char s[], char s2[]);

void main() {
    char string[] = "Skibidi";
    char string2[] = "Sigma";

    char* new_string = squeeze(string, string2);

    printf("New word: %s", new_string);
}

/* squeeze: delete all c from s */
char* squeeze(char s[], char s2[])
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (strchr(s2, s[i]) == NULL) {
        s[j++] = s[i];
    }
}
s[j] = '\0';
return s;
}