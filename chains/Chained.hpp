//
// Created by MagicBook on 03.03.2025.
//

#ifndef CHVIEW_CHAINED_HPP
#define CHVIEW_CHAINED_HPP

#include <cmath>
#include <vector>
#include <stdexcept>

class Chained {
private:
    std::vector<double> pB;
    std::vector<double> pC;
    // depth of chained fraction
    unsigned int _defaultTimes = 10;
    // declare API details
    double th05x(const double *x);
    double th05xs(const double *x);
    double _epsilon;
public:
    /// Make instance of Chained fraction methods storage
    /// \param defaultTimes depth of chained-fractions
    explicit Chained(unsigned int defaultTimes) {
        _defaultTimes = defaultTimes;
        _epsilon = 1e-10;
        pB.resize(_defaultTimes);
        pC.resize(_defaultTimes);
    }
    /// Make instance of Chained fraction methors storage
    /// default depth of chained-fraction=10
    Chained() : Chained(10) {
        // move logic to daddy constructor
    }

    /// Kill instance and temporary memory values
    ~Chained() = default;
    void sete(double e);
    double sh(double x);
    double sh2(double x);
    double ch2(double x);
    double ch(double x);
    double th(double x);
    double cth(double x);
    double sin(double x);
    double lsin(double x);
};

#endif //CHVIEW_CHAINED_HPP
