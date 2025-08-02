#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H
#include <string>
#include <random>
#include <ctime>

namespace robot_name {
    class robot {
    private:
        static std::mt19937 generator;
        static std::uniform_int_distribution<int> dist_alpha;
        static std::uniform_int_distribution<int> dist_num;
        std::string _name;
        
    public:
        robot() {
            reset();
        }
        std::string name() const {
            return _name;
        }

        void reset() {
            _name = "";

            for (int i = 0; i < 2; ++i) {
                char randomChar = static_cast<char>(dist_alpha(generator));
                 _name += randomChar;
            }
            for (int i = 0; i < 3; ++i) {
                char randomChar = static_cast<char>(dist_num(generator)); 
                _name += randomChar;
            }
        }
    };
}  // namespace robot_name

#endif // ROBOT_NAME_H