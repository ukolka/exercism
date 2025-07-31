#include "binary_search.h"
#include <stdexcept>

namespace binary_search {
    int find(const std::vector<int>& data, int value)  {
        if (data.empty()) {
            throw std::domain_error("Expect data to not be empty.");
        }
        int left{0};
        int right{static_cast<int>(data.size()) - 1};

        while (left <= right) {
            int middle = left + (right - left) / 2;

            if (data[middle] == value) {
                return middle;
            } else if (data[middle] > value) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        throw std::domain_error("Expect value to be in data.");
    }
}  // namespace binary_search
