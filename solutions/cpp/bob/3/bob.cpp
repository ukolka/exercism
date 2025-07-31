#include "bob.h"


namespace bob {

    std::string hey(std::string stringIn) {
        bool question = false;
        bool yelled = true;
        bool hasLetters = false;
        bool silence = true;

        for (char c : stringIn) {
            if (std::isalpha(c)) {
                hasLetters = true;
            }

            if (std::islower(c)) {
                yelled = false;
            }

            if (!std::isspace(c)) {
                silence = false;
                question = false;
            }

            if (c == '?') {
                question = true;
            }
        }


        if (question && yelled && hasLetters) {
            return "Calm down, I know what I'm doing!";
        } else if (silence) {
            return "Fine. Be that way!";
        } else if (question) {
            return "Sure.";
        } else if (yelled && hasLetters) {
            return "Whoa, chill out!";
        }
        return "Whatever."; 
    }

}  // namespace bob
