#include "series.h"
#include <stdexcept>

namespace series {
    vector<string> slice(const string& s, size_t n) {
        if (n == 0) throw domain_error("Slice size cannot be zero.");
        if (s.size() < n) throw domain_error("Slice size is too big.");
        vector<string> result;
        for (size_t i = 0; i <= s.size() - n; i++) {
            result.push_back(s.substr(i, n));
        }
        return result;
    }
}  // namespace series
