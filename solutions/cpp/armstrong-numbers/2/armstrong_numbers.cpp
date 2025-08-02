#include "armstrong_numbers.h"
#include <vector>
#include <cmath>
#include <iostream>

namespace armstrong_numbers {
    bool is_armstrong_number(int n) {
        int nCopy{n};
        int sum{};
        int count = std::log10(n) + 1;
        
        while (n > 0) {
            div_t div_r = std::div(n, 10);
            sum += std::pow(div_r.rem, count);
            n = div_r.quot;
        }

        return sum == nCopy;
    }
}  // namespace armstrong_numbers
