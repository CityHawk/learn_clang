#include <stdio.h>

void reverse(char s[])
{
    static int i = 0, n;
    int c = s[i];

    if (c) {
        i++;
        reverse(s);
        s[n-i] = c;
        i--;
    } else {
        n = i;
    }
}

int main() {
    char s[] = "abcedf";
    reverse(s);
    printf("%s\n", s);

    char s1[] = "foo";
    reverse(s1);
    printf("%s\n", s1);
}
