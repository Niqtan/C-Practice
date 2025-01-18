//For loops

//Problem 9: https://www.w3resource.com/c-programming-exercises/for-loop/index.php

#include <stdio.h>

main() {
    char asterisk = '*';
    int i, j;
    
    for (i = 0; i <= 4; i++) {
        for(j = 1; j <= i; j++) {
            printf("%c", asterisk);
        }
        printf("\n");
    }
}