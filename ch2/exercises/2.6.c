//Exercise 2.6
#include <stdio.h>

main() {
    int final_reading = setbits(0b10101110, 4, 3, 0b10100011);

    printf("Final Reading: %d", final_reading);
}

int setbits(int x, int p, int n, int y) {
    //Use a mask to filter the bits that need to be changed
    int first_mask = ((1 << n ) - 1);
    int y_bits = y & first_mask;
    
    int second_mask = ~(((1 << n) - 1) << (p+1-n));
    int x_bits = x & second_mask;
    
    int shifted_y_bits = y_bits << (p+1-n);

    return  x_bits | shifted_y_bits;
    //Replace number x and replace it with some bits with bits from y
    //Replace exactly n bits starting from the starting position of p in x
    // with the rightmost n bits of y
    //Need to do this without disturbing other bits of x
}