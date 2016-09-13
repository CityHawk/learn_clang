#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <libgen.h>

char trfunc(char c, char (*fnc) (char)) {
    return fnc(c);
}
int main(int argc, char **argv) {
    char upper,c;
    upper = strcmp(basename(*argv), "tr") == 0 ? 0 : 1;

    while ((c=getchar()) != EOF) putchar(trfunc(c,(char (*)(char c)) (upper ? toupper : tolower)));
}
