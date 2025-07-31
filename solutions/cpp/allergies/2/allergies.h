#if !defined(ALLERGIES_H)
#define ALLERGIES_H
#include <string>
#include <unordered_set>
#include <unordered_map>

namespace allergies {
    class allergy_test {
    private:
        int score;
        std::unordered_set<std::string> allergy_set;
        const std::unordered_map<int, std::string> allergy_map = {
            {1, "eggs"},
            {2, "peanuts"},
            {4, "shellfish"},
            {8, "strawberries"},
            {16, "tomatoes"},
            {32, "chocolate"},
            {64, "pollen"},
            {128, "cats"}
        };
    public:
        allergy_test(int initial_score);
        bool is_allergic_to(const std::string& substance) const;
        std::unordered_set<std::string> get_allergies();
    };
}  // namespace allergies

#endif // ALLERGIES_H