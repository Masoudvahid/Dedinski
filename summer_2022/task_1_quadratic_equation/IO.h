/**
 * @brief Control input and output of quadratic equations
 */

#ifndef EQUATIONS_IO_H
#define EQUATIONS_IO_H

#include <cstdio>
#include <cassert>
#include "roots_amount.h"

/**
 * @brief Input coefficients of our quadratic equation
 * @param[in] a The x^2 coefficient
 * @param[in] b The x coefficient
 * @param[in] c The constant
 */
void InputCoefficients(double *const a, double *const b, double *const c);

/**
 * @brief Output number of roots of quadratic equation and roots
 * @param[out] x1 The first root
 * @param[out] x2 The second root
 * @param number_of_roots The number of roots of the equation
 */
void OutputRoots(const double x1, const double x2, const RootsAmount number_of_roots);

#endif // !EQUATIONS_IO_H
