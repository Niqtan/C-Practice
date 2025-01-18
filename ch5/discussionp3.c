//5.7 Multidimensional arrays
Array of arrays
data_type name_of_array[size1][size2]; // Two dimensional

//Size calculation
sizeof a[10][20] = 10 x 20 = 200;

//Bytes
200 x 4 (Size of integer) = 800

//Examples of 2d arrays

//5.8
(skipped, short ch)

//5.9 Pointers vs Multi-dimensional Arrrays
int a[10][20];
int *b[10];

// Main difference is how they're defined. A pointer will usually be defined using
// a *, which indicates it is a pointer. A 2d array (or more) will typically
// have 2 or more indices in its declaration.

// 5.10 Command-line Arguments

//Ex:
#include <stdlib.h>
int main(int argc, char* argv ) {
    int i;

    for (i = 0; i < argc; i++) {
        printf("arg[%d]: %s\n", i, argv[i]);
    }

    int result = 1;

    for (i = 1; i < argc; i++) {
        int x = strtol(argv[i], NULL, 10);
        result = result * x;
    }

    return 0;
}

//5.11 Pointers to Functions
Example of an array pointer:

int fun(int a, int b) {
    return a+b;
}

//WRONG
int *arr[1]

arr is an aray of size 1 pointer to int 

//ANSWER
int (*ptr)[10]

ptr is a pointer to an array of size 10 to int

Example of a function pointer:

int (*ptr)(int, int);

//Assigning the address of a function to a function pointer

int (*ptr)(int, int) = &func

//alternative
int (*ptr)(int, int) = add
result = ptr(10, 20);

//5.12 Complicated Declarations

//Ex 1, converts C declaration into word description
char **argv
argv: pointer to char
int (*daytab)[13]
daytab: pointer to array[13] of int
int *daytab[13]
daytab: array[13] of pointer to int
void *comp()
comp: function returning pointer to void
void (*comp)()
comp: pointer to function returning void
char (*(*x())[])()
x: function returning pointer to array[] of
pointer to function returning char
char (*(*x[3])())[5]
x: array[3] of pointer to function returning
pointer to array[5] of char

A declaration is made up of:
1. One Variable name
2. One basic type
3. Zero or more operator

Ex:
char *name[]

name is an array of pointers to char

Ex 2:

char (*name)[50];
name is a pointer to an array of size 50 of  char

char **name[50];

name is an array of size 50 of pointers pointing to a pointer pointing to char

Ex Complicated:

char *(*(**a[][8])())[];

a is an array of an array of size 8 of pointer to pointer to function returning pointer to an array of pointer to char