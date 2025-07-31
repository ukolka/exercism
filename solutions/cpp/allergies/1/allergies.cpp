#include "allergies.h"
#include <cstdlib>

namespace allergies {
    allergy_test::allergy_test(int initial_score) : score(initial_score) {
            int len = allergies.size();
            for (int i = 0; i < len; i++) {
                std::div_t result = std::div(initial_score, 2);
                initial_score = result.quot;
                if (result.rem) { allergic_to.insert(allergies[i]); }
            }
        }

    bool allergy_test::is_allergic_to(const std::string& allergy) const {
        return allergic_to.find(allergy) != allergic_to.end();
    }

    std::unordered_set<std::string> allergy_test::get_allergies() {
        return allergic_to;
    }
}  // namespace allergies
