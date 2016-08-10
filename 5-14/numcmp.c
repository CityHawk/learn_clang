#include <stdlib.h>
#include <stdio.h>

/* numcmp:  compare s1 and s2 numerically */
int numcmp(char *s1, char *s2, char reverse)
{
	double v1, v2;
    short r = 1;

	v1 = atof(s1);
	v2 = atof(s2);

    if (reverse == 1)
        r = -1;

    if (v1 < v2)
		return -1*r;
	else if (v1 > v2)
		return 1*r;
	else
		return 0;
}
