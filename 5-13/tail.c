#include <stdio.h>

#define MAXLINES 5000
static char *lineptr[MAXLINES];

int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t linecap = 0;
    ssize_t c;
    int nline = 0;

    while ((c=getline(&line,&linecap,stdin)) > 0) {
        lineptr[nline++]=line;
    }
}

