#include <stdio.h>
#include <stdlib.h>

// extern double daxpy(double a, double *x, double *y, double *z, int n);

extern void daxpy_c(double a, const double *X, const double *Y, double *Z, int n);

int main() {
    double A = 2.0;
    int n = 3;

    double X[3] = {1.0, 2.0, 3.0};
    double Y[3] = {11.0, 12.0, 13.0};
    double Z[3];

    printf("Calling daxpy_c with A = %f, n = %d\n", A, n);
    daxpy_c(A, X, Y, Z, n);
    printf("Returned from daxpy_c\n");

    for (int i = 0; i < n; i++) {
        printf("Z[%d] = %f\n", i, Z[i]);
    }

    return 0;
}


