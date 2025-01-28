// Exercise 6-4. Write a program that prints the distinct words in its input sorted into decreasing
// order of frequency of occurrence. Precede each word by its count.

#include <stdio.h>
#include <string.h>

    /*
    Specs:

    1. The program should print distinct words (Words that are different)
    from each other
    2. It should be from ITS input so we need to use scanf
    
    Constraints:
    1. It should be in decreasing order of frequency of occurence
        - What this means is that we will need to see the frequency of words
        and based off how much they are repeated, then we will need to print out
        the decreasing order of times the words have been repeated
    2. Precede each word by the count of how many times they have been
    repeated
    */

struct x {
    char* words[100];
    int count;
    struct x *ptr;
} real;

/*
Problems to look out for:
    1. The bad thing about that is that we would need to create multiple variables
    incrementing a specific word. That is not memory efficient.
    2. Connected to 1., count would overlap with other counts as well of distinct words.
    3. We may use a self referential struct but it doesn't seem necessary
    for this type of problem.

*/

int main() {
    struct x* ptr = &real;
    //For many times the word has been repeated, then we increment count on that word

    int i, j, unique, repeated;
    char* token;
    char* token2;
    
    printf("Enter a sentence with a lot of words: ");
    fgets(ptr->words, strlen(ptr->words), stdin);

    while (ptr->words != '\0') {
        token = strtok(ptr->words, " ");
        token2 = strtok(ptr++->words, " ");
        while (token != NULL) {
            for (i = 0; token[i] != '\0' && token2[i] != '\0'; i++) {
                    if (strcmp(token, token2) == 0) {
                        repeated = 1;
                        break;
                    }
                    else {
                        ptr->count++;
                        printf("%d %s", ptr->count, token);
                }
            }
        }
    }
}