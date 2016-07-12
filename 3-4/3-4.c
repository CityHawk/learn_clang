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

void itoa(int n, char s[]) {
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
}

int main() {
    char s[1000];

    itoa(99,s);
    printf("%s\n", s);

    itoa(0,s);
    printf("%s\n", s);

    itoa(INT_MAX,s);
    printf("%s\n", s);

    itoa(INT_MIN+1,s);
    printf("%s\n", s);

    itoa(INT_MIN,s);
    printf("%s\n", s);
}
