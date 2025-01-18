//Exercise 2.5
#include <stdio.h>
#include <string.h>

char any(char s[], char s2[]);

void main() {
    char string[] = "Skibidi";
    char string2[] = "Slicer";

    char first_char = any(string, string2);
    
    if (isalpha(first_char)) {
    printf("First Match Found: %c", first_char);
    }
    else {
        printf("No characters matching. Error Code: -1");
    }
}

/* any: Find first match of a char */
char any(char s[], char s2[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        char *result = strpbrk(s, s2);
        if (result != NULL) {
        return *result;
    }
    else {
        return -1;
    }
}
return 0;
}