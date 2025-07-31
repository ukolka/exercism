#include "scrabble_score.h"
#include <unordered_set>
#include <array>

namespace scrabble_score {
    int score(const string& word) {
        unordered_set<char> one_point = {
            'A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T'};
        unordered_set<char> two_point = {'D', 'G'};
        unordered_set<char> three_point = {'B', 'C', 'M', 'P'};
        unordered_set<char> four_point = {'F', 'H', 'V', 'W', 'Y'};
        unordered_set<char> five_point = {'K'};
        unordered_set<char> eight_point = {'J', 'X'};
        unordered_set<char> ten_point = {'Q', 'Z'};        

        array<unordered_set<char>, 7> point_sets = {
            one_point, two_point, three_point,
            four_point, five_point, eight_point, ten_point};

        int score{};
        for (auto ch : word) {
            for (int j = 0; j < 7; ++j) {
                if (point_sets[j].find(toupper(ch)) != point_sets[j].end()) {
                    if (j == 5)
                        score += 8;
                    else if (j == 6)
                        score += 10;
                    else
                        score += j + 1;
                }
            }
        }
        return score;
    }
}  
