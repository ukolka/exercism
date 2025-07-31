#include "atbash_cipher.h"
#include <cctype>

namespace atbash_cipher {
    char codec(const char &c) {
        return std::isdigit(c) ?
            c : (char) ('z' - (std::tolower(c) - 'a'));
    }

    std::string encode(const std::string &initial_string) {
        std::string output;
        int char_count = 0;
        for (const auto &c : initial_string) {
            if (std::isalnum(c)) {
                if (char_count == 5) {
                    output += ' ';
                    char_count = 0;
                }
                output += codec(c);
                ++char_count;
            }
        }
        return output;
    }

    std::string decode(const std::string &initial_string) {
        std::string output;
        int char_count = 0;
        for (const auto &c : initial_string) {
            if (std::isalnum(c)) {
                output += codec(c);
                ++char_count;
            }
        }
        return output;
    }
    #undef CODEC
}  // namespace atbash_cipher
