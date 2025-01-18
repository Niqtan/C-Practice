//While loops

//Problem 8: https://www.w3resource.com/c-programming-exercises/while-loop/index.php

#include <stdio.h>
#include <math.h>

main() {

    //Calculate and prints the sum of cubes
    //Must be even numbers up to 20 using a while loop
    int limit = 20;
    int min = 2;

    printf("Cubed even numbers up to %d\n\n", limit);
    while (min <= limit) {
        int cubed_min = pow(min, 3);
        printf("%d cube is: %d\n", min, cubed_min);
        min += 2;
    }
}