#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINES 5000     /* max #lines to be sorted */
char *lineptr[MAXLINES];  /* pointers to text lines */

char case_sensitive = 1;
char directory_order = 0;
int field = -1;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *,char), char reverse);
int numcmp(char *, char *, char);
int pstrcmp(char *s, char *t,char);
void getfield(int fieldnum, char *s, char **d);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;           /* number of input lines read */
    int numeric = 0;      /* 1 if numeric sort */
    char reverse = 0;
    int ch;

    extern char case_sensitive;

    while ((ch = getopt(argc, argv, "nrfdF:")) != -1) {
        switch (ch) {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            case 'f':
                case_sensitive = 0;
                break;
            case 'd':
                directory_order = 1;
                break;
            case 'F':
                field = atoi(optarg);
        }

    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        q_sort((void **) lineptr, 0, nlines-1, (int (*)(void*,void*,char))(numeric ? numcmp : pstrcmp),reverse);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

/* qsort:  sort v[left]...v[right] into increasing order */
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *,char),char reverse)
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)   /* do nothing if array contains */
        return;          /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        int _t;
        if (field > 0) {
            char *f1 = (char *) malloc(100*sizeof(char));
            char *f2 = (char *) malloc(100*sizeof(char));
            getfield(field, v[i], &f1);
            getfield(field, v[left], &f2);
            _t = (*comp)(f1, f2, reverse);
        } else {
            _t = (*comp)(v[i], v[left], reverse);
        }
        if (_t < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    q_sort(v, left, last-1, comp, reverse);
    q_sort(v, last+1, right, comp, reverse);
}

void getfield(int fieldnum, char *s, char **d) {
    char *token;
    char *tstr = strdup(s);
    for (int i=0; i < fieldnum || (token=strsep(&tstr, " \t")) != NULL; i++) {
        *d = token;
    }
}
