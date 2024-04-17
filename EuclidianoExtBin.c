#include <stdio.h>

int euclideanExtendedBinary(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = euclideanExtendedBinary(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    int x, y;
    int gcd = euclideanExtendedBinary(a, b, &x, &y);

    printf("GCD: %d\n", gcd);
    printf("x: %d, y: %d\n", x, y);

    return 0;
}