#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
    int c,prevblank;

    prevblank = FALSE;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (prevblank == FALSE) {
                putchar(c);
                prevblank = TRUE;
            }
        } else {
            putchar(c);
            prevblank = FALSE;
        }
    }
}
