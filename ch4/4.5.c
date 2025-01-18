//Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in
//Appendix B, Section 4.

#include <math.h>

main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
            op2 = pop();
                push(pop() - op2);
                break;
            case '/':
            op2 = pop();
                if (op2 != 0.0)
                push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
            op2 = pop();
                if (op2 != 0.0) 
                push( (int) pop() %  (int) op2);
            else
                printf("error: zero divisor\n");
                break;
            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case 's': // sin
                push(sin(pop()));
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
    }
    }
    return 0;
}