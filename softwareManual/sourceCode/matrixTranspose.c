#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, k = 0;

	int m = 3; // rows
	int n = 3; // col

	// alloc memory for a matrix
	double **A;
	A = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		A[i] = calloc(n, sizeof(double));
	}

	// alloc memory for a matrix
	double **C;
	C = calloc(m, sizeof(double*));

	for (i = 0; i < m; i++)
	{
		C[i] = calloc(n, sizeof(double));
	}

	// assign even values to matrix A
	k = 1;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = k * 2;
			k++;
		}
	}

	printf("\n\n\n");

	printf("\n\nMatrix A =\n");

	printMatrix(A, m, n);

	transposeMatrix(A, C, m, n);

	printf("\n\n\n");

	printf("\n\nMatrix C = A transpose\n");

	printMatrix(C, m, n);

	printf("\n\n\n");


	// free memory
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);

	// free memory
	for (i = 0; i < m; i++)
	{
		free(C[i]);
	}

	free(C);

	return 0;
}