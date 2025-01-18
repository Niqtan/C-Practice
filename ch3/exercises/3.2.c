// Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
// into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
// a function for the other direction as well, converting escape sequences into the real characters.
#include <stdio.h>

char* escape(char s[], char t[]);
char* unescape(char d[], char f[]);

void main() {
    char sigma_str[] = "    Sigma   ";
    char stored_str[100];

    char stored_str2[100];
    char prime_example[] = "Hello\\n World";

    char* first_str = escape(stored_str, sigma_str);
    char* second_str = unescape(stored_str2, prime_example);

    printf("First str: %s\n", first_str);
    printf("Second str: %s", second_str);
}
char* escape(char s[], char t[]) {

    int i, j;
    for (i = j = 0; t[i] != '\0'; i++)
    switch(t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
    }
     s[j] = '\0';

     return s;
}

char* unescape(char d[], char f[]) {


    int i, j;
    for (i = j = 0; f[i] != '\0'; i++)
    switch(f[i]) {
        case 'n':
            d[j++] = '\n';
            break;
        case 't':
            d[j++] = '\t';
            break;
        case '\\':
            break;
        default:
            d[j++] = f[i];
            break;
    }
     d[j] = '\0';

     return d;
}
