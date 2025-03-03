#include "exps/Chained.hpp"
#include <iostream>

int main() {
    auto *cInstance = new Chained(10);
    double x = -3, dx = 1;
    while (x < 3) {
        std::cout << x << '\t' << cInstance->sin(x) << std::endl;
        x += dx;
    }

    delete cInstance;
    return 0;
}

