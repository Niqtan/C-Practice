//Exercise 3-4. In a two's complement number representation, our version of itoa does not
//handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why
//not. Modify it to print that value correctly, regardless of the machine on which it runs.

//The current version of the itoa cannot handle -1 is because if we try to use one's
// complement on negative one, flipping the bits WILL work however, it does not handle two's complement
//by adding 1 after inverting the bits. Hence, the reason why it can't handle -1 is simply because flipping the bits
//is not enough. We need to use two's complement to add 1 to the binary code in order for negative one to be truly
// positive 1.

//Revision
/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) { /* record sign */
        n = -n; /* make n positive */
        i = 0;
    }

    //Added code
    else if ((sign = n) == -1) {
        n = -n + 1;
        i = 0;
    }
    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
        if (sign < 0)
            s[i++] = '-';
            s[i] = '\0';
            reverse(s);
}