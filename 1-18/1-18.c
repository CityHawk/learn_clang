#include <stdio.h>

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0
int get_line(char line[], int max);
int trim(char line[], char out[]);

int main() {
    int len = 0; /* current line length */
    char line[MAXLINE]; /* current input line */
    char trimmedline[MAXLINE];

    while((len = get_line(line, MAXLINE)) > 0) {
        if (trim(line, trimmedline) >=0)
            printf("trimmed line: %s<EOL>\n", trimmedline);
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

int trim(char s[], char out[]) {
    int i,j;
    int begin,end;

    for (i = 0; (s[i] == ' ' || s[i] == '\t'); ++i)
        ;

    begin = i;

    /* race up to the EOL */
    while (s[i] != '\n')
        ++i;

    for (i=i-1; (s[i] == ' ' || s[i] == '\t'); --i)
        ;

    end = i;


    j = 0;
    for (i = begin; i <= end; ++i){
        out[j] = s[i];
        ++j;
    }
    out[j] = '\0';
    return end-begin;
}
