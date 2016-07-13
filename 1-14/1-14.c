#include <stdio.h>

#define CAP_OFFSET 32
#define OFFSET 65
#define TRUE 1
#define FALSE 0

int main() {
    int c,i;

    int nsymbols[256];

    for (i = 0; i < 256; ++i) {
        nsymbols[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        ++nsymbols[c];
    }

    for (i = 0; i < 256; ++i) {
        if (nsymbols[i] > 0) {
            printf("%2c",i);
            printf(": %3d >", nsymbols[i]);

            for (c = 0; c < nsymbols[i]; ++c) {
                printf("#");
            }

            printf("\n");
        }
    }
}
