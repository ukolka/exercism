#include "pangram.h"
#include <set>
#include <cctype>
#include <algorithm>

namespace pangram {
    std::set<char> alphabet_set() {
        std::set<char> result{};
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            result.insert(ch);
        }
        return result;
    }

    std::set<char> make_set(const std::string& phrase) {
        std::set<char> result{};
        for (auto ch : phrase) {
            result.insert(std::tolower(ch));
        }
        return result;
    }

    bool is_pangram(const std::string& candidate) {
        std::set<char> alphabet{alphabet_set()};
        std::set<char> candidate_set{make_set(candidate)};

        bool isSubset = std::includes(candidate_set.begin(),
            candidate_set.end(),
            alphabet.begin(),
            alphabet.end()
        );
        return isSubset;
            
    }
}  // namespace pangram
