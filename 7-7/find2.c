#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* int getline(char *line, int max); */

int grep(char *line,char *pattern);

/* find:  print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
    char *line;
    size_t linecap = 0;
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    if (argc <= 1) {
        fprintf(stderr, "Usage: find -x -n pattern\n");
        exit(1);
    } else {
        char *pattern = *argv++; argc--;
        if (argc > 0) {
            // read files
        }
        while (getline(&line, &linecap, stdin) > 0) {
            lineno++;
            if ((strstr(line, pattern) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}

int grep(char *line,char *pattern) {
    return 0;
}
