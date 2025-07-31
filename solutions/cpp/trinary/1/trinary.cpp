#include "trinary.h"
#include <cmath>

namespace trinary {
    int to_decimal(const std::string& input_string) {
        int exp = input_string.length(), out = 0;

        for (auto &c : input_string) {
            if (!std::isdigit(c)) {
                return 0;
            }
            out += (c - '0') * std::pow(3, --exp);
        }
        return out;
    }
}
