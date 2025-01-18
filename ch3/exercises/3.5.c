//Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
//character representation in the string s. In particular, itob(n,s,16) formats s as a
//hexadecimal integer in s.

/* Converts hex str s to hexadecimal integer*/
void itob(int n, char s[], int b) {
    char tmpstr[100];
    char digits[] = "0123456789ABCDEF";
    int c = 0;

    int size_ni_tempstr = sizeof(tmpstr);

    int base_remainder;

    if (n == 0) {
           s[0] = '0';
           //Use the size in order to get the last element of a string
           s[size_ni_tempstr - 1] = '\0';
    }

    do {
        base_remainder =  n % b;
        tmpstr[c++] = digits[base_remainder];
        n = n / b;
    }
    while ( n != 0 );

    int j;
    for (j = 0; j < c ; j++) {
        //-1 becaue of the null terminated string
        s[j] = (tmpstr[c - 1 - j]);
    }
    
    s[j] = '\0';

    //Print out a hexadecimal str
    printf("Here is your hexadecimal: %s", s);
}