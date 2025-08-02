#include "high_scores.h"

#include <algorithm>

namespace arcade {

    std::vector<int> HighScores::list_scores() {
        return scores;
    }

    int HighScores::latest_score() {
        return scores[scores.size() - 1];
    }

    int HighScores::personal_best() {
        return top_three()[0];
    }

    std::vector<int> HighScores::top_three() {
        std::vector<int> aux_scores{scores};
        std::sort(aux_scores.begin(), aux_scores.end(), std::greater<int>());
        int min_score = 0;
        int score_count = 3;
        auto start = aux_scores.begin();
        auto end = start + score_count;
        auto it = std::find(start, end, min_score);
        if (it != end) {
            aux_scores.resize(distance(start, it));
        } else {
            aux_scores.resize(score_count);
        }
        
        return aux_scores;
    }

}  // namespace arcade
