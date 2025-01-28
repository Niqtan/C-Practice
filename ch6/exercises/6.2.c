// Exercise 6-2. Write a program that reads a C program and prints in alphabetical order each
// group of variable names that are identical in the first 6 characters, but different somewhere
// thereafter. Don't count words within strings and comments. Make 6 a parameter that can be
// set from the command line.

#include <stdio.h>

struct x {
    char *words;
};

int e_something = 0; /* The 6th letter as something for command line */

main (int argc, char *argv[]) {

    struct x xtab[] = {
        "myloveString",
        "myloveInt",
        "myloveDecimal",
    };
    int i, j;
    char fixed_arr[3];

    /*
    To do:
    1. Have a group of variable names that are identical in the first 6 characters
        - it should be printed in alphabetical order
        Perhaps, what we could actually do is to use a for loop to iterate
        over it.
    2. "but different somewhere thereafter."
        - Different letters after the 6th letter
    
    CONSTRAINTS:
    - Don't count words within strings and comments
    - Make the 6th letter a parameter to be set from cmd line
     */

    //The . notation would access each variable name and iterate over them
    for (i = 0; xtab[i].words != xtab[7].words; i++) {
        for (i = 0; i <= 3 ;i++) {
            for(j = i + 1; j <= 3; j++) {
                //0 means the next letter is identical hence we compare it to 0
                //to sort different letters
                
                //If the j iterable has a greater alphabeticn caracter than
                //the name, then those two names are interchanged
                if (strcmp(xtab[i].words, xtab[j].words) > 0) {
                    strcpy(*(fixed_arr + i), xtab[i].words);
                    strcpy(xtab[i].words, xtab[j].words);
                    strcpy(xtab[j].words, *(fixed_arr + i));
                }
            }
        }
    }
    for (i = 7; xtab[7].words != '\0'; i++) {
        *(fixed_arr + i) = xtab[j].words;
    }

    printf("The alphabetic sorted array of the first 6 words is: %i\n", xtab.words);
    
    while (--argc > 0 && *(argv)[0] == '-') {
        while (i == *(++argv)[0]) {
            switch(i) {
                case 'e':
                    e_something = 1;
                    break;
                default:
                    break;
            }
        }
    }
}