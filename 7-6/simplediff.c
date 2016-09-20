#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 4096

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Should have 2 args\n");
        exit(1);
    }

    FILE *aFile, *bFile;
    aFile = fopen(argv[1], "r");
    bFile = fopen(argv[2], "r");

    char astr[MAXLINE], bstr[MAXLINE];

    int lineno = 0;
    while ((fgets(astr, MAXLINE, aFile) != NULL) && (fgets(bstr, MAXLINE, bFile)!=NULL)) {
        lineno++;
        if (strcmp(astr,bstr) != 0) {
            printf("%d > %s%d < %s\n", lineno,astr,lineno,bstr);
            exit(0);
        }
    }

    /* let's close them for good */
    fclose(aFile);
    fclose(bFile);
    return 0;
}
