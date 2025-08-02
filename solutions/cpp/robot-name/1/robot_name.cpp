#include "robot_name.h"

namespace robot_name {
    std::mt19937 robot::generator(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution<int> robot::dist_alpha('A', 'Z');
    std::uniform_int_distribution<int> robot::dist_num('0', '9');
}  // namespace robot_name
