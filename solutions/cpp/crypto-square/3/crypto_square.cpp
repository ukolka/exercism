#include "crypto_square.h"
#include <iostream>
#include <cmath>
namespace crypto_square {
    std::string cipher::normalize_plain_text() const {
        std::string result{""};
        for (auto & ch : input) {
            if (isalpha(ch) || isdigit(ch)) {
                result += tolower(ch);
            }
        }
        return result;
    }
    std::vector<std::string> cipher::plain_text_segments() const {
        std::vector<std::string> result{};
        std::string normalized = normalize_plain_text();
        if (normalized.empty()) {
            return result;
        }
        float rows = floor(sqrt(normalized.size())); 
        float columns = ceil(normalized.size() / rows);
        for (int i = 0; i < rows; ++i) {
            std::string row = normalized.substr(i * columns, columns);
            if (row.size() > 0) 
                result.push_back(row);
        }
        return result;
    }
    std::string cipher::cipher_text() const {
        std::string result{""};
        std::vector<std::string> segments = plain_text_segments();
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
    std::string cipher::normalized_cipher_text() const {
        std::string result{""};
        std::vector<std::string> segments = plain_text_segments();
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