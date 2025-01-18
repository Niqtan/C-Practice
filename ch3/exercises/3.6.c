//Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
//argument is a minimum field width; the converted number must be padded with blanks on the
//left if necessary to make it wide enough./* itoa: convert n to characters in s */
void itoa(int n, char s[], int min_width)
{
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;


    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    //Use the * in order to specify the width, with the padding
    printf("Converted Integer: %*s\n", min_width, s);
    
    reverse(s);

    /*
    To do:
    1. If n < min_width -> it will be padded to the left w/ blank spaces
    Basically if the outcome does not consume all of the width given,
    then it pads some blank spaces to the left?
    */
}