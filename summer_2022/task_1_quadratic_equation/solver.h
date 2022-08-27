/**
 * @brief Solve the equation with provided coefficients
 */
#ifndef EQUATIONS_SOLVER_H
#define EQUATIONS_SOLVER_H

#define  DBL_EPSILON 2.220446e-6

#include <cmath>
#include <cassert>
#include "roots_amount.h"

/**
 * @brief Check if two provided numbers are equal
 * @param[in] first The first number
 * @param[in] second The second number
 * @return True in the case both numbers are equal and False otherwise
 */
bool IsEqual(double first, double second);

/**
 * @brief Solve linear equations if coefficient of x^2 is zero
 * @param b Coefficient of x
 * @param c Constant coefficient
 * @param x Pointer to the root
 * @return RootsAmount The number of roots of the linear equation
 */
RootsAmount SolveLinearEquations(const double b, const double c, double *x);

/**
 * @brief Solves the equation with provided coefficients
 * @param a Coefficient of x^2
 * @param b Coefficient of x
 * @param c Constant coefficient
 * @param x1 Pointer to the first root
 * @param x2 Pointer to the second root
 * @return RootsAmount The number of roots of the linear equation
 */
RootsAmount SolveEquation(const double a, const double b, const double c, double *x1, double *x2);

#endif // EQUATIONS_SOLVER_H
