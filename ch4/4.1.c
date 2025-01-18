//Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
//occurrence of t in s, or -1 if there is none.

//Original Function:
/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
        ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

//New function:
int strindex(char s[], char t[])
{
    int j, k;
    int n = strlen(s);
    //Reverse the string approach
    for (unsigned i = n; i > 0;) {
        --i;

        
    //Another improved for loop would to be to make i a signed integer
    //Ex:
    for (int i = n - 1 /* this gets the last index*/; i >= 0; i--)
    //This makes it so that the code is much more maintainable and readable
    //from other engineers. If i is equal to the last index of the string
    //s, then it should mean that it will iterate backwards (using the decrementation)
    //of i-- and hence get the position of each one of the characters.


        //Technically get the rightmost occurance of t by reversing the loop
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
    
        ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}