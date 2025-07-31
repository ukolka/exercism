#include "reverse_string.h"
#include <algorithm>

namespace reverse_string {
    std::string reverse_string(std::string in_string) {
        std::reverse(in_string.begin(), in_string.end());
        return in_string;
    }
}  // namespace reverse_string
