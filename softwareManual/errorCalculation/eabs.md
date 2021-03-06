# Math 4610 Fundamentals of Computational Mathematics
Software Manual.

**Routine Name:**           eabs

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    error.c

will produce an executable **error.exe** that can be executed.

**Description/Purpose:** The eabs function will compute the absolute error between v and u. The variable v is 
an approximation to the exact value u.

**Input:** There are two inputs needed in this case, the arguments v and u are passed to the function as inputs.

**Output:** The eabs function returns a double precision value that represents the absolute error based on the inputs.

**Usage/Example:**

The function has two inputs, the arguments v an u are type double. The variable v is an approximation to the exact
value u. The function returns a double precision value, the absolute error between v and u. 

    #include <mylib.h>
    
    int main() {
    
    double  approximate = 0.0;
    double exact = 0.0;
    double e = 0.0;
    
    approximate = 3.001;
    exact = 3.0;
    
    printf("x = %.8e, y = %.8e\n\n", approximate, exact);
    
    e = eabs(approximate, exact);
    printf("absolute error = %.8e\n", e);
    
    return 0;
    }

Output from the lines above:

    x = 3.00100000e+00, y = 3.00000000e+00
    
    absolute error = 1.00000000e-03

The value of x = 3.001 is the approximation to the the exact value of y = 3.000. The computed absolute error
between x and y is 1.000e-03.

**Implementation/Code:** The following is the code for eabs()

    double eabs(double v, double u) {
    double e = fabs(u - v);
    return e;
    }

**Last Modified:** September/2018
