#include <stdio.h>
#include <stdlib.h>

void detab(char *s, int tabstop, int tabstart) {
    int i,ci;
    int nexttabstop;

    for (ci=0; *s!='\0'; s++,ci++) {
        if (*s == '\t' && ci >= tabstart) {
            nexttabstop = tabstop - (ci % tabstop);
            for (int _t=0; _t<nexttabstop; _t++)
                printf(".");
            ci += nexttabstop - 1;
        } else {
            putchar(*s);
        }
    }
}

int argv2int(char *s) {
    s++;
    return atoi(s);
}

int main(int argc, char * argv[]) {
    char *line = NULL;
    size_t linecap = 0;
    ssize_t c;
    int tabstop = 4;
    int tabstart = 0;

    argv++;
    while (--argc > 0) {
        switch (*argv[0]) {
                case '+':
                    tabstop = argv2int(*argv);
                    break;
                case '-':
                    tabstart = argv2int(*argv);
                    break;
                default:
                    printf("unknown operand %c\n", *argv[0]);
                    break;

        }
        argv++;
    }

    while ((c=getline(&line,&linecap,stdin)) > 0) {
        detab(line, tabstop, tabstart);
    }
}
