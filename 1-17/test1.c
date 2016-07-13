#include<stdio.h>

#define MAXLINE 1000
#define MAXLENGTH 5

int get_line(char [], int max);
void copy(char from[], char to[]);

int main()
{
    int len = 0; /* current line length */
    char line[MAXLINE]; /* current input line */

    while((len = get_line(line, MAXLINE)) > 0)
    {
        if(len > MAXLENGTH)
            printf("LINE-CONTENTS:  %s\n", line);
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
