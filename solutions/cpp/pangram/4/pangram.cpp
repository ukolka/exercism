#include "pangram.h"
#include <bitset>

namespace pangram {

    bool is_pangram(const std::string& candidate) {
        const unsigned target = 26;
        if (candidate.size() < target || candidate.size() > 1000) {
            return false;
        }
        
        std::bitset<target> candidate_set{};

        for (auto ch : candidate) {
            if (std::isalpha(ch)) {
                candidate_set.set(std::tolower(ch) - 'a');
            }
            if (candidate_set.count() == target) {
                return true;
            }
        }
        return false;            
    }
}
