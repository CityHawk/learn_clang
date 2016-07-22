#include <stdio.h>
/* strcmp:  return <0 if s<t, 0 if s==t, >0 if s>t */
int pstrcmp(char *s, char *t)
{
    /* printf("%s\n", s); */
    /* printf("%s\n", t); */
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
