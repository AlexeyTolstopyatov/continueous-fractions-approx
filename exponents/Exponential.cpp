//
// Created by MagicBook on 03.03.2025.
//

#include "Exponential.hpp"

// implement "brilliant hardware" operations
// using math notebooks... It will be template
// with what I'll compare my idea
/// Exponencial view of sh(x)
double Exponential::sh(double x) {
    return (exp(x) - exp(-x)) / 2;
}
/// Exponencial view of ch(x)
double Exponential::ch(double x) {
    return (exp(x) + exp(-x)) / 2;
}
/// Exponential view of th(x)
double Exponential::th(double x) {
    return (exp(2 * x) - 1) / (exp(2 * x) + 1);
}
/// Exponencial view of cth(x)
double Exponential::cth(double x) {
    return (exp(2 * x) +1 / (exp(2 * x) - 1));
}