//Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes
//getch and ungetch unnecessary. Revise the calculator to use this approach.

#include <math.h>
#include <stdio.h>

main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getline(s)) != EOF) {
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