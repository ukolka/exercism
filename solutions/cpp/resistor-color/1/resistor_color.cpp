#include "resistor_color.h"
#include <algorithm>

namespace resistor_color {
    vector<string> colors() {
        return {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    }

    unsigned color_code(const string& in) {
        vector<string> c = colors();
        return distance(c.begin(), find(c.begin(), c.end(), in));
    }
}  // namespace resistor_color
