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
        int min_score = 0;
        int score_count = std::min((int) scores.size(), 3);

        std::vector<int> aux_scores{scores};
        auto begin = aux_scores.begin();
        auto end = begin + score_count;
               
        std::nth_element(begin, end, aux_scores.end(), std::greater<int>());
        std::sort(begin, end, std::greater<int>());

        auto it = std::find(begin, end, min_score);
        if (it != end) {
            aux_scores.resize(distance(begin, it));
        } else {
            aux_scores.resize(score_count);
        }
        
        return aux_scores;
    }

}  // namespace arcade
