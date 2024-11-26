#include <stdio.h>
#include <stdlib.h>

extern double daxpy(double a, double x, double y);

int main() {
    int n; // size of the vectors
    double A; // scalar multiplier

    printf("Enter the scalar value A: ");
    scanf("%f", &A);

    printf("Enter the size of the vectors (n): ");
    scanf("%d", &n);

    double *X = (double *)malloc(n * sizeof(double));
    double *Y = (double *)malloc(n * sizeof(double));
    double *Z = (double *)malloc(n * sizeof(double));

    if (X == NULL || Y == NULL || Z == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements for vector X:\n", n);
    for (int i = 0; i < n; i++) {
        printf("X[%d]: ", i);
        scanf("%f", &X[i]);
    }

    printf("Enter %d elements for vector Y:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Y[%d]: ", i);
        scanf("%f", &Y[i]);
    }
    
    for (int i = 0; i < n; i++) {
        Z[i] = daxpy(A, X[i], Y[i]);
    }

    printf("Resulting vector Z:\n");
    for (int i = 0; i < n; i++) {
        printf("Z[%d] = %f\n", i, Z[i]);
    }

    free(X);
    free(Y);
    free(Z);

    return 0;
}
