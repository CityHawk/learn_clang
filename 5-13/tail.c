#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAXLINES 5000
static char *lineptr[MAXLINES];
static int fill = 0;

void storeline(char *s, int n);

int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t linecap = 0;
    ssize_t c;
    int tailsize = 10;
    int ch;

    ch = getopt(argc, argv, "n:");
    if (ch == 'n') {
        tailsize = atoi(optarg);
    }

    while ((c=getline(&line,&linecap,stdin)) > 0) {
        char *tline = (char *) malloc(strlen(line)*sizeof(char));
        strcpy(tline,line);
        storeline(tline, tailsize);
    }

    for (int i=0;i<fill;i++)
        printf("%s", lineptr[i]);
}

void storeline(char *line, int tailsize) {
    if (fill < tailsize) {
        lineptr[fill++] = line;
    } else {
        int i = 0;

        free(lineptr[i]);

        while(i < (tailsize-1)) {
            lineptr[i] = lineptr[i+1];
            i++;
        }
        lineptr[i] = line;
    }
}
