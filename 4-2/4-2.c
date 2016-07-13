#include <stdio.h>

int main() {
    double sum, atof(char s[]);

    printf("%f\n", atof("123.456"));
    printf("%f\n", atof("-555.333"));
    printf("%f\n", atof("123.45e6"));
    printf("%f\n", atof("123.45e-6"));
}

