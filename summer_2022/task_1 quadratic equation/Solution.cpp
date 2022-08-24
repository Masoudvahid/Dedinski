#include <stdio.h>
#include <math.h>
#include <assert.h>

void quadratic_equation(double, double, double, double &, double &);

int main() {
    double A;
    double B;
    double C;
    double X1;
    double X2;

    // Input variables
    puts("Enter the coefficients A, B and C of your task_1 quadratic equation.\n");
    scanf("%lf%lf%lf", &A, &B, &C);

    // Calculate the roots using quadratic_equation function
    quadratic_equation(A, B, C, X1, X2);

    return 0;
}

void quadratic_equation(const double A, const double B, const double C, double &X1, double &X2) {
    // Check if all variables have been entered
    assert(A != NULL);
    assert(B != NULL);
    assert(C != NULL);

    // Check if all variables are qualified for the calculation
    assert(A != 0);

    // Calculate discriminant
    double discriminant = 0;
    discriminant = pow(B, 2) - (4 * A * C);
    X1 = (-B + sqrt(discriminant)) / 2 * A;
    X2 = (-B - sqrt(discriminant)) / 2 * A;

    // Define different possibilities for the roots
    enum root_types {
        real_and_distinct,
        real_and_equal,
        imaginary_and_unequal
    };
    root_types root_type;
    if (discriminant > 0) {
        root_type = real_and_distinct;
    } else if (discriminant == 0) {
        root_type = real_and_equal;
    } else {
        root_type = imaginary_and_unequal;
    }

    // Check different possibilities for the roots
    switch (root_type) {
        case real_and_distinct:
            printf("Roots are real and distinct\nX1 = %lf\nX2 = %lf", X1, X2);
            break;
        case real_and_equal:
            printf("Roots are real and equal\nX1 = X2 = %lf", X1);
            break;
        case imaginary_and_unequal:
            printf("Roots are imaginary and unequal\n");
            break;
    }
}
