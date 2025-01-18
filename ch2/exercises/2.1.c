//Exercise 2.1
#include <limits.h>
#include <float.h>

main()
{
    printf("The range of signed char is %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("The range of an unsigned char is %d to %d\n", CHAR_MIN, UCHAR_MAX);

    printf("The range of an signed short int is %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("The range of an unsigned short int is %d to %d\n", SHRT_MIN, USHRT_MAX);

    printf("The range of a signed int is %d to %d\n", INT_MIN, INT_MAX);
    printf("The range of an unsigned int is %d to %d\n", INT_MIN, UINT_MAX);

    printf("The range of a signed long int is %d to %d\n", LONG_MIN, LONG_MAX);
    printf("The range of an unsigned long int is %d to %d\n", LONG_MIN, ULONG_MAX);

}