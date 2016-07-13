#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAXWORDLEN 15

int main() {
    int c, prevblank, cwordlen, i, morethanmax, most_frequent_word_count;

    int hgramdata[MAXWORDLEN];

    for (i = 0; i < MAXWORDLEN; ++i) {
        hgramdata[i] = 0;
    }
    morethanmax = 0;

    prevblank = FALSE;
    cwordlen = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (prevblank == FALSE) {
                if (cwordlen <= MAXWORDLEN) {
                    ++hgramdata[cwordlen-1];
                } else {
                    ++morethanmax;
                }
                cwordlen = 0;

            } else {
                prevblank = TRUE;
            }
        } else {
            ++cwordlen;
            prevblank = FALSE;
        }

    }

    for (i = 0; i < MAXWORDLEN; ++i) {
        printf ("%2d:%3d ", i+1, hgramdata[i]);
        for (c = 0; c < hgramdata[i]; ++c) {
            putchar ('#');
        }
        putchar('\n');
    }
    printf (">>:%3d\n", morethanmax);


    /* Vertical version */
    printf ("\n\n--- ( Vertical version) ---\n\n");

    /* find max value of the array */
    most_frequent_word_count = 0;
    for (i = 0; i < MAXWORDLEN; ++i) {
        if (most_frequent_word_count < hgramdata[i]) {
            most_frequent_word_count = hgramdata[i];
        }
    }

    if (morethanmax > most_frequent_word_count) {
        most_frequent_word_count = morethanmax;
    }

    /* OK, now we found the pike value */

    for (c = most_frequent_word_count; c > 0; --c) {
        printf("%2d:", c);

        for (i = 0; i < MAXWORDLEN; ++i) {
            if (c <= hgramdata[i]) {
                printf("  #");
            } else {
                printf("   ");
            }
        }

        if (c <= morethanmax) {
            printf("  #\n");
        } else {
            printf("   \n");
        }
    }

    /* Draw numbers */

    printf("  :");
    for (i = 0; i < MAXWORDLEN; ++i) {
        printf("%3d", i+1);
    }
    printf(" >>\n");

}
