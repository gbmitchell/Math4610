# Math 4610 Fundamentals of Computational Mathematics
Homework 4 problem 4.

**Routine Name:**           backSub

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This routine will carry out back substitution to solve for the unkown values of vector x in the problem Ax=b. A is an upper triangular matrix, x is a vector of unknowns, and b is a vector of known values. The problem Ax=b represents a linear system of n equations and n unknowns. Back substitution solves for the values of in order of xn, ....., x3, x2, x1.

**Input:** There are four inputs needed in this case to back solve the problem Ax=b. An upper triangular matrix, a vector of unkown values, a vector of given values, and a value to indicate the size of the matrix and vectors. The matrix and vectors are passed to the routine by reference.

**Output:** This routine does not return anything, instead it changes the values for the vector of unknowns. The solved values for the vector of unknowns can then be used as needed.

**Usage/Example:**

There are four inputs needed in this case to back solve the problem Ax=b. An upper triangular matrix (B), a vector of unkown values (xb), a vector of given values (bb), and a value to indicate the size of the matrix and vectors (n). The matrix and vectors are passed to the routine by reference. This routine does not return anything, instead it changes the values for the vector of unknowns. The solved values for the vector of unknowns can then be used as needed.

    #include "mylib.h"
    #include <stdio.h>

    int main() {
        int i, j = 0;
        int n = 0;
        int m = 0;

        // 3x3
        double B[50][50] = { {1.0, -2.0, -6.0}, {2.0, 4.0, 12.0}, {1.0, -3.0, -12.0} };
        double bb[50] = { 5.0, 0.0, -2.0 };
        double xb[50] = { 0 };

        m = 3;
        n = 3;

        squareGauss(B, bb, n);

        printf("Gaussian elimination on augmented matrix B =\n");

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3e\t", B[i][j]);
            }
            printf("|%.3e\n", bb[i]);
        }

        backSub(B, xb, bb, n);

        printf("\n\n\n");

        printf("Solution using back substitution on augmented matrix B\n");

        for (i = 0; i < n; i++) {
            printf("x%d = %.3e\n", i + 1, xb[i]);
        }

        return 0;
    }

Output from the lines above:

    Gaussian elimination on augmented matrix B =
    1.000e+00       -2.000e+00      -6.000e+00      |5.000e+00
    0.000e+00       8.000e+00       2.400e+01       |-1.000e+01
    0.000e+00       0.000e+00       -3.000e+00      |-8.250e+00



    Solution using back substitution on augmented matrix B
    x1 = 2.500e+00
    x2 = -9.500e+00
    x3 = 2.750e+00

The output from the example code prints the values for the upper triangular matrix B augmented with the known values of the vector bb. The routine then back solves for the values in the vector of unknowns and stores those values in the vector xb. The stored values are then printed as the solution to the problem Ax=b.

**Implementation/Code:** The following is the code for backSub()

    void backSub(double A[50][50], double x[50], double b[50], int n) {
        int i, j = 0;
        double sum = 0.0;

        x[n] = b[n] / A[n][n];
        for (i = n - 1; i > -1; i--) {
            sum = 0.0;
            for (j = (i + 1); j < n; j++) {
                sum = sum + (A[i][j] * x[j]);
            }
            x[i] = (b[i] - sum) / A[i][i];
        }
    }

**Last Modified:** November/2018
