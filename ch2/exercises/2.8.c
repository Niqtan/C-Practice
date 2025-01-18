//Exercise 2.8
#include <stdio.h>

main() {
    int final_reading = rightrot(0b10101110, 3);

    printf("Final Reading: %d", final_reading);
}

int rightrot(int x, int n) {
    int shifted_bits = x >> n;
    int rotated_bits = x << ((sizeof(x) * 8) - n);
    
    return shifted_bits | rotated_bits;
}