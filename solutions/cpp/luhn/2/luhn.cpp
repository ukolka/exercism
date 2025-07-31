#include "luhn.h"
#include <vector>
#include <cmath>

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

        int sum = 0, count = 0;
        while (end != start) {
            char c = *(--end);
            if (std::isdigit(c)) {
                int digit = (c - '0') * std::pow(2, count % 2);
                if (digit > 9) {
                    digit -= 9;
                }
                sum += digit;
                ++count;
            } else if (std::isspace(c)) {
                continue;
            } else {
                return false;
            }
        }
        
        return sum % 10 == 0;
    }
}
