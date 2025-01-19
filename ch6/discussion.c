// 6.1 Basic of Structures

//Syntax

//Tag name
struct point {
    int x; //members
    int y;
};

//Struct defining a type
struct {...} x, y, z
==
int x, y, z;

//Struct  defining a variable
struct point pt;

//Combining:
struct maxpt = {320, 200};

//Structure accessing
printf("%d , %d", pt.x, pt.y);

//Nested Structures
Ex:

struct rect { 
    struct point p1;
    struct point p2;
}

struct rect screen;

screen.p1.x

//6.2 Structures and Functions
/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

//Initializing any structure dynamically
struct rect screen;
struct point middle;
struct point makepoint(int, int);


screen.pt1 = makepoint(int, int);

/* addpoints: add two points */
struct addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

//Structure pointer
struct point *pp;

//*pp points to a structure of typ struct point

// -> operator
//Has 


//6.3 Arrays of Structures

//Example
#define NKEYS 1000
char *keyword[NKEYS];

//Example declaration in a struct
struct key {
    char *word;
    int count;  
};

struct key keytab[NKEYS];
//Makes it so that each element of the array is a struc

//Under the hood
struct key keytab[] =  {
"auto", 0,
"break", 0,
"case", 0,
"char", 0,
"const", 0,
"continue", 0,
"default", 0,
/* ... */
"unsigned", 0,
"void", 0,
"volatile", 0,
"while", 0
};

//Finding thes ize
#define NKEYS (sizeof keytab / sizeof (struct key))