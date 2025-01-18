//Pointers

//Ex:
p = &c // Assigns the address of c to p

//Dereference
ip = &x;
y = *ip
*ip = 0
ip = &z[0]


//5.3 Pointers and Arrays
int a[10] <-- Array

// Reference vs Dereferencing

pa = &a[0]; <-- Refers to first index element
x = *pa <-- gets the contents of index 0 into x

pa++ <-- legal for pointers
a++ <-- illegal for arrays

// String definitions
char s[] <-- double purpose for both array and string which is confusing
char *s <-- Convention use since it only should have 1 use, and that
is to be a pointer

//Passing an array as a parameter
It is only allowed to pass part of an array to a function

Ex:
f(&a[2])

f function declaration:
f(int arr[]) or f(int *arr)

//5.4 Address Arithmetic

Ex: p+=i
//Increments it to i beyond where it currently does

//Rudimentary storage allocator

//First routine
alloc(n) --> pointer to n consecutive character positions

afree(p) --> releases the storage acquired so it can be reused later

//Routines are rudimentary because the calls to afree must be made in order
//for the calls to alloc to be made

//two main functions
malloc()
free()

Implementation
alloc --> static array (private to alloc and afree)

allocp --> pointer which points to the next free element

allocbuf --> storing place of the size

//Addition and Subtraction
Addition
Ex: p + n 

1. C first looks at what type p points to 
2. Next, it multiplies n by that type's size (Ex: int = 4 bytes, hence 4 * n = R)
3. After getting the result, then we move that many bytes forward in memory

Subtraction

if (p < q) {
    q-p+1 = n of elements from p-q inclusive 
}