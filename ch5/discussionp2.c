//5.5 Character Pointers and Funcs

char *pmessage <-- actually a pointer to the character array
char amessage[] <-- array

//Great example of usage of pointers
/* strcpy: copy t to s; pointer version 2 */
void strcpy(char *s, char *t)
{
while ((*s++ = *t++) != '\0')
;
//This moves the incrementation of s and t into the test part of the loop

//*t gets the character t  points to, and is assigned to the location *s points to
// After these operations, both s and t are incremented
}

//Incrementation with pointers

*--p
//What happens: decrements p before fetching the character p points to
//In contrast:
*p--
//Which simply gets the value thatp  is pointing to and decrements it

//5.6 Pointer to arrays

int (*p)[5];
//pointer to the whole array of elements NOT JUST 1

& vs * in arrays
//With * operator, we can go inside the box and pick specific values
// WIth & operator, we can go outside and get the general picture of the array

Pointer array is a homogeneous collection of indexed pointer variables

Syntax: pointer_type *array_name [array_size]

Ex: char *lineptr[MAXLINES]

//What this does is that it creates an array of MAXLINES elements, wher eeach element
//is a pointer to char
