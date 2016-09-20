#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* int getline(char *line, int max); */

int grep(char *, FILE *);

static int except = 0;
static int number = 0;

/* find:  print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
    char *line;
    long lineno = 0;
    int c, number = 0, found = 0;

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
    if (argc < 1) {
        fprintf(stderr, "Usage: find -x -n pattern\n");
        exit(1);
    } else {
        char *pattern = *argv++; argc--;
        if (argc > 0)
            while (argc-- > 0) {
                FILE *f = fopen(*argv, "r");
                if (f == NULL) {
                    fprintf(stderr, "Unable to read file %s\n", *argv);
                } else {
                    found += grep(pattern, f);
                }
                fclose(f);
                argv++;
            }
        else
            found += grep(pattern, stdin);
    }
    return found;
}

int grep(char *pattern, FILE *stream) {
    int found = 0;
    long lineno = 0;
    size_t linecap = 0;
    char *line = NULL;
    int c;
    while ((c = getline(&line, &linecap, stream)) > 0) {
        lineno++;
        if ((strstr(line, pattern) != NULL) != except) {
            if (number)
                printf("%ld:", lineno);
            printf("%s", line);
            found++;
        }
    }
    return found;
}
