//Exercise 2.7

#include <stdio.h>

main() {
    int final_reading = invert(0b10101110, 4, 3);

    printf("Final Reading: %d", final_reading);
}

int invert(int x, int p, int n) {
    //Creates a mask then inverts that mask
    return x ^ (((1 << n ) - 1) << (p+1 - n));
}