#include "isbn_verifier.h"

namespace isbn_verifier {
    bool is_valid(const string& candidate) {
        int i{};
        int sum{};
        for (auto it = candidate.rbegin(); it != candidate.rend(); ++it) {
            char ch = *it;
            if (ch == '-') {
                continue;
            }

            int digit = ch - '0';
            if (ch == 'X' && i == 0) {
                digit = 10;
            }
            sum += digit * (i + 1);
            ++i;
        }
        return i == 10 && sum % 11 == 0;
    }
}  // namespace isbn_verifier