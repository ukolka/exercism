#include "darts.h"

namespace darts {
    unsigned int score(float x, float y) {
        float dist = std::sqrt(x*x + y*y);
        if (dist <= 1) {
            return 10;
        }
        if (dist <= 5) {
            return 5;
        }
        if (dist <= 10) {
            return 1;
        }
        return 0;
    }
} // namespace darts