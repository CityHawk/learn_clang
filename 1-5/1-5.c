#include <stdio.h>

#define UPPER  300
#define LOWER  0
#define STEP   10
int main() {
    int step = 10;
    float farh;

    for (farh = UPPER; farh >= LOWER; farh = farh - STEP) {
        printf("%3.0f - %6.1f\n", farh, (5.0/9.0)* (farh - 32));
    }
}
