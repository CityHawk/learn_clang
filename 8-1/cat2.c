#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024

void filecopy(int s, int d) {
    char buf[BUFSIZE];

    int n;

    while ((n = read(s,buf, BUFSIZE)) > 0) {
        if (write(d, buf,n) != n) {
            char *t = "error writing to output";
            write(2, t, strlen(t));
        }
    }

}

/* cat:  concatenate files, version 2 */
int main(int argc, char *argv[])
{
    int fd;

    if (argc == 1)  /* no args; copy standard input */
        filecopy(0, 1);
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY)) == -1) {
                char *_t = NULL;
                sprintf(_t, "can't open %s\n", *argv);
                write(2, _t, sizeof(_t));
                exit(1);
            } else {
                filecopy(fd, 1);
                close(fd);
            }
    exit(0);
}
