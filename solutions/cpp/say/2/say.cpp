#include "say.h"
#include <unordered_map>
#include <stdexcept>
#include <iostream>

namespace say {
    std::string in_english_under100(const long long& n) {
         std::unordered_map<int, std::string> digits{
            {0, ""},
            {1, "one"},
            {2, "two"},
            {3, "three"},
            {4, "four"},
            {5, "five"},
            {6, "six"},
            {7, "seven"},
            {8, "eight"},
            {9, "nine"},
            {10, "ten"},
            {11, "eleven"},
            {12, "twelve"},
            {13, "thirteen"},
            {14, "fourteen"},
            {15, "fifteen"},
            {16, "sixteen"},
            {17, "seventeen"},
            {18, "eighteen"},
            {19, "nineteen"},
            {20, "twenty"},
            {30, "thirty"},
            {40, "forty"},
            {50, "fifty"},
            {60, "sixty"},
            {70, "seventy"},
            {80, "eighty"},
            {90, "ninety"},
        };
        
        if (n < 20) {
            return digits[n];
        }
        if (n < 100) {
            if (n % 10 == 0) {
                return digits[n];
            }
            return digits[n - n % 10] + "-" + digits[n % 10];
        }
        return "";
    }

    std::string in_english_under1000(const long long& n) {
        if (n < 100) {
            return in_english_under100(n);
        } else if (n < 1000) {
            std::string result = in_english_under100(n / 100) + " hundred";
            if (n % 100 > 0) {
                result += " ";
            }
            return result + in_english_under100(n % 100);
        }
        return "";
    }

    std::string in_english(const long long& initial_n) {
        long long n = initial_n;
        if (n < 0 || n > 999999999999) {
            throw std::domain_error("Expect positive input that's not too large.");
        }
        
        if (n == 0) {
            return "zero";
        }

        std::string result{};
        std::lldiv_t div_result;

        if (n >= 1e9 && n < 1e12) {
            div_result = std::div(n, 1e9);
            result += in_english_under1000(div_result.quot) + " billion";  
            if (div_result.rem > 0) {
                result += " " + in_english(div_result.rem);
            }
        } else if (n >= 1e6 && n < 1e9) {
            div_result = std::div(n, 1e6);
            result += in_english_under1000(div_result.quot) + " million";
            if (div_result.rem > 0) {
                result += " " + in_english(div_result.rem);
            }
        } else if (n >= 1e3 && n < 1e6) {
            div_result = std::div(n, 1e3);
            result += in_english_under1000(div_result.quot) + " thousand";
            if (div_result.rem > 0) {
                result += " " + in_english(div_result.rem);
            }
        } else {
            result += in_english_under1000(n);
        }
        
        return result;
    }
}
