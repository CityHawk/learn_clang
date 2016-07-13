#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int max);
void clear_line(char line[]);

int main() {
    char line[MAXLINE];
    int len,i;

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > 5)
            printf("%d - %s\n", len-1, line);

        /* i = 0; */
        /* while (line[i] != '\0') { */
        /*     if (line[i] == '\n') */
        /*         printf(" \\n "); */
        /*     else */
        /*         printf("%3c", line[i]); */
        /*     ++i; */
        /* } */
    }
    return 0;
}

int get_line(char s[], int lim) {
    int c;
    int i = 0;
    while ( (c = getchar()) != EOF && c != '\n' && i < lim-1) {
        s[i] = c;
        ++i;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

