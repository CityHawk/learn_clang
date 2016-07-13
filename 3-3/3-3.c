#include <stdio.h>

#define MAXLINE 1000
int main() {
    char *line = NULL;
    char finalline[MAXLINE];
    size_t linecap = 0;
    ssize_t linelen;
    int i, j,fi;
    char c;

    // read the line
    while ((linelen = getline(&line, &linecap, stdin)) > 0 ) {
        fi = 0;
        for (i=0; (i < linelen) && (line[i] == '-'); i++) {;}

        linelen--;
        while (line[--linelen] == '-') { ; }

        while (i<=linelen) {
            if (line[i+1] == '-') {
                j = i;
                // chase the next non - symbol
                while (line[++i] == '-') {;}
                for (c=line[j]; c < line[i]; c++) {
                    finalline[fi++] = c;
                }
            } else {
                finalline[fi++] = line[i++];
            }
        }
        finalline[fi] = '\0';

        printf("%s\n", finalline);
    }
}
