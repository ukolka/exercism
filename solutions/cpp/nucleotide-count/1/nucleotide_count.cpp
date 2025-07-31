#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {
    std::map<char, int> count(const std::string& input) {
        std::map<char, int> result{};
        result['A'] = 0;
        result['C'] = 0;
        result['G'] = 0;
        result['T'] = 0;
        for (auto ch : input) {
            switch (ch) {
                case 'A':
                case 'C':
                case 'G':
                case 'T':
                    ++result[ch];
                    break;
                default:
                    throw std::invalid_argument("Expect {ACGT}");
            }
        }
        return result;
    }
}  // namespace nucleotide_count
