#include "grains.h"
#include <cmath>

namespace grains {
    unsigned long long square(int n) {
        return pow(2, n - 1);
    }

    unsigned long long total() {
        return square(65) - 1;
    }
}  // namespace grains
