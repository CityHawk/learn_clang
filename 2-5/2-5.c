#include <stdio.h>
#include <assert.h>
#include <string.h>

int any(char s1[], char s2[]) {
    int i,j;
    int pos = -1;

    for (i=0; pos < 0 && i < strlen(s1); i++) {
        for (j=0; pos <0 && j < strlen(s2); j++) {
            if (s1[i] == s2[j])
                pos = i;
        }
    }

    return pos;
}

int main() {
    assert(any("abcdef", "fer") == 4);
    assert(any("abc", "feb") == 1);
    assert(any("abc", "def") == -1);
}
