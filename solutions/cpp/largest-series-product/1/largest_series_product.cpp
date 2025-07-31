#include "largest_series_product.h"
#include <cctype>
#include <stdexcept>

namespace largest_series_product {
    static int product(const string& s) {
        if (s.length() == 0) {
            return 0;
        }
        int prod{1};
        for (auto ch : s) {
            if (isdigit(ch)) {
                prod *= ch - '0';
            } else {
                throw domain_error("Expect digits only.");
            }
        }
        return prod;
    }

    int largest_product(const string& s, size_t len) {
        if (len > s.length()) throw domain_error("Expect len < s.length().");

        if (len == s.length()) return product(s);
        
        int max_prod{};
        for (size_t i = 0; i < s.length() - len + 1; ++i) {
            int prod = product(s.substr(i, len));
            if (prod > max_prod) {
                max_prod = prod;
            }
        }
        return max_prod;
    }
} // largest_series_product