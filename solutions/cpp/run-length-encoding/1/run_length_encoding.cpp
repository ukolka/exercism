#include "run_length_encoding.h"

namespace run_length_encoding {
    string encode(const string& input) {
        if (input.length() == 0) {
            return "";
        }
        char prev{input[0]};
        unsigned count{0};
        string result;
        for (auto ch : input + '\0') {
            if (ch == prev) {
                count++;
            }
            
            if (ch != prev) {
                if (count == 1) {
                    result += prev != '\0' ? prev : ch;
                } else {
                    result += to_string(count) + prev;
                }
                count = 1;
            }
            prev = ch;
        }
        
        return result;
    } 
    string decode(const string& input) {
        string result;
        unsigned number{0};
        for (auto ch : input) {
            if (isdigit(ch)) {
                number *= 10;
                number += ch - '0';
            } else {
                for (unsigned i = 0; i < (number > 0 ? number : 1); i++) {
                    result += ch;
                }
                number = 0;
            }
        }
        return result;
    }
}  // namespace run_length_encoding
