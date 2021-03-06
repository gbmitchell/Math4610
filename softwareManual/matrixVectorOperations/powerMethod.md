# Math 4610 Fundamentals of Computational Mathematics
Software Manual

**Routine Name:**           powerMethod

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    powerMethod.c

will produce an executable **powerMethod.exe** that can be executed.

**Description/Purpose:** This routine will compute the largest eigenvalue of a matrix.

**Input:** There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference.

**Output:** This routine returns a double precision value that represents the largest eigenvalue of the matrix A.

**Usage/Example:**

There are five inputs needed in this case to compute the largest eigenvalue. A square matrix A, a vector v, a variable tol for error, a variable maxiter value to stop infinite loops, and a value n to indicate the size of the matrix and vector. The matrix and vectors are passed to the routine by reference. This routine returns a double precision value that represents the largest eigenvalue of the matrix A.

    #include "mylib.h"
    #include <stdio.h>
    #include <stdlib.h>


    int main() {
        int i, j = 0;
        int n = 3;
        int m = 3;
        int maxiter = n * 6000;
        double tol = 0.0001;
        double eigenvalue = 0.0;

        // allocate mxn matrix
        double **A;
        A = calloc(m, sizeof(double*));

        for (i = 0; i < m; i++)
        {
            A[i] = calloc(n, sizeof(double));
        }

        // allocate vector for solution
        double *v;
        v = calloc(n, sizeof(double));

        A[0][0] = 4.0; A[0][1] = 1.0; A[0][2] = 2.0;
        A[1][0] = 1.0; A[1][1] = 5.0; A[1][2] = 3.0;
        A[2][0] = 2.0; A[2][1] = 3.0; A[2][2] = 6.0;

        v[0] = 1.0; v[1] = 1.0; v[2] = 1.0;

        printf("Matrix A =\n");

        printMatrix(A, m, n);

        eigenvalue = powerMethod(A, v, tol, maxiter, n);

        printf("Largest eigenvalue of matrix A = %.3e", eigenvalue);

        // free memory
        for (i = 0; i < m; i++)
        {
            free(A[i]);
        }

        free(A);
        free(v);

        return 0;
    }

Output from the lines above:

    Matrix A =
    4.000e+00       1.000e+00       2.000e+00
    1.000e+00       5.000e+00       3.000e+00
    2.000e+00       3.000e+00       6.000e+00

    Finished after 6 iterations
    
    Largest eigenvalue of matrix A = 9.419e+00

The output shows the matrix A, the largest eigenvalue of matrix A, and the number of iterations it took to compute the eigenvalue.

**Implementation/Code:** The following is the code for powerMethod()

    double powerMethod(double **A, double *v0, double tol, int maxiter, int n) {
        int i, j = 0;
        int iter = 0;
        double temp = 0.0;
        double eigen0 = 0.0;
        double eigen1 = 0.0;
        double err = 10 * tol;

        // alloc memory for a vector
        double *y;
        y = calloc(n, sizeof(double));

        // alloc memory for a vector
        double *v1;
        v1 = calloc(n, sizeof(double));

        vectorXmatrix(A, v0, y, n, n);

        while ((err > tol) && (iter < maxiter)) {
            iter++;

            temp = vectorNormL2(y, n);

            for (i = 0; i < n; i++) {
                v1[i] = y[i] / temp;
            }

            eigen1 = vectorInner(v1, y, n);

            vectorXmatrix(A, v1, y, n, n);

            err = eabs(eigen1, eigen0);

            eigen0 = eigen1;

        }
        printf("Finished after %d iterations\n\n", iter);

        // free memory
        free(y);
        free(v1);

        return eigen0;
    }

**Last Modified:** November/2018
