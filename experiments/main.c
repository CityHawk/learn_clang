#include <stdio.h>

void print1(void);
void print2(void);
void print3(void);

static int foo = -1;
int main(){
    extern int foo;
    printf("%d\n", foo);
    print1();
    print2();
}
