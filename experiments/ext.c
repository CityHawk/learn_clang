#include <stdio.h>
int foo = 1;

void print1(void) {
    extern int foo;
    printf("%d\n", foo);
}

void print2(void) {
    printf("%d\n", foo);
}

void print3(void) {
    static int foo = -100;
    printf("%d\n", foo);
}
