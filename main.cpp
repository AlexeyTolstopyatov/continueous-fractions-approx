#include "exps/Chained.hpp"
#include <iostream>

int main() {
    auto *cInstance = new Chained(1000);
    double x = -3, dx = 0.1;
    while (x < 3) {
        std::cout << x << '\t' << cInstance->sh2(x) << std::endl;
        x += dx;
    }

    delete cInstance;
    return 0;
}

