#include "crypto_square.h"
#include <iostream>
#include <cmath>

namespace crypto_square {
    string cipher::normalize_plain_text() {
        string result{""};
        for (auto it = input_.begin(); it != input_.end(); ++it) {
            if (isalpha(*it) || isdigit(*it)) {
                result += tolower(*it);
            }
        }
        return result;
    }

    vector<string> cipher::plain_text_segments() {
        vector<string> result{};
        string normalized = normalize_plain_text();
        if (normalized.empty()) {
            return result;
        }
        float rows = floor(sqrt(normalized.size())); 
        float columns = ceil(normalized.size() / rows);

        for (int i = 0; i < rows; ++i) {
            string row{""};
            for (int j = 0; j < columns; ++j) {
                size_t idx = i * columns + j;
                if (idx < normalized.size()) {
                    row += normalized[idx];
                }
            }

            if (row.size() > 0) 
                result.push_back(row);
        }
        return result;
    }

    string cipher::cipher_text() {
        string result{""};
        vector<string> segments = plain_text_segments();
        if (segments.empty()) {
            return result;
        }

        size_t columns = segments[0].size();
        size_t rows = segments.size();
        for (size_t i = 0; i < columns; ++i) {
            for (size_t j = 0; j < rows; ++j) {
                if (i < segments[j].size())
                    result += segments[j][i];
            }
        }
        return result;
    }

    string cipher::normalized_cipher_text() {
        string result{""};
        vector<string> segments = plain_text_segments();
        if (segments.empty()) {
            return result;
        }
        size_t columns = segments[0].size();
        size_t rows = segments.size();

        for (size_t i = 0; i < columns; ++i) {
            for (size_t j = 0; j < rows; ++j) {
                if (i < segments[j].size()) 
                    result += segments[j][i];
                else 
                    result += ' ';
            }
            if (i < columns - 1)
                result += ' ';
        }
        return result;
    }
}  // namespace crypto_square
