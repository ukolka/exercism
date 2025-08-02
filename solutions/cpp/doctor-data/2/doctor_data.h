#pragma once
#include <string>

namespace star_map {
    enum class System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        Omicron2Eridani,
        DeltaEridani,
        AlphaCentauri
    };
}

namespace heaven {
    class Vessel {
        public:
            std::string name;
            int generation{};
            star_map::System current_system;
            int busters{};

            Vessel(
                std::string name, 
                int generation,
                star_map::System system = star_map::System::Sol
            ) : name(name), generation(generation), current_system(system) {}

            Vessel replicate(std::string name) {
                return Vessel(name, generation + 1);
            }

            void make_buster() {
                ++busters;
            }

            bool shoot_buster() {
                if (busters > 0) {
                    --busters;
                    return true;
                }
                return false;
            }

    };

    std::string get_older_bob(Vessel bob1, Vessel bob2);

    bool in_the_same_system(Vessel bob1, Vessel bob2);
}

