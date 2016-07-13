#include <stdio.h>

#define TABSTOP 4

int main() {
    int c,numspaces;

    numspaces = 0;
    while ((c=getchar()) != EOF) {
        if (c == ' ') {
            if (++numspaces >= TABSTOP) {
                putchar('-');
                numspaces = 0;
            }
        } else if (c == '\n') {
            numspaces = 0;
        } else {
            putchar(c);
        }

    }
}
