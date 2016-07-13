#include <stdio.h>

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0
int get_line(char line[], int max);
void reverse(char line[]);

int main() {
    int len = 0; /* current line length */
    char line[MAXLINE]; /* current input line */
    char revline[MAXLINE];

    while((len = get_line(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

int get_line(char line[], int max)
{
    int i = 0;
    int c = 0;

    for(i = 0; ((c = getchar()) != EOF) && c != '\n' && i < max - 1; ++i)
        line[i] = c;

    if(c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}

void reverse(char s[]) {
    char tmp;
    int i, linelen;

    for (i=0; (s[i] != '\n'); ++i)
        ;

    linelen = i-1;

    for (i=0; i<linelen; ++i) {
        tmp = s[i];
        s[i] = s[linelen];
        s[linelen] = tmp;
        --linelen;
    }
}
