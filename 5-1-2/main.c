#include <stdio.h>
#define SIZE 1

int main() {
    int n, array[SIZE], getint(int *);

    /* for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) */
    /*     ; */
    /*  */
    /* for (n = 0; n < SIZE; n++) */
    /*     printf("%d\n", array[n]); */

    double arr[SIZE], getfloat(double *);
    for (n = 0; n < SIZE && getfloat(&arr[n]) != EOF; n++)
        ;

    for (n = 0; n < SIZE; n++)
        printf("%f\n", arr[n]);


}
