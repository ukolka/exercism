#include <math.h>
#include <stdint.h>
#include "resistor_color_trio.h"

#define BAND_COUNT 2

resistor_value_t color_code(resistor_band_t bands[]) {
    float result = 0;
    for (int i = 0; i < BAND_COUNT; i++) {
        result *= 10;
        result += bands[i]; 
    } 
    result *= pow(10, bands[BAND_COUNT]);

    if (result < 1E+3) {
        return (resistor_value_t) {
            .value = result,
            .unit = OHMS
        }; 
    } else if (result < 1E+6) {
        return (resistor_value_t) {
            .value = result / 1E+3,
            .unit = KILOOHMS 
        };
    } else if (result < 1E+9) {
        return (resistor_value_t) {
            .value = result / 1E+6,
            .unit = MEGAOHMS 
        };
    } 
    return (resistor_value_t) {
        .value = result / 1E+9,
        .unit = GIGAOHMS 
    };
}

#undef BAND_COUNT
