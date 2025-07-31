#include "pascals_triangle.h"

namespace pascals_triangle {
    vector<vector<int>> generate_rows(int n) {
        vector<vector<int>> rows{};
        for (int i = 0; i < n; ++i) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; ++j) {
                row[j] = rows[i - 1][j - 1] + rows[i - 1][j];
            }
        }
        return rows;
    }
}  // namespace pascals_triangle
