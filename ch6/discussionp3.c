//6.6 Lookup Tables

#define IN 1

state = IN; //IN becomes 1 because of the replacement text

//Two functions which manipulate this behavior:

//install(s,t) 
//Records name s and replacement text t

//Lookup(s) searches for s in table

//hash function adds a hash value of string s

//How to write a function=like preprocessor macro

#define MIN(A, B) (A < B ? A: B)

//But why?


//6.7 Typedef

typedef int Length;
//Makes the name length syonym for an integer
//Can be used in declarations, casts, and 

Length *lengths[];

typedef char *String; 
//char gets replaced by a data type called String
//Makes a data type for string


typedef int INTEGER;

int main() {
    INTEGER var = 100;
     
}

//typedef on structures
typedef struct car {
}
car

int main() {
    car c1;
    
}

//6.8 Unions

union skibidi
{
    int ival;
    float fval;
    char *sval;
} u;


//Accessing
u.ival

//Nested unions

struct {
    char *name;
    int flags;
    int utype;
    union {
        int ival;
        float fval;
        char *sval;
    } u;
} symtab[NSYM];

symtab[i].u.ival;

//Application of Unions

//Initial Structure
struct store {
    double price;

    union {
        struct {
            char *title;
            char *author;
            int num_pages;
        } book;
        struct {
            int color;
            int size;
            char *design;
        } shirt;
    } items;

};

//6.9 Bit Fields

//Ex:

#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04

//Symbol Table

struct {
    //Unsigned so that it does not have negative values
    unsigned int is_keyword: 1; //Represents field width in bits
    unsigned int is_extern : 1; //Tells the compiler how much memory I want to utilize
    unsigned int is_static : 1; 
} flags;
//Contain 3 1-bit fields
