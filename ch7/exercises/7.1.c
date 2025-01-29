// Exercise 7-1. Write a program that converts upper case to lower or lower case to upper,
// depending on the name it is invoked with, as found in argv[0].

#include <stdio.h>
#include <ctype.h>

main(int argc, char *argv[]) {
    
    int i;
    
    if (argc == 2){
        while ((i = getchar()) != EOF) {
            if ((*argv)[1] == 'l') {
                putchar(tolower(i));
            }
            else if ((*argv)[1] == 'u') {
                putchar(toupper(i));
            }
        }
    }

    return 0;

}