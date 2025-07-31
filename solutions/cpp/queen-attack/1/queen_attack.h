#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H
#include <utility>
#include <stdexcept>

namespace queen_attack {
    class chess_board {
    private:
        std::pair<int, int> white_{};
        std::pair<int, int> black_{};

        bool is_valid(std::pair<int, int> position);

    public:
        chess_board(const std::pair<int, int>& in_white, const std::pair<int, int>& in_black) : 
            white_(in_white), black_(in_black) {

            if (white_ == black_) {
                throw std::domain_error("Expect distinct positions.");
            }

            if (!is_valid(white_) || !is_valid(black_)) {
                throw std::domain_error("Expect valid positions.");
            }
        }

        std::pair<int, int> white() const;
        std::pair<int, int> black() const;
        bool can_attack() const; 
    };
}

#endif 
