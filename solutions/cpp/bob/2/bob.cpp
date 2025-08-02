#include "bob.h"


namespace bob {

    std::string hey(std::string stringIn) {
        bool question = false;
        bool yelled = true;
        bool silence = true;

        for (char c : stringIn) {
            if (std::islower(c)) {
                yelled = false;
            }

            if (c == '?') {
                question = true;
            }

            if (std::isspace(c)) {
                question = false;
            } else {
                silence = false;
            }
        }


        if (question && yelled) {
            return "Calm down, I know what I'm doing!";
        } else if (silence) {
            return "Fine. Be that way!";
        } else if (question) {
            return "Sure.";
        } else if (yelled) {
            return "Whoa, chill out!";
        }
        return "Whatever."; 
    }

}  // namespace bob
