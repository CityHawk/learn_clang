#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define LINEFOLD 15
#define MAXLINE 1024

char line[1024];

int get_line(void);
int finegrain_last_known_blank(char line[], int pos);
void dumpline(char line[]);

int main() {
    int len,i,lastknownblank,startline, prevblank;
    extern char line[];

    while ((len=get_line()) > 0) {
        lastknownblank = 0;
        prevblank = FALSE;
        i = 0;
        while ((len-startline) >= LINEFOLD) {
            startline = i;
            while ((i-startline) < LINEFOLD) {
                if (line[i] != ' ') {
                    prevblank = TRUE;
                } else {
                    if (prevblank == TRUE) {
                        lastknownblank = finegrain_last_known_blank(line, i);
                        prevblank = FALSE;
                    }
                }
                ++i;
            }


            printf("symbol %c, ", line[lastknownblank]);
            line[lastknownblank] = '\n';
            /* printf("lastknownblank: %d, i: %d, len: %d, startline: %d\n", lastknownblank, i, len, startline); */
        }
        dumpline(line);
    }
}

int get_line(void) {
    int c, i;
    extern char line[];

    for (i=0; i < MAXLINE-1 && ((c=getchar()) != EOF && c != '\n'); ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

int finegrain_last_known_blank(char line[], int pos) {
    int i;
    for (i = pos; i == ' '; i++)
        ;
    printf("%c\n", line[i]);
    return i;
}

void dumpline(char line[]) {
    int i;
    for (i=0; line[i] != '\0'; ++i) {
        if (line[i] == ' ')
            putchar('*');
        else
            putchar(line[i]);
    }
}
