#include "atbash_cipher.h"
#include <cctype>

namespace atbash_cipher {
    #define CODEC(c) std::isdigit(c) ? \
                    c : (char) ('z' - (std::tolower(c) - 'a'))

    std::string encode(std::string initial_string) {
        std::string output;
        int char_count = 0;
        for (char c : initial_string) {
            if (std::isalnum(c)) {
                if (char_count == 5) {
                    output += ' ';
                    char_count = 0;
                }
                output += CODEC(c);
                ++char_count;
            }
        }
        return output;
    }

    std::string decode(std::string initial_string) {
        std::string output;
        int char_count = 0;
        for (char c : initial_string) {
            if (std::isalnum(c)) {
                output += CODEC(c);
                ++char_count;
            }
        }
        return output;
    }
    #undef CODEC
}  // namespace atbash_cipher
