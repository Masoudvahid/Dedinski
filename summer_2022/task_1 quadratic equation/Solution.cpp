
#include "IO.cpp"
#include "solver.cpp"

int main() {
    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    PossibleRootNumbers number_of_roots;

    // Input variables
    InputCoefficients(&a, &b, &c);

    // Calculate the roots using SolveEquations function
    number_of_roots = SolveEquations(a, b, c, &x1, &x2);

    // Output the result of calculations
    OutputRoots(x1, x2, number_of_roots);

    return 0;
}
