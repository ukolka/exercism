#include <math.h>
#include "darts.h"

uint8_t score(coordinate_t pos) {
    float distance = sqrt(pow(pos.x, 2) + pow(pos.y, 2));
    if (distance <= 1) {
        return 10;
    } else if (distance <= 5) {
        return 5;
    } else if (distance <= 10) {
        return 1;
    }
    return 0;
}
