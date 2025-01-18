//Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the
// command line, where each operator or operand is a separate argument. For example,
// expr 2 3 4 + *
// evaluates 2 * (3+4).

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

void push(double);
double pop(void);

int main(int argc, char *argv[]) {
    int *operand;

    if (argc <= 1) {
        printf("Could not find valid amount of arguments");
    } 

    while (--argc > 0) {
        //Will keep iterating over the arguments
        while (operand = *++argv[0]) {
            //If its a digit, then we push it onto the stack
            if (isdigit(operand)) {
                //Logic for pushing (still works even if char)
                push(atoi(*operand));
            }
            else  {
                //Then we check if its an operation or not, then do the
                //necessary operations
                switch(*operand) {
                    case '+':
                        push(pop() + pop());
                        break;
                    case '*':
                        push(pop() * pop());
                        break;
                    case '-':
                        *operand = pop();
                        push(pop() - *operand);
                        break;
                case '/':
                    *operand = pop();
                    if (*operand != 0.0)
                        push(pop() / *operand);
                    else
                        printf("error: zero divisor\n");
                    break;
                case '%':
                    *operand = pop();
                    if (*operand != 0.0) 
                        push((int) pop() % (int) *operand);
                    else
                        printf("error: zero divisor\n");
                    break;
                case '^':
                    *operand = pop();
                    push(pow(pop(), *operand));
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
                    printf("Error: Not a valid operation\n");
                    break;
                }
            }
        }
    }

    //Should print the value from the stackk
    printf("Here is your final result: %d", operand);
}