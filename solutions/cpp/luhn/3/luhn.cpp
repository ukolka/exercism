#include "luhn.h"
#include <vector>

namespace luhn {
    bool valid(const std::string& ccnumber) {
        int sum = 0;
        bool is_even = false;
        int length = 0;
        
        for (auto start = ccnumber.crbegin(); start != ccnumber.crend(); ++start) {
            char ch = *start;
            if (std::isdigit(ch)) {
                int digit = ch - '0';
                if (is_even) {
                    digit *= 2;
                    if (digit > 9) {
                        digit -= 9;
                    }
                } 

                is_even = !is_even;
                ++length;
                sum += digit;
            } else if (std::isspace(ch)) {
                continue;
            } else {
                return false;
            }
        }
        
        return length > 1 && sum % 10 == 0;
    }
}  // namespace luhn
