//
// This is solver for quadratic equations
//

#include "solver.h"
#include "IO.h"
#include <cmath>
#include <cassert>

inline bool IsEqual(double first, double second) {
    return abs(first - second) <= DBL_EPSILON * abs(first);
}

PossibleRootNumbers SolveLinearEquations(const double a, const double b, const double c, double *x) {
    if (IsEqual(b, 0)) {
        if (IsEqual(c, 0)) {
            return infinite_roots;
        } else {
            return no_roots;
        }
    }
    *x = -c / b;
    return one_root;
}

PossibleRootNumbers SolveEquations(const double a, const double b, const double c, double *x1, double *x2) {
    /*// Check if all variables have been entered
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);*/

    // Check if all variables are qualified for the calculation
    if (IsEqual(a, 0)) {
        return SolveLinearEquations(a, b, c, &(*x1));
    }

    // Calculate discriminant
    double discriminant = 0;
    discriminant = pow(b, 2) - (4 * a * c);
    double sqrt_discriminant = sqrt(discriminant);
    *x1 = (-b + sqrt_discriminant) / (2 * a);
    *x2 = (-b - sqrt_discriminant) / (2 * a);

    // Define different possibilities for the roots
    if (discriminant > 0) {
        return two_roots;
    } else if (discriminant == 0) {
        return two_equal_roots;
    } else {
        return two_imaginary_roots;
    }
}