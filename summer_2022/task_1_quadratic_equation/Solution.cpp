#include "IO.h"
#include "solver.h"
#include "unit_test.h"

#define Test_d // Comment this line to perform testing

int main() {
#ifdef Test_d
    Test();
#else
    double a = 0;
    double b = 0;
    double c = 0;

    double x1 = 0;
    double x2 = 0;

    // Input variables
    InputCoefficients(&a, &b, &c);

    // Calculate the roots using SolveEquation function
    RootsAmount n_roots = SolveEquation(a, b, c, &x1, &x2);

    // Output the result of calculations
    OutputRoots(x1, x2, n_roots);

#endif

    return 0;
}
