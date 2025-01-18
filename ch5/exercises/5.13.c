//Exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n
//is set to 10, let us say, but it can be changed by an optional argument so that
// tail -n
// prints the last n lines. The program should behave rationally no matter how unreasonable the
// input or the value of n. Write the program so it makes the best use of available storage; lines
// should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
// fixed size.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 1000

int main(int argc, char *argv[]) {
    int n = 10;
    int iterator;
    //Max capacity of lines
    char *line[MAXLINES];

    if (argc < 0 && argc > 1) {
        printf("Could not find valid amount of arguments");
    } 

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (iterator = *++argv[0]) {
            if (isdigit(iterator)) {
                n = atoi(iterator);
                break;
            }
            else {
                printf("Please specify n.");
            }
        }
    }

    /*
    1. Logic for printing the last n lines.
    */

   printf("%s", line[n]);


}
