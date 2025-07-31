#include "prime_factors.h"
#include <cstdlib>
#include <cmath>

namespace prime_factors {
    std::vector<int> of(int n) {
        std::vector<int> factors{};

        div_t result = std::div(n, 2);
        while (result.rem == 0) {
            factors.emplace_back(2);
            n = result.quot;
            result = std::div(n, 2);
        }

        for (int i{3}; i < std::sqrt(n) + 1; i += 2) {
            result = std::div(n, i);
            while (result.rem == 0) {
                factors.emplace_back(i);
                n = result.quot;
                result = std::div(n, i);
            }
        }

        if (n > 2) {
            factors.emplace_back(n);
        }
        
        return factors;
    }
}  // namespace prime_factors
