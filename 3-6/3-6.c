#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void lpad(int width, char s[]) {
    if (width <= strlen(s))
        return;

    char _ts[width+1];
    int i = 0;
    int j;
    for (i=0; i<(width - strlen(s)); i++) {
        _ts[i] = '_';
    }

    for (j=0; j<strlen(s); j++, i++) {
        _ts[i] = s[j];
    }

    for (i=0; i<width; i++) {
        s[i] = _ts[i];
    }
    s[i] = '\0';
}

void itoa(int n, char s[], int pad) {
    int i, sign;
    unsigned int n2;

    if ((sign = n) < 0)
        n2 = -n;
    else
        n2 = n;

    i = 0;

    do {
        s[i++] = n2 % 10 + '0';
    } while ((n2 /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
    lpad(pad, s);
}

int main() {
    char s[1000];

    itoa(99,s,5);
    printf("%s\n", s);

    itoa(0,s, 1);
    printf("%s\n", s);

    itoa(INT_MAX,s,15);
    printf("%s\n", s);

    itoa(INT_MIN+1,s,15);
    printf("%s\n", s);

    itoa(INT_MIN,s,15);
    printf("%s\n", s);
}
