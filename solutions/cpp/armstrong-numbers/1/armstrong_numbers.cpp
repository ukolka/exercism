#include "armstrong_numbers.h"
#include <vector>
#include <cmath>
#include <iostream>

namespace armstrong_numbers {
    bool is_armstrong_number(int n) {
        int nCopy = n;
        if (n < 10) {
            return true;
        }

        int count = 0;
        std::vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            count++;
            n /= 10;
        }

        int sum = 0;
        for (int digit : digits) {
            sum += std::pow(digit, count);
        }

        return sum == nCopy;
    }
}  // namespace armstrong_numbers
