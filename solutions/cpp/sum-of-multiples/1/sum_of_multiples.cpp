#include "sum_of_multiples.h"

namespace sum_of_multiples {
    int to(vector<int> items, int lim) {
        int sum = 0;
        for (int i = 1; i < lim; ++i) {
            for (auto val : items) {
                if (i % val == 0) {
                    sum += i;
                    break;
                }
            }
        }
        return sum;
    }
}  // namespace sum_of_multiples
