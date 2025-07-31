#include "doctor_data.h"

namespace heaven {
    std::string get_older_bob(Vessel bob1, Vessel bob2) {
        return bob1.generation < bob2.generation ? bob1.name : bob2.name;
    }

    bool in_the_same_system(Vessel bob1, Vessel bob2) {
        return bob1.current_system == bob2.current_system;
    }

}
