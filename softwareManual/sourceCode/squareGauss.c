#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	int i, j = 0;
	int m = 3;
	int n = 3;

	// alloc memory for a matrix
	double **A;
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// alloc memory for a vector
	double *b;
	b = calloc(n, sizeof(double));

	A[0][0] = 1.0;  A[0][1] = -2.0; A[0][2] = -6.0;
	A[1][0] = 2.0;  A[1][1] = 4.0; A[1][2] = 12.0;
	A[2][0] = 1.0; A[2][1] = -3.0; A[2][2] = -12.0;

	b[0] = 5.0; b[1] = 0.0; b[2] = -2.0;

	printf("Upper triagular augmented matrix A =\n");

	printAugMatrix(A, b, m, n);

	squareGauss(A, b, n);

	printf("\n\n\n");

	printf("Gauss Elimination on augmented matrix A=\n");

	printAugMatrix(A, b, m, n);

	printf("\n\n\n");


	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);

	free(b);

	return 0;
}