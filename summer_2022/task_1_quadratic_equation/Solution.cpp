#include "IO.h"
#include "solver.h"
#include "unit_test.h"

#define NDEBUG  //is for release (no asserts there)


int main() {
#ifdef NDEBUG
    Test();
#else

    double a = NAN;
    double b = NAN;
    double c = NAN;

    double x1 = NAN;
    double x2 = NAN;

    // Input variables
    InputCoefficients(&a, &b, &c);

    // Calculate the roots using SolveEquation function
    RootsAmount n_roots = SolveEquation(a, b, c, &x1, &x2);

    // Output the result of calculations
    OutputRoots(x1, x2, n_roots);

#endif

    return 0;
}
