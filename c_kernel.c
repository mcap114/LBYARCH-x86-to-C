#include <stdio.h>

void daxpy_c(double a, const double *X, const double *Y, double *Z, int n) {
    for (int i = 0; i < n; i++) {
        Z[i] = a * X[i] + Y[i];
    }
}

