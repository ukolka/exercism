#include "allergies.h"

namespace allergies {
    allergy_test::allergy_test(int initial_score) : score(initial_score) {
            for (const auto& pair : allergy_map) {
                if ((pair.first & initial_score) != 0) {
                    allergy_set.emplace(pair.second); 
                }
            }
        }

    bool allergy_test::is_allergic_to(const std::string& substance) const {
        return allergy_set.find(substance) != allergy_set.end();
    }

    std::unordered_set<std::string> allergy_test::get_allergies() {
        return allergy_set;
    }
}  // namespace allergies
