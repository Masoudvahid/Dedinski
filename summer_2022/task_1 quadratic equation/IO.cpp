#include <cstdio>
#include <stdlib.h>
#include "IO.h"

void InputCoefficients(double *a, double *b, double *c) {
    puts("Enter the coefficients a, b and c of your quadratic equation.\n");
    if (scanf("%lf%lf%lf", &(*a), &(*b), &(*c)) != 3) {
        puts("Invalid coefficients entered.\n");
        exit(-1);
    }
}

void OutputRoots(const double x1, const double x2, const PossibleRootNumbers number_of_roots) {
    // Check different possibilities for the roots
    switch (number_of_roots) {
        case no_roots:
            printf("No roots");
            break;
        case one_root:
            printf("One real root exits\nx1 = %lf", x1);
            break;
        case two_roots:
            printf("Roots are real and distinct\nx1 = %lf\nx2 = %lf", x1, x2);
            break;
        case two_equal_roots:
            printf("Roots are real and equal\nx1 = x2 = %lf", x1);
            break;
        case two_imaginary_roots:
            printf("Roots are imaginary and unequal\n");
            break;
        case infinite_roots:
            printf("Infinite number of roots\n");
            break;
    }
}
