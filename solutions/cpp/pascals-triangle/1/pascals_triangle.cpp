#include "pascals_triangle.h"

namespace pascals_triangle {
    vector<vector<int>> generate_rows(int n) {
        vector<vector<int>> rows{};
        rows.reserve(n);
        if (n == 0) {
            return rows;
        }
        if (n >= 1) {
            rows.push_back({1});
        }

        for (int i = 1; i < n; ++i) {
            vector<int> row{};
            row.reserve(i + 2);
            row.emplace_back(0);
            for (auto it = rows[i - 1].begin(); it != rows[i - 1].end(); ++it) {
                row.emplace_back(*it);
            }
            row.emplace_back(0);

            for (int j = 0; j < i; ++j) {
                row[j] = row[j] + row[j + 1];
            }
            row.pop_back();
            rows.emplace_back(row);
        }
        return rows;
    }
}  // namespace pascals_triangle
