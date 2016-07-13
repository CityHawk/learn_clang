#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define MAXOP 100
#define NUMBER '0'
#define VAR '1'

int getop(char []);
void push(double);
double pop(void);
void pstack();
double vars[26];

int main() {
    int type;
    double op2;
    char s[MAXOP];
    int sign = 1;
    double cr;
    int f;

    for (int i=0; i<26; i++)
        vars[i] = DBL_MAX;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case VAR:
                f = atoi(s);
                if (vars[f] != DBL_MAX) {
                    push(vars[f]);
                } else {
                    vars[f] = pop();
                }
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
                    printf("error: zero division\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int) pop() % (int) op2);
                else
                    printf("error: zero division\n");
                break;
            case '^':
                op2 = pop();
                push(pow(pop(),op2));
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'c':
                push(cos(pop()));
                break;
            case 'p':
                // print the stack
                pstack();
                break;
            case 'w':
                // swap last two
                break;
            case 'd':
                // duplicate stack
                break;
            case '\n':
                printf("\t%.8g\n", cr=pop());
                push(cr);
                break;
            default:
                printf("error: unknown command\n");
                break;
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if ( sp > 0 )
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.') {
        if (c >= 'A' && c <= 'Z')
            return VAR;
        else
            return c; /* not a number */
    }

    i = 0;

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void pstack(void) {
    for (int i = sp; i>=0; i--)
        printf("%f ", val[i]);
    printf("\n");
}
