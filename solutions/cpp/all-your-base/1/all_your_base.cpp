#include "all_your_base.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>

namespace all_your_base {
    vector<unsigned int> convert(unsigned int input_base, const vector<unsigned int>& input_digits, unsigned int output_base) {
        if (input_base < 2) throw invalid_argument("Input base must be >= 2");
        if (output_base < 2) throw invalid_argument("Output base must be >= 2");
        vector<unsigned int> output_digits;
        unsigned int decimal = 0;
        unsigned int power = 0;
        for (auto it = input_digits.rbegin(); it != input_digits.rend(); ++it) {
            if (*it >= input_base) throw invalid_argument("All digits must be strictly less than the input base");
            decimal += *it * pow(input_base, power);
            ++power;
        }
        while (decimal > 0) {
            output_digits.push_back(decimal % output_base);
            decimal /= output_base;
        }
        reverse(output_digits.begin(), output_digits.end());
        return output_digits;
    }
}  // namespace all_your_base
