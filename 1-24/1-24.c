#include <stdio.h>

int main() {
    int c;
    int nbrakets_open,nfigbrakets_open,nsqbrakets_open;

    nbrakets_open = 0;
    nsqbrakets_open = 0;
    nfigbrakets_open = 0;

    while ((c=getchar())!=EOF) {
        if (c == '(') {
            nbrakets_open++;
        } else if (c == ')') {
            nbrakets_open--;
        } else if (c == '{') {
            nfigbrakets_open++;
        } else if (c == '}') {
            nfigbrakets_open--;
        } else if (c == '[') {
            nsqbrakets_open++;
        } else if (c == ']') {
            nsqbrakets_open--;
        }
    }

    if (nsqbrakets_open != 0 || nfigbrakets_open != 0 || nbrakets_open != 0 ){
        printf("nbrakets_open: %d; \n", nbrakets_open);
        printf("nsqbrakets_open: %d; \n", nsqbrakets_open);
        printf("nfigbrakets_open: %d; \n", nfigbrakets_open);
        printf("INCORRECT\n");
        return 1;
    } else {
        printf("nbrakets_open: %d; \n", nbrakets_open);
        printf("nsqbrakets_open: %d; \n", nsqbrakets_open);
        printf("nfigbrakets_open: %d; \n", nfigbrakets_open);
        printf("CORRECT\n");
        return 0;
    }
}
