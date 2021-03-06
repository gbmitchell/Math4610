# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 8a.

**Routine Name:**           outerProductMatrix

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    matrixMath.c

will produce an executable **matrixMath.exe** that can be executed.

**Description/Purpose:** This function will take a 3x1 matrix and multiply it by a 1x3 matrix in double precision. The result is a 3x3 matrix and this is known as the outer product.

**Input:** There are five inputs needed in this case. Matrix x, y, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of multiplying matrix x by matrix y transpose.

**Output:** This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the result of multiplying matrix x by matrix y transpose. The resulting matrix C can then be used in the main program as needed.

**Usage/Example:**

There are five inputs needed in this case. Matrix x, y, and C are arguments passed by reference. Arguments also passed to the function are m and n to indicate the size of the matrices. The real purpose is to produce values in the matrix C that represent the result of multiplying matrix x by matrix y transpose. This function doesnt return a value. Because the matrix C was passed by reference, the function can modify the matrix C to produce the result of multiplying matrix x by matrix y transpose. The resulting matrix C can then be used in the main program as needed.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int j = 0;
        int m = 3; // rows
        int n = 3; // col
        double C[3][3] = { 0 };
        double x[3] = { 4, 5, 6 };
        double y[3] = { 7, 8, 9 };
        
        printf("\n\nVector x =\n");
    
        for (i = 0; i < m; i++) {
            printf("%.3lf\n", x[i]);
        }
    
        printf("\n\nVector y =\n");
    
        for (i = 0; i < m; i++) {
            printf("%.3lf\n", y[i]);
        }
    
        outerProductMatrix(x, y, C, m, n);
    
        printf("\n\nMatrix C = outer product of x and y\n");
    
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%.3lf\t", C[i][j]);
            }
            printf("\n");
        }    
    }    

Output from the lines above:

    Vector x =
    4.000
    5.000
    6.000
    
    Vector y =
    7.000
    8.000
    9.000
    
    Matrix C = outer product of x and y
    28.000  32.000  36.000
    35.000  40.000  45.000
    42.000  48.000  54.000

The output shows the values for matrix x and y. Additionally, the output shows the matrix C which is the result of multiplying matrix x by matrix y transpose. The result is called the outer product.

**Implementation/Code:** The following is the code for outerProductMatrix()

    void outerProductMatrix(double x[3], double y[3], double C[3][3], int m, int n) {
        int i, j = 0;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                C[i][j] = x[i] * y[j];
            }
        }
    }
    
# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 8b.

**Routine Name:**           vectorInner

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorMath.c

will produce an executable **vectorMath.exe** that can be executed.

**Description/Purpose:** This function will compute the inner product of two vectors of the same size and the computation is done in double precision. 

**Input:** There are three inputs needed in this case. Vectors u and v are arguments passed by reference and len is an argument passed to the function to indicate the length of the vectors.

**Output:** This function returns a double precision value which represents the inner product of the vectors u and v.

**Usage/Example:**

There are three inputs needed in this case. Vectors u and v are arguments passed by reference and len is an argument passed to the function to indicate the length of the vectors. This function returns a double precision value ia, which represents the inner product of the vectors u and v.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int len = 0;
        double ia = 0;
        double u[3] = { 1, 2, 3 };
        double v[3] = { 8, -7, 6 };
    
        len = sizeof(u) / 8;
    
        printf("\n\nVector u =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", u[i]);
        }
    
        printf("\n\nVector v =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", v[i]);
        }
    
        printf("\n\n\nInner product of u and v = ");
    
        ia = vectorInner(u, v, len);
    
        printf("%.3lf", ia);
    }

Output from the lines above:

    Vector u =
    1.000
    2.000
    3.000
    
    Vector v =
    8.000
    -7.000
    6.000
    
    Inner product of u and v = 12.000

The output shows the value for the vectors u and v as well as the resulting inner product of the vectors.

**Implementation/Code:** The following is the code for vectorInner()

    double vectorInner(double up[3], double vp[3], int len) {
        int i = 0;
        double ia = 0.0;
        for (i = 0; i < len; i++) {
            ia = ia + ( up[i] * vp[i]);
        }
        return ia;
    }
    
# Math 4610 Fundamentals of Computational Mathematics
Homework 3 problem 8c.

**Routine Name:**           vectorCross

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    vectorMath.c

will produce an executable **vectorMath.exe** that can be executed.

**Description/Purpose:** This function will compute the cross product of two vectors of the same size and the computation is done in double precision. 

**Input:** There are four inputs needed in this case. Vectors u, v, and a are arguments passed by reference and len is an argument passed to the function to indicate the length of the vectors. The real purpose is to produce values in the vector a that represent the cross product of the vectors u and v.

**Output:** This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the cross product the vectors u and v. The resulting vector a can then be used in the main program as needed.

**Usage/Example:**

There are four inputs needed in this case. Vectors u, v, and a are arguments passed by reference and len is an argument passed to the function to indicate the length of the vectors. This function doesnt return a value. Because the vector a was passed by reference, the function can modify the vector a to produce the cross product the vectors u and v. The resulting vector a can then be used in the main program as needed.

    #include "mylib.h"
    
    int main() {
        int i = 0;
        int len = 0;
        double u[3] = { 1, 2, 3 };
        double v[3] = { 8, -7, 6 };
        double a[3] = { 0 };
    
        len = sizeof(u) / 8;
    
        printf("\n\nVector u =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", u[i]);
        }
    
        printf("\n\nVector v =\n");
    
        for (i = 0; i < len; i++) {
            printf("%.3lf\n", v[i]);
        }

        printf("\n\n\nCross product of u and v =\n");

        vectorCross(u, v, a, len);

        for (i = 0; i < len; i++) {
            printf("%.3lf\n", a[i]);
        }
    }

Output from the lines above:

    Vector u =
    1.000
    2.000
    3.000
    
    Vector v =
    8.000
    -7.000
    6.000
    
    Cross product of u and v =
    33.000
    18.000
    -23.000

The output shows the value for the vectors u and v as well as the resulting cross product of the two vectors.

**Implementation/Code:** The following is the code for vectorCross()

    void vectorCross(double up[3], double vp[3], double ap[3], int len) {
        ap[0] = (up[1] * vp[2]) - (up[2] * vp[1]);
        ap[1] = (up[2] * vp[0]) - (up[0] * vp[2]);
        ap[2] = (up[0] * vp[1]) - (up[1] * vp[0]);
    }

**Last Modified:** October/2018
