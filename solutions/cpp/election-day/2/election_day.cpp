#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace election {

struct ElectionResult {
    std::string name{};
    int votes{};
};

int vote_count(const ElectionResult& er) {
    return er.votes;
}

void increment_vote_count(ElectionResult& er, const int& num_votes) {
    er.votes += num_votes;
}

ElectionResult& determine_result(std::vector<ElectionResult>& results) {
    auto winner = std::max_element(results.begin(), results.end(),
        [](const ElectionResult& a, const ElectionResult& b) {
            return a.votes < b.votes;
        });

    if (winner == results.end()) {
        throw std::domain_error("No winner in empty results.");
    }

    ElectionResult& result{*winner};
    result.name = "President " + result.name;
    return result;
}

}  // namespace election