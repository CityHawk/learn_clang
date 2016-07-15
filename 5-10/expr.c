#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define VAR '1'

void push(double);
double pop(void);
int isalldigit(char *s);

/* reverse Polish calculator */
int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    int i;

    for (i = 1; i < argc; i++) {
        if (isalldigit(argv[i])) {
            push(atof(argv[i]));
        } else if (strcmp(argv[i],"+") == 0) {
            push(pop() + pop());
        } else if (strcmp(argv[i],"-") == 0) {
            op2 = pop();
            push(pop() - op2);
        } else if (strcmp(argv[i],"*") == 0) {
            push(pop() * pop());
        } else if (strcmp(argv[i],"/") == 0) {
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
        } else {
            printf("%d\n", isalldigit(argv[i]));
            printf("error: unknown command %s\n", s);
        }
    }
    printf("%f\n", pop());
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

int isalldigit(char *s) {
    char *_t;

    _t = s;
    while (*s != '\0') {
        if (isdigit(*s) || '.' == *s) {
            s++;
        } else {
            s = _t;
            return 0;
        }
    }
    s = _t;
    return 1;
}
