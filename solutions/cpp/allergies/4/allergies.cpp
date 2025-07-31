#include "allergies.h"

namespace allergies {

    const std::unordered_map<std::string, int> allergy_test::allergy_map = {
            {"eggs", 1},
            {"peanuts", 2},
            {"shellfish", 4},
            {"strawberries", 8},
            {"tomatoes", 16},
            {"chocolate", 32},
            {"pollen", 64},
            {"cats", 128}
        };

    allergy_test::allergy_test(int initial_score) : score(initial_score) {}

    bool allergy_test::is_allergic_to(const std::string& substance) const {
        auto it = allergy_map.find(substance);
        return it != allergy_map.end() && score & it->second; 
    }

    std::unordered_set<std::string> allergy_test::get_allergies() {
        std::unordered_set<std::string> result;
        
        for (const auto& pair : allergy_map) {
            result.emplace(pair.first);
        }

        return result;
    }
}  // namespace allergies
