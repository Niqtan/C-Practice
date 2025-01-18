//Exercise 4-2. Extend atof to handle scientific notation of the form


//Original Function:
/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
    sign = (s[i] == '-') ? -1 : 1; //Make the sign -1 or 1 depending on the sign
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
    //Multiplying the current value by 10
        val = 10.0 * val + (s[i] - '0'); //Adding in the new empty spot
        if (s[i] == '.')
            i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0'); //Shifting the number to the left
        power *= 10;
    }


    return sign * val / power;
}

//New function:

#include <ctype.h> // Include for isdigit
#include <math.h> // Include for pow

double atof(char s[])
{
    double val, power;
    int i, sign, exponent, exp_sign, final_notation;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
        if (s[i] == '.')
            i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    //Checks if the current index is in scientific notation
    if (s[i] == 'e' || s[i] == 'E') {
        i++;

        //If it is, then the  next thing to check is its sign
        if (s[i] == '-') {
            exp_sign = -1;
            i++;
        }
        else if (isdigit(s[i])) {
            exp_sign = 1;
        }
    //Next, evaluate the value of the exponent
    for (exponent = 1; isdigit(s[i]); i++) {
        //Use the expression s[i] - '0' to convert it to a digit
        exponent = exponent * 10 + (s[i] - '0');

    }

    //Finally, multiply the final exponent with the sign
    exponent *= exp_sign;
    
    //And then, add that to the current formula
    return sign * val / power * pow(10, exponent);
    }

    return sign * val / power;
}