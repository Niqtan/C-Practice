//Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
//end of the string s, and zero otherwise.

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t) {
    int s_len = strlen(s);
    char *temp = malloc(s_len + 1);

    //Reverses the string s
    for (int i = s_len - 1; i >= 0; i--) {
        //Duplicates the string and sees if current iteration = start of s (very first instance of s)
        temp[i] = s[s_len - 1 - i];
    }

    //terminate the string
    temp[s_len] = '\0'; 

    //Compare both strings if they match
    if (strcmp(temp, t) == 0) {
        free(temp);
        return 1;
    }
    else {
        free(temp);    
        return 0;
    }
}