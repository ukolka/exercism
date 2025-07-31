#include "luhn.h"
#include <vector>

namespace luhn {
    bool valid(const std::string& ccnumber) {
        auto start = ccnumber.begin();
        auto end = ccnumber.end();
        while (std::isspace(*start)) {
            ++start;
        }
        while (std::isspace(*(end - 1))) {
            --end;
        }

        if (end - start < 2) {
            return false;
        }

        std::vector<int> digits;
        while (start != end) {
            char c = *start;
            ++start;
            if (std::isspace(c)) {
                continue;
            } else if (std::isdigit(c)) {
                digits.emplace_back(c - '0');
            } else {
                return false;
            }
        }
        
        int sum = 0; 
        for (int i = digits.size() - 1, count = 0; i >= 0; --i, ++count) {
            int digit = digits[i];
            if (count % 2 == 1) {
                digit *= 2;
                if (digit > 9) {
                    digit -= 9;
                }
            }
            sum += digit;
        }
        return sum % 10 == 0;
    }
}
