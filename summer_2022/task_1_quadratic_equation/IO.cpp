#include "IO.h"

void InputCoefficients(double *a, double *b, double *c) {
    printf("Enter the coefficients a, b and c of your quadratic equation.\n");
    while (scanf("%lg%lg%lg", a, b, c) != 3) {
        printf("Invalid coefficients entered. Please enter valid numbers\n");

        while (getchar() != '\n') { } // Input while correct format is entered
    }
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);
}

void OutputRoots(const double x1, const double x2, const RootsAmount number_of_roots) {
    switch (number_of_roots) {
        case NO_ROOTS:
            printf("No roots");
            break;
        case ONE_ROOT:
            printf("One real root exits\nb = %lg", x1);
            break;
        case TWO_ROOTS:
            printf("Roots are real and distinct\nb = %lg\nc = %lg", x1, x2);
            break;
        case IMAGINARY_ROOTS:
            printf("Roots are imaginary and unequal\n");
            break;
        case INFINITY_ROOTS:
            printf("Infinite number of roots\n");
            break;
    }
}
