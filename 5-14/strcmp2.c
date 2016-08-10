#include <stdio.h>
#include <ctype.h>
int cmpchar(char *s, char *t);

int pstrcmp(char *s, char *t, char reverse)
{
    int tmp;
    for ( ; (tmp=cmpchar(s, t)) == 0; s++, t++)
        if (*s == '\0')
            return 0;

    if (reverse == 1)
        return tmp*-1;
    else
        return tmp;
}

int cmpchar(char *s, char *t) {
    extern char directory_order;
    extern char case_sensitive;

    int res;

    if (directory_order == 1) {
        while (!isalnum(*s) || *s == ' ')
            s++;

        while (!isalnum(*t) || *t == ' ')
            t++;
    }

    if (case_sensitive == 1) {
        res = *s -*t;
    } else {
        res = tolower(*s) - tolower(*t);
    }
    return res;
}
