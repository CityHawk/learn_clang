#include <stdio.h>

#define MAXTEMP 300
#define MINTEMP 0
#define STEP 5

float f2c(int farh);

int main() {
    int farh;

    for (farh = MINTEMP; farh <= MAXTEMP; farh += STEP) {
        printf("%3d %6.1f\n", farh, f2c(farh));
    }
}

float f2c(int farh) {
    return (5.0/9.0) * (farh - 32);
}
