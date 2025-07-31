#include "acronym.h"

namespace acronym {
    string acronym(const string& input) {
        char prev_char = ' ';
        string result = "";
        for (auto ch : input) {
            if (isalpha(ch) && !isalpha(prev_char) && prev_char != '\'') {
                result += toupper(ch);
            }
            prev_char = ch;
        }
        return result;
    }
} 
