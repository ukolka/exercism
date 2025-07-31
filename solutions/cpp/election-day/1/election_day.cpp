#include <string>
#include <vector>

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
    int max_votes{};
    std::vector<ElectionResult>::iterator winner = results.begin();
    for (auto it = results.begin(); it != results.end(); ++it) {
        if (it->votes >= max_votes) {
            max_votes = it->votes;
            winner = it;
        }
    }
    ElectionResult& result{*winner};
    result.name = "President " + result.name;
    return result;
}

}  // namespace election