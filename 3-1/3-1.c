#include <stdio.h>

int binsearch(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n-1;

    while (low <= high) {
        mid = (low+high)/2;

        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int rbinsearch(int a[], int x, int min, int max) {
    int low, mid, high;
    mid = (min+max-1)/2;
    if (a[mid] == x) {
        return mid;
    }

    if (x > mid)
        return rbinsearch(a, x, mid, max-1);
    else
        return rbinsearch(a, x, min, mid);
    return -1;
}

int main() {
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    printf("%d\n", binsearch(40, a, 10));
    printf("%d\n", rbinsearch(a, 40, 0, 10));
    printf("%d\n", rbinsearch(a, 100, 0, 10));
    printf("%d\n", rbinsearch(a, 10, 0, 10));
}
