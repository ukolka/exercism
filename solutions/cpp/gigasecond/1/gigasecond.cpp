#include "gigasecond.h"

namespace gigasecond {
    ptime advance(const ptime& start) {
        auto duration = seconds(1'000'000'000);
        return ptime(start + duration);
    }
}  // namespace gigasecond
