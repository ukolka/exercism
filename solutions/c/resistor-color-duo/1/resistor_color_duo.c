#include <stdio.h>
#include "resistor_color_duo.h"

#define RESISTOR_COUNT 2

uint16_t color_code(resistor_band_t bands[]) {
    uint16_t result = 0;
    for (int i = 0; i < RESISTOR_COUNT; i++) {
        result *= 10;
        result += bands[i]; 
    } 
    return result;
}

#undef RESISTOR_COUNT
