#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
    int c,prevc,pprevc,commentopen, stringopen;

    /* this is comment */
    commentopen = FALSE;
    stringopen = FALSE;
    printf("This /* is the comment in */ string\n");
    while ((c=getchar()) != EOF ) {
        pprevc = prevc;
        if (c == '"') {
            if (commentopen == FALSE && stringopen == FALSE) {
                stringopen = TRUE;
            } else if (commentopen == TRUE && stringopen == FALSE) {
                stringopen = FALSE;
            } else if (commentopen == FALSE && stringopen == TRUE) {
                stringopen = FALSE;
            } else {
                printf("Unexpected error\n");
            }
        }
        
        if (pprevc == '\'' && prevc == '"' & c == '\'')
            stringopen = FALSE;
        if (stringopen == FALSE) {
            if ('/' == prevc && '*' == c) {
                /* comment open */
                commentopen = TRUE;
                c = '\0';
            } else if ('*' == prevc && '/' == c) {
                /* comment close */
                commentopen = FALSE;
                c = '\0';
            } else if (('/' == prevc && '*' != c) || ('*' == prevc && '/' != c)) {
                putchar(prevc);
                putchar(c); /* and this is comment */
            } else if ('/' == c) {
                ;
            } else if ('*' == c) {
                ;
            } else {
                if (commentopen == FALSE)
                    putchar(c);
                /* "this is the string within comment" */
            }
        } else {
            putchar(c);
        }
        prevc = c;
    }
}
