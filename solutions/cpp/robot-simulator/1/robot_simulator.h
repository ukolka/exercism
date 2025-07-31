#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H
#include <string> 

namespace robot_simulator {
    enum Bearing {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    class Robot {
    private:
        std::pair<int, int> position;
        Bearing bearing;
    public:
        Robot();
        Robot(std::pair<int, int> position, Bearing bearing);
        std::pair<int, int> get_position() const;
        Bearing get_bearing() const;
        void turn_right();
        void turn_left();
        void advance();
        void execute_sequence(const std::string& sequence);
    };
}  // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H