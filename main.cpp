#include <iostream>

#include "chains/Chained.hpp"
#include "exponents/Exponential.hpp"

unsigned int iteratesCount;

/// Creates table of values using
/// exponential view of hyperbolic cosine
/// and continued-fractions view of hyperbolic consine
/// Exponential::ch(x)  | Chained::ch(x)
/// \param a start of distance
/// \param b end of distance
int count_cosh(double a, double b) {
    auto *cInstance = new Chained(iteratesCount);
    double x = a, dx = 0.1;
    while (x < b) {
        std::cout << x << '\t' << cInstance->sh2(x) << std::endl;
        x += dx;
    }

    delete cInstance;
    return 0;
}

/// Creates table of calues using
/// exponential (standard) view of
/// sh(x) and continued fractions view of it
/// use start and end parameters for draw
/// Exponential::sh(x) | Chained::sh(x)
/// \param a start of distance
/// \param b end of distance
/// \return
void count_sinh(double a, double b) {
    auto *cInstance = new Chained(iteratesCount);
    double x = a, dx = 0.1;
    while (x < b) {
        std::cout << Exponential::sh(a) << '\t' << cInstance->sh2(a) << std::endl;
        x += dx;
    }
    delete cInstance;
}

/// Creates table of values using
/// exponential (standard) view of
/// sh(x) and continued fractions view of it
/// use start and end parameters for draw
/// Exponential::sh(x) | Chained::sh(x)
/// \param a start of distance
/// \param b end of distance
/// \return
void count_tanh(double a, double b) {
    auto *cInstance = new Chained(iteratesCount);
    double x = a, dx = 0.1;
    while (x < b) {
        std::cout << Exponential::th(x) << '\t' << cInstance->th(x) << std::endl;
        x += dx;
    }

    delete cInstance;
}

/// Creates table of sine values using
/// infinite continued-fractions approximation
/// more information see in main.pdf or sin.pdf
/// or inside Chained class you see info
/// about how it works...
/// I've written there my calculates
/// and minds about this way to draw sin(x).
/// \param a start of distance
/// \param b end of distance
/// \return
int count_sin(double a, double b) {
    auto *cInstance = new Chained(iteratesCount);
    double x = a, dx = 0.1;
    while (x < b) {
        std::cout << cInstance->sh2(x) << std::endl;
        x += dx;
    }

    delete cInstance;
    return 0;
}

int main() {
    // initialize global source
    iteratesCount = 1000;
    double start = -3, end = 3;
    count_sin(start, end);
    count_sinh(start, end);
    count_cosh(start, end);
    count_tanh(start, end);
    return 0;
}