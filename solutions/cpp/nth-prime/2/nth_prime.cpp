#include "nth_prime.h"
#include <stdexcept>
#include <vector>

namespace nth_prime {

    std::size_t nth(std::size_t n) {
        if (n == 0) {
            throw std::domain_error("Invalid input");
        }
        std::vector<std::size_t> primes{2, 3};
       
        if (n < 3) {
            return primes[n - 1];
        }

        for (std::size_t candidate = 3; primes.size() < n; candidate += 2) {
            bool is_prime = true;
            for (auto prime : primes) {
                if (candidate % prime == 0) {
                    is_prime = false; 
                    break;
                }
            }

            if (is_prime) {
                primes.emplace_back(candidate);
            }
        }

        return primes[primes.size() - 1];
    }
}  // namespace nth_prime
