//Exercise 2.9

//Answer:
// The reason why the expression x &= (x-1) deletes the rightmost 1-bit
// is because it tries to subtract (delete) the rightmost 1-bit by making it 
// so that it subtracts the rightmost bit by 1, which makes it so that
// it eliminates the rightmost 1-bit. Now, what if the right-most bit was 
// a 0? That is where the & operator comes into play. If the right-most bit
//was a 0 and it cannot be subtracted by 1, of course it has to borrow.
//Then the result would be 1. However, using the & operator, it can try
//to match the original 0 and therefore it still deletes the rightmost
//1-bit because the match doesnt work. Lastly, the = operator is there 
//to assign the value back to a new variable called x.

//Rewrite the function
int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= (x-1)) {
            b++;
    }
    return b;
}