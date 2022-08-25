/**
 * @brief unit testing
 */
#ifndef EQUATIONS_UNIT_TEST_H
#define EQUATIONS_UNIT_TEST_H

#include "solver.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>    // For colorful output

using namespace std; // For colorful output

/**
 * @brief Store coefficients of test cases
 */
typedef struct {
    double a; /**< coefficient of x^2 */
    double b; /**< coefficient of x */
    double c; /**< constant coefficient */
} Coefficients;

/**
 * @brief Store the answers of test cases
 */
typedef struct {
    int roots_amount; /**< number of roots */
    double x1;        /**< first root */
    double x2;        /**< second root */
} Answers;

/**
 * @brief Store the roots from SolveEquation function
 */
typedef struct {
    double x1; /**< first root */
    double x2; /**< second root */
} Roots;

static const char *ROOT_NUMBERS_NAMES[] = {"NO_ROOTS", "ONE_ROOT", "TWO_ROOTS", "INFINITY_ROOTS", "IMAGINARY_ROOTS"};

/**
 * @brief Test SolveEquation function
 * @see SolveEquation(const double a, const double b, const double c, double *x1, double *x2)
 */
void Test();

/**
 * @brief print the result of provided test
 * @param[in] roots_amount The number of roots retrieved from SolveEquation function
 * @see SolveEquation(const double a, const double b, const double c, double *x1, double *x2)
 * @param[in] roots The roots retrieved from SolveEquation function
 * @see SolveEquation(const double a, const double b, const double c, double *x1, double *x2)
 * @param[in] test_case_answers The answers of provided test case.
 * @return True whether the test is passed successfully, False otherwise
 */
bool TestResult(const RootsAmount roots_amount, const Roots roots, const Answers test_case_answers);


#endif //EQUATIONS_UNIT_TEST_H
