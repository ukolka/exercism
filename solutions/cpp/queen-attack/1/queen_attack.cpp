#include "queen_attack.h"

namespace queen_attack {
    bool chess_board::is_valid(std::pair<int, int> position) {
        return !(position.first < 0 || position.first > 7 ||
            position.second < 0 || position.second > 7);
    }

    std::pair<int, int> chess_board::white() const {
        return white_;
    }

    std::pair<int, int> chess_board::black() const {
        return black_;
    }

    bool chess_board::can_attack() const {
        return white_.first - white_.second == 
            black_.first - black_.second ||

            white_.first + white_.second ==
            black_.first + black_.second ||

            white_.first == black_.first ||

            white_.second == black_.second;
    }
}
