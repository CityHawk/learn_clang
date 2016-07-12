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

void itob(int n, char s[], int b) {
    int i, sign;
    unsigned int n2;
    char nums[] = "0123456789ABCDEF";

    if ((sign = n) < 0)
        n2 = -n;
    else
        n2 = n;

    i = 0;

    do {
        s[i++] = nums[n2 % b];
    } while ((n2 /= b) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[1000];

    itob(64,s,8);
    printf("%s\n", s);

    itob(57005,s,16);
    printf("%s\n", s);

    itob(INT_MIN,s,16);
    printf("%s\n", s);

    itob(INT_MAX,s,16);
    printf("%s\n", s);
}
