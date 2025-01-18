// Exercise 2.3
#include <stdio.h>

int main() {
    char string[] = "A3F7C9E2";
    long final = htoi(string);
    printf("Hexadecimal to integer: %ld", final);
}

long htoi(char s[]) {
    return strtol(s, NULL, 16);
}