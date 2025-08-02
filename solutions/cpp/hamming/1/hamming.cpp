#include "hamming.h"
#include <stdexcept>

namespace hamming {
    int compute(const string& a, const string& b) {
        if (a.length() != b.length()) {
            throw domain_error("Expect equal length.");
        }
        int result{};
        for (auto ita = a.begin(), itb = b.begin(); ita != a.end(); ++ita, ++itb) {
            if (*ita != *itb) {
                ++result;
            }
        }
        return result;
    }
}      // namespace hamming
