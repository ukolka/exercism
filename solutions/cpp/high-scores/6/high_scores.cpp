#include "high_scores.h"

#include <algorithm>

namespace arcade {

    std::vector<int> HighScores::list_scores() {
        return scores;
    }

    int HighScores::latest_score() {
        if (scores.size() > 0) {
            return scores[scores.size() - 1];
        }
        return 0;
    }

    int HighScores::personal_best() {
        auto it = std::max_element(scores.begin(), scores.end());
        if (it != scores.end()) {
            return *it;
        }
        return 0;
    }

    std::vector<int> HighScores::top_three() {
        std::vector<int> aux_scores{scores};

        if (scores.size() > 3) {
            std::nth_element(aux_scores.begin(), aux_scores.begin() + 2, aux_scores.end(), std::greater<int>());
            aux_scores.resize(3);
        }
        std::sort(aux_scores.begin(), aux_scores.end(), std::greater<int>());

        return aux_scores;
    }

}  // namespace arcade