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