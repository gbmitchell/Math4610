#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, k = 0;
	double innerProduct = 0.0;

	int n = 3;

	// alloc memory for a vector
	double *v1;
	v1 = calloc(n, sizeof(double));

	// alloc memory for a vector
	double *v2;
	v2 = calloc(n, sizeof(double));

	// assign values to vector v1
	k = 4;
	for (i = 0; i < n; i++) {
		v1[i] = k;
		k++;
	}

	// assign values to vector v2
	k = 7;
	for (i = 0; i < n; i++) {
		v2[i] = k;
		k++;
	}

	printf("\n\n\n");

	printf("\n\nVector v1 =\n");

	printVector(v1, n);

	printf("\n\n\n");

	printf("\n\nVector v2 =\n");

	printVector(v2, n);

	innerProduct = vectorInner(v1, v2, n);

	printf("\n\n\n");

	printf("\n\nInner Product of  v1 and v2 = %.3e\n", innerProduct);

	printf("\n\n\n");


	// free memory
	free(v1);
	free(v2);

	return 0;
}