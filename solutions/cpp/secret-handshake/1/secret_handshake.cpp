#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake {
    vector<string> commands(int n) {
        vector<string> result{};

        if (0b00001 & n) {
            result.emplace_back("wink");
        }
        if (0b00010 & n) {
            result.emplace_back("double blink");
        }
        if (0b00100 & n) {
            result.emplace_back("close your eyes");
        }
        if (0b01000 & n) {
            result.emplace_back("jump");
        }
        if (0b10000 & n) {
            reverse(result.begin(), result.end());
        }
        return result;
    }
}  // namespace secret_handshake
