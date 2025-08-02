#include "binary.h"

namespace binary {
    int convert(const string& input) {
        int result = 0;
        for (auto it = input.begin(); it != input.end(); ++it) {
            result *= 2;
            int digit = (*it - '0');
            if (digit > 1 || digit < 0) {
                return 0;
            }
            result += digit;
        }
        return result;
    }
}  // namespace binary
