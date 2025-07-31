#include "sieve.h"

namespace sieve {
    std::vector<int> primes(const unsigned int& n) {
        std::vector<int> result{};

        for (unsigned int i = 2; i <= n; i++) {
            bool is_prime = true;
            for (const auto& elem : result) {
                if (i % elem == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) {
                result.emplace_back(i);
            }
        }
        
        return result;
    }
}  // namespace sieve
