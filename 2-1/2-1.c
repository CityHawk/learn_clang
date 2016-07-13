#include <stdio.h>
#include <limits.h>

int main() {
    /* signed int */
    int prevint = 0;
    int _int = 0;

    while (prevint >= _int) {
        prevint = _int;
        --_int;
    }

    printf("lowest int: %d, .h: %d\n", ++_int, INT_MIN);

    _int = 0;
    while (prevint <= _int) {
        prevint = _int;
        ++_int;
    }

    printf("largest int %d, .h: %d\n", --_int, INT_MAX);

    /* unsigned int */
    unsigned int prevuint = 0;
    unsigned int _uint = 0;

    while (prevuint >= _uint) {
        prevuint = _uint;
        --_uint;
    }

    printf("lowest uint: %d, .h: %d\n", ++_uint, 0);

    _uint = 0;
    while (prevuint <= _uint) {
        prevuint = _uint;
        ++_uint;
    }

    printf("largest uint %d, .h: %d\n", --_uint, UINT_MAX);

}

