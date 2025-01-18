//For Loops

//Problem 6: https://www.w3resource.com/c-programming-exercises/for-loop/index.php

#include <stdio.h>

main() {
    int n, i;

    printf("\nWhat table would you like to know?");
    scanf("%d", &n);

    //Use a basic for loop
    printf("Here's your multiplication table:\n");
    for (i = 0; 10 >= i >= 1 ;i++) {
        int multiplied_value = n * i;
        printf("%d * %d = %d\n", n, i, multiplied_value);
    }
 }