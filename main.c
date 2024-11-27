#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double daxpy(double a, double *x, double *y, double *z, int n);

extern void daxpy_c(double a, const double *X, const double *Y, double *Z, int n);

int main() {

    // scalar multiplier
    double A = 2.0; 

    // vector size
    /*
     2^20 = 1048576
     2^24 = 16777216
     2^28 = 268435456
     2^29 = 536870912
     2^30 = 1073741824
    */
    int n = 536870912;

    // number of runs for execution time test
    int runcount = 30;

    // vector declarations and 
    double *X = (double *)malloc(n * sizeof(double));
    double *Y = (double *)malloc(n * sizeof(double));
    double *Z = (double *)malloc(n * sizeof(double));

    if (X == NULL || Y == NULL || Z == NULL) {
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

    // measure execution time
    clock_t start, end;
    double total_time = 0.0;

    for (int iter = 0; iter < runcount; iter++) {
        start = clock(); 
        daxpy_c(A, X, Y, Z, n);
        end = clock(); 
        total_time += (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    }

    // display the first 10 elements of Z
    printf("First 10 elements of vector Z:\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("Z[%d] = %.2f\n", i, Z[i]);
    }

    // calculate and print average execution time
    double avg_time = total_time / runcount;
    printf("Average execution time for daxpy_c: %.3f ms\n", avg_time);
    return 0;
}
