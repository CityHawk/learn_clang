#include <stdio.h>

int main() {
    float farh, celsius;
    int upper,lower,step;

    upper = 300;
    lower = 0;
    step = 10;

    celsius = lower;
    while (celsius <= upper) {
        printf("%3.0f - %6.1f\n", celsius, (celsius * 9.0 / 5.0) + 32 );
        celsius = celsius + step;
    }
}
