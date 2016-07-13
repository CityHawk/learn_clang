#include <stdio.h>

int main() {
    int c;
    int tabs = 0;
    int spaces = 0;
    int nls = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            ++tabs;
        }

        if (c == ' ') {
            ++spaces;
        }

        if (c == '\n') {
            ++nls;
        }
    }

    printf("tabs: %d, spaces: %d, newlines: %d\n", tabs, spaces, nls);
}
