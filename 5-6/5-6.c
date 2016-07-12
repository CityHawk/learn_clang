#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* getline:  read a line into s, return length */
int get_line(char *s,int lim)
{
    int c,i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n';i++)
        *s++ = c;

    *++s = '\0';
    return i;
}

/* reverse:  reverse string s in place */
void reverse(char *s)
{
    int c;
    char *t;

    t = s;
    t += strlen(s)-1;

    while (s < t) {
        c = *s;
        *s++ = *t;
        *t-- = c;
    }
}

/* itoa:  convert n to characters in s */
void itoa(int n, char *s)
{
    int sign;
    char *stash;
    stash = s;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    do {       /* generate digits in reverse order */
        *s++ = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(stash);
}

/* atoi:  convert s to integer; version 2 */
int atoi(char *s)
{
    int sign;
    int n = 0;

    while (isspace(*s))  /* skip white space */
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')  /* skip sign */
        s++;

    while (isdigit(*s))
        n = 10 * n + (*s++ - '0');
    return sign * n;
}

/* strindex:  return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
    int i;

    char *_k = t;
    char *_j;

    for (i = 0; *s != '\0'; i++) {
        for (_j = s, t=_k; *t!='\0' && *_j==*t; _j++, t++)
            ;
        if (t>_k && *t == '\0')
            return i;
        s++;
    }
    return -1;
}

int main() {
    char l[1000];

    get_line(l,1000);
    printf("%s\n", l);

    reverse(l);
    printf("%s\n", l);

    itoa(1234, l);
    printf("%s\n", l);

    itoa(-12, l);
    printf("%s\n", l);

    printf("%d\n", atoi("1234"));
    printf("%d\n", atoi("-1234"));

    printf("%d\n", strindex("hello", "el"));
    printf("%d\n", strindex("hello", "al"));
}
