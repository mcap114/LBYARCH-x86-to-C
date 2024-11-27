double daxpy_c(double a, double *X, double *Y, double *Z, int n) {
    for (int i = 0; i < n; i++) {
        Z[i] = a * X[i] + Y[i];
    }
}

