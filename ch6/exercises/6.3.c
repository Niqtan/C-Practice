// Exercise 6-3. Write a cross-referencer that prints a list of all words in a document, and for
// each word, a list of the line numbers on which it occurs. Remove noise words like ``the,''
// ``and,'' and so on.

#include <stdio.h>
#include <string.h>

struct document{
    char *words;
} fitness[] = {
    "The FitnessGram Pacer Test is",
    "a multistage aerobic capacity test",
    "that progressively gets more difficult",
    "as it continues The 20",
    "meter pacer test will begin",
    "in 30 seconds Line up",
    "at the start The running",
    "speed starts slowly but gets",
    "faster each minute after you",
    "hear this signal bodeboop A",
    "sing lap should be completed",
    "every time you hear this",
    "sound ding Remember to run",
    "in a straight line and",
    "run as long as possible",
    "The second time you fail",
    "to complete a lap before",
    "the sound your test is",
    "over The test will begin",
    "on the word start On",
    "your mark Get ready Start",
    "ding"
};

void remove_word(char* text, char* word);

void cross_reference(struct document fitness[]) {
    int i;

    //List of noise words
    char array_noise[6][20] = {
        'a',
        "the",
        "twenty",
        "thirty",
        "ding",
        "bodeboop"
    };
    
    //Token for the strtok func
    char* token;

    //Create a copy of the original string
    char* new_paragraph = strdup(fitness[i].words);
    
    //Put a delimeter to identify each word by using a white space as the
    //delimeter
    token = strtok(fitness[i].words, " ");

    //If the copied string is not null termianted
    while (new_paragraph != '\0') {
        
        //Strtok always wants it to not equal to NULL for us to keep
        //iterating over the token
        while (token != NULL) {

        //Now compare the word and the word  from the noise word list
        for(i = 0; array_noise[i] != '\0'; i++) {
            if (strcmp(token, array_noise[i]) == 0) {

                //If both are true, then replace that specific word
                //Error: token is the word, yet we're setting the new paragraph,
                //supposedly a whole string, to null terminated which means we're setting it
                // to be deleted

                //Proposed solution: create a hypothetical function for removing the word.
                remove_word(new_paragraph, token);
            }
        }
    }
    i++;
    }

    printf("The new paragraph is: %i", fitness);
}


