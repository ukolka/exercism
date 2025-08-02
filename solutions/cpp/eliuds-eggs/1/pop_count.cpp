#include "pop_count.h"

namespace chicken_coop {

    int positions_to_quantity(int positions) {
        int quantity = 0;
        while (positions > 0) {
            quantity += positions & 1;
            positions >>= 1;
        }
        return quantity;
    }

}  // namespace chicken_coop
