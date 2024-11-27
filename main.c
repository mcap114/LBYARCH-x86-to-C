#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

extern double daxpy_asm(double a, double *x, double *y, double *z, int n);

extern void daxpy_c(double a, const double *X, const double *Y, double *Z, int n);

int main() {

    // scalar multiplier
    double A = 2.0; 

    // vector size
    /*
     2^20 = 1048576
     2^24 = 16777216
     2^27 = 134217728
     2^28 = 268435456
     2^29 = 536870912
     2^30 = 1073741824
    */
    int n = 1048576;

    // number of runs for execution time test
    int runcount = 30;

    // vector declarations and 
    double *X = (double *)malloc(n * sizeof(double));
    double *Y = (double *)malloc(n * sizeof(double));
    double *Z_c = (double *)malloc(n * sizeof(double));
    double *Z_x86 = (double *)malloc(n * sizeof(double));

    if (X == NULL || Y == NULL || Z_c == NULL || Z_x86 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // sample test case
    /* 
    double X[3] = {1.0, 2.0, 3.0};
    double Y[3] = {11.0, 12.0, 13.0};
    double Z[3];
    */
   
   // generate vector of n size with randomized entries (range of 1.0 - 100.0)
   for (int i = 0; i < n; i++) {
        X[i] = (double)(rand() % 1000) / 10.0; 
        Y[i] = (double)(rand() % 1000) / 10.0;
    }

    // FOR CHECKING: first 10 elements of each vector
    /*
    printf("First 10 elements of vector X:\n");
    for (int i = 0; i < 10 && i < n; i++) { // Ensure we don't exceed vector size
        printf("X[%d] = %.2f\n", i, X[i]);
    }

    printf("First 10 elements of vector Y:\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("Y[%d] = %.2f\n", i, Y[i]);
    }
    */

    // Measure execution time for C kernel
    clock_t start, end;
    double total_time_c = 0.0;

    for (int i = 0; i < runcount; i++) {
        start = clock();
        daxpy_c(A, X, Y, Z_c, n);
        end = clock();
        total_time_c += (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    }

    printf("\nFirst 10 elements of c kernel output:\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("Z_c[%d] = %.2f\n", i, Z_c[i]);
    }
    double avg_time_c = total_time_c / runcount;
    printf("Average execution time for c kernel: %.3f ms\n", avg_time_c);

    // Measure execution time for x86 kernel
    double total_time_x86 = 0.0;

    for (int i = 0; i < runcount; i++) {
        start = clock();
        daxpy_asm(A, X, Y, Z_x86, n);
        end = clock();
        total_time_x86 += (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    }

    printf("\nFirst 10 elements of x86 kernel output:\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("Z_x86[%d] = %.2f\n", i, Z_x86[i]);
    }
    double avg_time_x86 = total_time_x86 / runcount;
    printf("Average execution time for x86 kernel: %.3f ms\n", avg_time_x86);

    // check if results are the same
    bool results_match = true;
    for (int i = 0; i < 10 && i < n; i++) {
        if (Z_c[i] != Z_x86[i]) {
            results_match = false;
            break;
        }
    }

    if (results_match) {
        printf("\nResults match.\n");
    } else {
        printf("\nResults do NOT match.\n");
    }

    // free allocated memory
    free(X);
    free(Y);
    free(Z_c);
    free(Z_x86);

    return 0;
}
