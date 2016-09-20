#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if ( argc-- > 1) {
    } else {
        fprintf(stderr, "You should supply at least 1 file\n");
        exit(1);
    }
    return 0;
}
