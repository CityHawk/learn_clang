#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000   /* max length of any input line */
char *alloc(int);

/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int nlines;
	char *p, *line;
    size_t lcap = MAXLEN;
    ssize_t len;

	nlines = 0;
	while ((len = getline(&line,&lcap,stdin)) > 0)
		if (nlines >= maxlines || (p = (char *) malloc(len*sizeof(char))) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}
