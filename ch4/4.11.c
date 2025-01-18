//Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal
//static variable.
#include <ctype.h>
int getch(void);

/* getop: get next character or numeric operand */
int getop(char s[])
{
int i, c;
static int last_char = 0;
while ((s[0] = c = getch()) == ' ' || c == '\t')
;
s[1] = '\0';
if (!isdigit(c) && c != '.')
return c; /* not a number */
i = 0;
if (isdigit(c)) /* collect integer part */
while (isdigit(s[++i] = c = getch()))
;
if (c == '.') /* collect fraction part */
while (isdigit(s[++i] = c = getch()))
;
s[i] = '\0';
if (c != EOF)
last_char = c;
return NUMBER;
}