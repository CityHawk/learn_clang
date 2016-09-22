#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define PAGELEN 15

static int pagecount = 1;
static int linecount = 0;

void safeprintf(const char * restrict format, ...) {
    va_list va;
    va_start(va,format);

    if (linecount++ < PAGELEN)
        vprintf(format,va);
    else {
        printf("\n--- %d ---\n\n", pagecount++);
        linecount = 0;
    }
    va_end(va);
}

int main(int argc, char *argv[]) {

    if ( argc <= 1) {
        fprintf(stderr, "You should supply at least 1 file\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        safeprintf("-------------------\n");
        safeprintf("FILE: %s\n", argv[i]);
        safeprintf("-------------------\n");
        FILE *f = fopen(argv[i],"r");
        size_t linecapp = 0;
        char *line = NULL;
        while (getline(&line, &linecapp, f) != EOF) {
            safeprintf("%s", line);
        }
        fclose(f);
    }
    return 0;
}
