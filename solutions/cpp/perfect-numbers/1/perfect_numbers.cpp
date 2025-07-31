#include "perfect_numbers.h"
#include <vector>
#include <numeric>
#include <cmath>
#include <stdexcept>
using namespace std;

namespace perfect_numbers {
    static vector<int> factors(int number) {
        vector<int> result{};

        for (int i = 1; i <= number / 2; ++i) {
            if (number % i == 0) {
                result.emplace_back(i);
            }
        }
        return result;
    }

    Classification classify(int number) {
        if (number <= 0) throw domain_error("Expect positive input.");
        vector<int> f = factors(number);
        int sum = accumulate(f.begin(), f.end(), 0);
        
        if (number == sum) {
            return perfect;
        } else if (number < sum) {
            return abundant;
        }
        return deficient;
    }


}  // namespace perfect_numbers
