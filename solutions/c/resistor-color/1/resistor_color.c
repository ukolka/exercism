#include <stdlib.h>
#include "resistor_color.h"

unsigned int color_code(resistor_band_t color) {
    return (unsigned int) color;
}

const resistor_band_t* colors() {
    resistor_band_t* rv = realloc(NULL, sizeof(resistor_band_t) * 10); 
    rv[0] = BLACK;
    rv[1] = BROWN;
    rv[2] = RED;
    rv[3] = ORANGE;
    rv[4] = YELLOW;
    rv[5] = GREEN;
    rv[6] = BLUE;
    rv[7] = VIOLET;
    rv[8] = GREY;
    rv[9] = WHITE;
    return rv;
}
