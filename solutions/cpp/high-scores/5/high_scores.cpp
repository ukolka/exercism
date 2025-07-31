#include "high_scores.h"

#include <algorithm>
#include <iostream>

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
        auto begin = aux_scores.begin();
        auto end = begin + std::min((int) scores.size(), 3);
               
        if (aux_scores.end() > end) {
            std::nth_element(begin, end, aux_scores.end(), std::greater<int>());
        }
        std::sort(begin, end, std::greater<int>());

        if (aux_scores.end() > end) {
            aux_scores.resize(std::distance(begin, end));
        }
        
        return aux_scores;
    }

}  // namespace arcade
