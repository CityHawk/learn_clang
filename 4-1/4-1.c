#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int strindex(char s[], char p[]) {
    int i, j, k;
    int rm = -1;

    for (i=0; s[i] != '\0'; i++) {
        /* putchar(s[i]); */
        for (j=i, k=0; p[k]!='\0' && s[j]==p[k]; k++, j++)
            ;

        if (k > 0 && p[k] == '\0')
            rm = i;
    }
    return rm;

}

int main() {
    char *l = NULL;
    size_t lcap = 0;
    char pattern[] = "ou";
    int found = 0;
    int pos;

    while (getline(&l,&lcap, stdin) > 0) {
        if ((pos=strindex(l, pattern)) >= 0) {
            printf("%d: %s\n", pos,l);
            found++;
        }
    }
    printf("%d\n", found);
    return found;
}
