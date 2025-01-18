// Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
//duplicate it, and to swap the top two elements. Add a command to clear the stack.

#include <stdio.h>

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0;/* next free stack position */
double val[MAXVAL]; /* value stack */
int i;

//print the top  5 elements
void print_func() {
    for ( i = 0; i <= 5; i++) {
        
        printf("Top Elements: %lf\n", val[sp-1-i]);
    }
}


//Duplicate the top element
int j;
double dup_top() {
    for ( i = j = 0; i < 1; i++, j++) {
        
        val[j] = val[sp-1-i];
        push(val[j]);
    }
    
    return val[j];
}

//Swap the top two elements
void swap() {
    double temp = val[sp-2];
    val[sp-2] = val[sp-1];
    val[sp-1] = temp;

}

//Clear the stack
void clear() {
    while (sp >= 0) {
    pop();
    }
}