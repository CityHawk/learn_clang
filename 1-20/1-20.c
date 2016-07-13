#include <stdio.h>

#define TABSTOP 4

int currenttabpos;

void maketotabstop(void) {
    extern int currenttabpos;
    int i;

    for (i=currenttabpos; i < TABSTOP; ++i)
        putchar('.');

    currenttabpos = 0;
}

int main() {
    int c;
    extern int currenttabpos;


    currenttabpos = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            maketotabstop();
        } else {
            putchar(c);
            if (++currenttabpos >= TABSTOP || c == '\n')
                currenttabpos = 0;
        }
    }

}
