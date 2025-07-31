#include "hexadecimal.h"

namespace hexadecimal {
    int digit(const char &ch) {
        if (std::isalpha(ch)) {
            return ch - 'a' + 10;
        } else if (std::isdigit(ch)) {
            return ch - '0';
        }
        return -1;
    }

    int convert(const std::string &initial_string) {
        int sum = 0;
        for (auto &ch : initial_string) {
            int curr_digit = digit(ch);
            if (curr_digit > 15 || curr_digit < 0) {
                return 0;
            }
            sum = sum * 16 + curr_digit; 
        }
        return sum;
    }
} 
