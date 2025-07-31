#include "pangram.h"
#include <set>
#include <cctype>
#include <algorithm>

namespace pangram {

    bool is_pangram(const std::string& candidate) {
        unsigned int target = 26;
        if (candidate.size() < target) {
            return false;
        }
        std::set<char> candidate_set{};

        for (auto ch : candidate) {
            if (std::isalpha(ch)) {
                candidate_set.insert(std::tolower(ch));
            }
            if (candidate_set.size() == target) {
                return true;
            }
        }
        return false;            
    }
}  // namespace pangram
