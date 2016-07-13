#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
    int c, is_special;

    while ((c = getchar()) != EOF){
        is_special = FALSE;

        if (c == '\t') {
            printf("\\t");
            is_special = TRUE;
        }

        if (c == '\b') {
            printf("\\b");
            is_special = TRUE;
        }

        if (c == '\\') {
            printf("\\\\");
            is_special = TRUE;
        }

        if (is_special == FALSE) {
            putchar(c);
        }
    }
}
