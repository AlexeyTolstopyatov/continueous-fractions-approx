//
// Created by MagicBook on 03.03.2025.
//

#include "Chained.hpp"

/// f
/// Calculates the fractional part of the hyperbolic function
/// approximation (cosh(x)) using a continued fraction.
///
/// Argument Conversion:
/// It first converts the input argument x by calculating a = (x/2)^2.
/// This transformation is due to the fact that the continued fraction
/// is used to approximate tanh(x/2), and not cosh(x) itself.
///
/// Initializing arrays:
/// It then initializes two arrays,
/// [pB] and [pC], with values that depend on the [_defaultTimes] parameter
/// and are used to calculate the continued fraction.
/// The pB array contains coefficients
/// that determine the structure of a continued fraction,
/// and the pC array is used to store intermediate calculation results.
///
/// Calculating a continued fraction:
/// The main part of the function is a loop that calculates
/// the continued fraction iteratively, starting from the
/// last term and moving to the first. At each step of the loop,
/// the value of [pC[i]] is calculated based on the values of [pB[i]],
/// [a], and [pC[i+1]].
/// This is a typical algorithm for calculating continued fractions from the bottom up.
///
/// Return result: At the end, the function returns
/// the value that is the result of calculating a continued fraction
/// multiplied by [a]. This value is an approximation
/// of the fractional part of cosh(x).
/// \param x
/// \return
double Chained::f(const double *x) {
    if (_defaultTimes == 0) {
        throw std::invalid_argument("defaultTimes must be greater than 0");
    }

    double a = pow(*x, 2) / 4; // (x/2)^2

    pB[_defaultTimes - 1] = 2 * _defaultTimes + 1;
    pC[_defaultTimes - 1] = pB[_defaultTimes - 1];
    int times = (int)_defaultTimes; // signed integer review

    for (int i = times - 2; i >= 0; --i) {
        pB[i] = 2 * (i + 1) + 1; // 2n+1 format - corrected index for b[i]
        pC[i] = pB[i] + a / pC[i + 1];
    }

    return (a / pC[0]);
}
double Chained::ch(double x) {
    return (1 + f(&x));
}
double Chained::sh(double x) {
    return x * (1 + f(&x) / 3);
}
double Chained::th(double x) {
    return x * (1 - f(&x) * 4 / (3 * 5));
}
double Chained::cth(double x) {
    // i try to make more elegant equalization.
    return (1 / th(x));
}