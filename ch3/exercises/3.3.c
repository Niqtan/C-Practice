//Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
//the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
//case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
//that a leading or trailing - is taken literally.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void expand(char s1[], char s2[]);

void main() {
    expand("0-9", "prefix_");
}
void expand(char s1[], char s2[]) {

    int i;
    size_t len = strlen(s2); 
    //Allocate new space for each concatenation
    char *s3 = malloc(len + 2);
                    
    s3[0] = '\0';
                    
    //Standard code to loop over each character in a string
    for (i = 0; s1[i] != '\0'; i++) {
        switch (s1[i])
        {
        case '-':
            char first_index = s1[0]; //Gets the first element of the string
            char last_index = s1[2]; //Gets the last element of the string
        
            if (isalpha || isdigit (first_index) && isalpha || isdigit (last_index)) {
                
                int next_index;
                for (next_index = first_index; next_index <= last_index; next_index++) {
                    //Creates a new tempory character for concatenation
                    char tmpstr[2];
                    //Stores the next letter
                    tmpstr[0] = next_index;
                    //Stores the extra character of '\0'
                    tmpstr[1] = 0;
                    //Concatenates it to a new string
                    strcat(s3, tmpstr);
                }
            }
            else {
                 printf("Invalid ranges\n");
            }
            break;
        default:
            break;
        }
    }
    printf("Here is your notation: %s\n", s3); 
}