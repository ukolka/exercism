#if !defined(ALLERGIES_H)
#define ALLERGIES_H
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

namespace allergies {
    class allergy_test {
    private:
        int score;
        std::unordered_set<std::string> allergy_set;
        static const std::unordered_map<int, std::string> allergy_map;
    public:
        allergy_test(int initial_score);
        bool is_allergic_to(const std::string& substance) const;
        std::unordered_set<std::string> get_allergies();
    };
}  // namespace allergies

#endif // ALLERGIES_H
