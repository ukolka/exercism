#include "pascals_triangle.h"
#include <iostream>

namespace pascals_triangle {
    vector<vector<int>> generate_rows(int n) {
        vector<vector<int>> rows{};
        for (int i = 0; i < n; ++i) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; ++j) {
                float n = static_cast<float>(i);
                float k = static_cast<float>(j);
                row[j] = ((n - k + 1) / k) * row[j - 1]; 
            }
            rows.push_back(row);
        }
        return rows;
    }
}  // namespace pascals_triangle
