#include <stdio.h>

//Basic implementation of finding a min and max in array (no pointers)
void main() {
    int a[] = {23, 45, 6, 98};

    int min, max;
    min = max = a[0]; //23
    
    for (int i = 0; i <= 3; i++) {
        if (a[i] < min) {
            min = a[i];
        }
}
}

//Basic implementation of finding a min and max in array (w/ pointers)

int main() {
    int a[] = {42, 4211, 5, 423};
}