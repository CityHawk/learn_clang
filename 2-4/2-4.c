#include <stdio.h>
#include <assert.h>
#include <string.h>

void squeeze(char s1[], char s2[]);
void squeeze_orig(char s[], int c);

int main() {
    char s1[] = "abcdef";
    char s2[] = "dab";
    squeeze(s1,s2);

    printf("%s\n", s1);
}

void squeeze(char s[], char s2[]) {
    int curchar,c,i,j;

    for (curchar=0; (c = s2[curchar]) != '\0'; curchar++) {
        for (i = j = 0; s[i] != '\0'; i++) {
            if (s[i] != c)
                s[j++] = s[i];
        }

        s[j] = '\0';
    }
}
