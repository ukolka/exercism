#include "etl.h"
#include <cctype>

namespace etl {
    map<char, int> transform(map<int, vector<char>> input) {
        map<char, int> output{};
        for (auto entry : input) {
            for (auto ch : entry.second) {
                output[tolower(ch)] = entry.first;
            }
        }
        return output;
    }
}  // namespace etl
