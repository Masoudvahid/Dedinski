/**
 * @file This is solver for quadratic equations
 */

#include "solver.h"

bool IsEqual(double first, double second) {
    // To consider more mathematical principles, we can compare with second number
    return fabs(first - second) <= DBL_EPSILON;
}

RootsAmount SolveLinearEquations(const double b, const double c, double *x) {
    assert(x != nullptr);

    if (IsEqual(b, 0)) {
        if (IsEqual(c, 0)) {
            return INFINITY_ROOTS;
        }

        return NO_ROOTS;
    }

    *x = -c / b;

    return ONE_ROOT;
}

RootsAmount SolveQuadratic(const double a, const double b, const double c, double *x1, double *x2) {
    // Calculate discriminant
    double discriminant = (b * b) - (4 * a * c);
    double sqrt_discriminant = sqrt(discriminant);

    *x1 = (-b + sqrt_discriminant) / (2 * a);
    *x2 = (-b - sqrt_discriminant) / (2 * a);

    // Define different possibilities for the roots
    if (discriminant > 0)
        return TWO_ROOTS;
    if (IsEqual(discriminant, 0))
        return ONE_ROOT;

    return IMAGINARY_ROOTS;
}

RootsAmount SolveEquation(const double a, const double b, const double c, double *x1, double *x2) {
    // Check if all variables are qualified for the calculation
    if (IsEqual(a, 0)) {
        return SolveLinearEquations(b, c, x1);
    } else if (IsEqual(c, 0)) {
        *x1 = 0;
        SolveLinearEquations(a, b, x2);
        return TWO_ROOTS;
    } else {
        return SolveQuadratic(a, b, c, x1, x2);
    }


}