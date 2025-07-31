#include "diamond.h"
#include <iostream>

namespace diamond {
    vector<string> rows(const char& ch) {
        int distance = ch - 'A';
        vector<string> result(2 * distance + 1);
        for (int i = 0; i <= distance; i++) {
            string line(2 * distance + 1, ' ');
            line[distance - i] = line[distance + i] = (char)('A' + i);
            result[i] = result[distance * 2 - i] = line;
        }
        return result;
    } 
}  // namespace diamond
