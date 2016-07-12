#include <stdio.h>
void itoa(int in, char s[]) {
    static int sign = 0;
    static int i;
    if (sign == 0) {
        if (in < 0) {
            sign = -1;
            in = -in;
        } else {
            sign = 1;
        }
        i = 0;
    }

    if (in / 10) {
        itoa(in /10, s);
    }

    if (sign != 0) {
        if (sign < 0)
            s[i++] = '-';
        sign = 0;
    }

    s[i++] = in % 10 + '0';
    s[i] = '\0';
}
int main() {
    char s[100];

    itoa(1256, s);
    printf("%s\n", s);

    itoa(12, s);
    printf("%s\n", s);

    itoa(-456, s);
    printf("%s\n", s);
}
