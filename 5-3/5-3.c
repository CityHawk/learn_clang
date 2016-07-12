#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

void str_cat(char *s, char *t) {
    s += strlen(s);

    while (*t)
        *s++ = *t++;
    *s = '\0';
}

int str_end(char *s, char *t) {
    int match = 1;

    s += strlen(s)-1;
    t += strlen(t)-1;

    while (*s && *t) {
        if (*s == *t) {
            s--; t--;
        } else {
            match = 0;
            break;
        }
    }
    return match;
}

void strn_cpy(char *s,char *t,int n) {
    while (n-- > 0 && *s)
        *t++ = *s++;
    *t = '\0';
}

void strn_cat(char *s, char *t, int n) {
    s += strlen(s);
    while (n-- > 0 && *t) {
        *s++ = *t++;
    }
    *s = '\0';
}

int strn_cmp(char *s, char *t, int n) {
    int hasmatch = 1;

    while (n-- > 0 && *s && *t) {
        if (*s++ != *t++)
            hasmatch = 0;
    }

    return hasmatch;
}

int main() {
    char s[MAXLEN] = "Hello";
    char t[MAXLEN] = "world";

    str_cat(s,t);
    printf("%s\n", s);
    printf("%d\n", str_end(s,t));
    printf("%d\n", str_end(s,"foobar"));
    printf("%d\n", str_end(s,"old"));
    printf("%d\n", str_end(s,"HelloworldHelloworld"));

    char t2[MAXLEN];
    strn_cpy(s,t2,6);
    printf("%s\n", t2);

    strn_cpy(s,t2,3);
    printf("%s\n", t2);

    strn_cpy("abcdef",t2,20);
    printf("%s\n", t2);

    strn_cat(s, "abcdef", 3);
    printf("%s\n", s);

    printf("%d\n", strn_cmp("allo", "allosaur",4));
    printf("%d\n", strn_cmp("allo", "allosaur",5));
    printf("%d\n", strn_cmp("alo", "allosaur",4));
}

