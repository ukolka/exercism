#include "allergies.h"

namespace allergies {

    const std::unordered_map<int, std::string> allergy_test::allergy_map = {
            {1, "eggs"},
            {2, "peanuts"},
            {4, "shellfish"},
            {8, "strawberries"},
            {16, "tomatoes"},
            {32, "chocolate"},
            {64, "pollen"},
            {128, "cats"}
        };

    allergy_test::allergy_test(int initial_score) : score(initial_score) {
            for (const auto& pair : allergy_map) {
                if (pair.first & initial_score) {
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
