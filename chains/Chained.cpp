//
// Created by MagicBook on 03.03.2025.
//

#include "Chained.hpp"

/// th05x
/// Calculates the fractional part of the hyperbolic function
/// approximation (cosh(x)) using a continued fraction.
///
/// Argument Conversion:
/// It first converts the input argument x by calculating a = (x/2)^2.
/// This transformation is due to the fact that the continued fraction
/// is used to approximate th(x/2), and not ch(x) itself.
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
/// \return f64 result
double Chained::th05x(const double *x) {
    if (_defaultTimes == 0) {
        throw std::invalid_argument("times must be greater than 0");
    }

    double x2 = *x * *x;

    pB.back() = 2 * _defaultTimes; // 2n, n = _defaultTimes
    pC.back() = pB.back();

    // filling args like "up to down"
    for (int i = (int)_defaultTimes - 2; i >= 0; --i) {
        pB[i] = 2 * (i + 1); // 2, 4, 6, ...
        pC[i] = pB[i] + x2 / pC[i + 1];
    }

    return x2 / pC[0];
}
/// Second idea to compute tanh(x/2) for construct
/// based hyperbolic functions.
/// \param x
/// \return
double Chained::th05xs(const double *x) {
    if (_defaultTimes == 0) {
        throw std::invalid_argument("times must be greater than 0");
    }

    double a = pow(*x, 2) / 4; // (x/2)^2
    // initialize last fraction's level
    pB.back() = 2 * _defaultTimes + 1; // 3, 5, 7,... {2n+1}
    pC.back() = pB.back();

    for (int i = (int)_defaultTimes - 2; i >= 0; --i) {
        pB[i] = 2 * (i + 1) + 1; // 3, 5, 7, ... {2n+1}
        pC[i] = pB[i] + a / pC[i + 1];
    }

    // addition (x/2)
    return (*x / 2) / (1 + a / pC[0]);
}

/// Calls contuiueous fractions compiler and result it
/// ch(x) = 1 + C, where C is big chained-fraction
/// of consine argument.
/// \param x
/// \return f64 result for cosine
double Chained::ch(double x) {
    return (1 + th05x(&x));
}
/// Calls continueous fractions compiler and results it
/// using idea:
/// lets big c-fraction = C;
/// sh(x) = x * 1 + C
///             -----
///               3
///
/// \param x angle (Rad)
/// \return f64 result for
double Chained::sh(double x) {
    return x * (1 + th05x(&x) / 3);
}
/// Function links "pure" th(x) using th(x/2)
/// appriximation
/// Lets use angle power:
/// th(x) = x *  1 - 4th(x/2)
///             --------------
///                 3 * 5
/// \param x angle (Rad)
/// \return
double Chained::th(double x) {
    return x * (1 - th05x(&x) * 4 / (3 * 5));
}
/// Hyprebolic ctan, if i still remember
/// is reversed th(x). So, lets reverse it
/// \param x angle (Rad)
/// \return
double Chained::cth(double x) {
    // i try to make more elegant equalization.
    return (1 / th(x));
}
/// Updates Epsilon value.
/// \param e
void Chained::sete(double e) {
    _epsilon = e;
}

/// Builds sin result using "infinite" chained-fractions
/// Later i've tried to construct that by-hand on the paper
/// Tonight i've decided to remake it and now it works.
///
/// \param x angle in (Rad)
/// \return f64 result
double Chained::sin(double x) {
    // attempt 29
    // [-π, π] normalization
    x = fmod(x + M_PI, 2 * M_PI) - M_PI;

    double x2 = x * x;
    double result = 0.0;

    for (int n = (int)_defaultTimes; n >= 1; --n) {
        // reconstruct denumerator
        double numerator = (2 * n) * (2 * n + 1) * x2;
        double denominator = (2 * n + 2) * (2 * n + 3) - x2 + result;
        result = numerator / denominator;
    }
    return x / (1 + result);
}

/// My shcizo idea is compile large sine function
/// which approximates on lagrer set [-3PI; +3PI]
/// Compiles result from "infinite" c-fractions
/// updates depth [_defaultTimes]
/// \param x angle (in Rad)
/// \return f64 result of approximation.
double Chained::lsin(double x) {
    x = fmod(x + M_PI, 2 * M_PI) - M_PI;
    // what if long sin(x)? args > -3pi<->3pi scope?
    double x2 = x * x;
    double result = 0.0;

    for (int n = (int)_defaultTimes; n >= 1; --n) {
        double numerator = (2 * n) * (2 * n + 1) * x2;
        double denominator = (2 * n + 2) * (2 * n + 3) - x2 + result;
        result = numerator / denominator;
    }

    return x / (1 + result);
}
/// Builds hyperbolic consine
/// using second implementation of
/// approximation th(x/2).
/// \param x angle (Rad)
/// \return
double Chained::ch2(double x) {
    return (1 + th05xs(&x));
}
/// Builds hyperbolic sine
/// using second implementation of
/// approximation th(x/2)
/// \param x angle (Rad)
/// \return
double Chained::sh2(double x) {
    return x * (1 + th05x(&x) / 3);
}