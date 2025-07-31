#include "luhn.h"

namespace luhn {
    bool valid(const std::string& ccnumber) {
        int sum = 0;
        int length = 0;
        
        for (auto start = ccnumber.crbegin(); start != ccnumber.crend(); ++start) {
            char ch = *start;
            if (std::isspace(ch)) {
                continue;
            }
            if (!std::isdigit(ch)) {
                return false;
            }
            
            int digit = ch - '0';
            if (length % 2 == 1) {
                digit *= 2;
                if (digit > 9) {
                    digit -= 9;
                }
            } 

            ++length;
            sum += digit;
        }
        
        return length > 1 && sum % 10 == 0;
    }
}  // namespace luhn
