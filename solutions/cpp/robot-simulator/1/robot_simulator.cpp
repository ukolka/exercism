#include "robot_simulator.h"

namespace robot_simulator {
    Robot::Robot () {
        position = std::make_pair(0, 0);
        bearing = Bearing::NORTH;
    }
    Robot::Robot(std::pair<int, int> position, Bearing bearing)
        : position{position}, bearing{bearing} {}

    std::pair<int, int> Robot::get_position() const {
        return position;
    }

    Bearing Robot::get_bearing() const {
        return bearing;
    }

    void Robot::turn_left() {
        bearing = static_cast<Bearing>((static_cast<int>(bearing) + 4 - 1) % 4);
    }

    void Robot::turn_right() {
        bearing = static_cast<Bearing>((static_cast<int>(bearing) + 1) % 4);
    }

    void Robot::advance() {
        switch (bearing)
        {
        case Bearing::NORTH:
            position.second++;
            break;
        case Bearing::EAST:
            position.first++;
            break; 
        case Bearing::SOUTH:
            position.second--;
            break;
        case Bearing::WEST:
            position.first--;
            break;
        default:
            break;
        }
    }

    void Robot::execute_sequence(const std::string& sequence) {
        for (auto c : sequence) {
            switch (c)
            {
            case 'L':
                turn_left();
                break;
            case 'R':
                turn_right();
                break;
            case 'A':
                advance();
                break;
            default:
                break;
            }
        }
    }
}  // namespace robot_simulator
