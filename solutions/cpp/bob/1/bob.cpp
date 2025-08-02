#include "bob.h"


namespace bob {
    bool isYelled(std::string stringIn) {
        bool result = true;
        bool hasLetters = false;
        int len = stringIn.length();

        for (int i = 0; i < len; i++) {
            if (std::isalpha(stringIn[i])) {
                hasLetters = true;
                if (std::islower(stringIn[i])) {
                    result = false; break;
                }
            }
        }

        return result && hasLetters;
    }

    bool isQuestion(std::string stringIn) {
        bool result = false; 
        int len = stringIn.length();

        for (int i = len - 1; i >= 0; i--) {
            if (stringIn[i] == '?') {
                result = true;
                break;
            } else if (std::isalnum(stringIn[i])) {
                break;
            }
        }

        return result;
    }

    bool isSilence(std::string stringIn) {
        bool result = true;
        int len = stringIn.length();

        for (int i = 0; i < len; i++) {
            result = result && std::isspace(stringIn[i]);
        }

        return result;
    }

    std::string hey(std::string stringIn) {
        bool question = isQuestion(stringIn);
        bool yelled = isYelled(stringIn);
        bool silence = isSilence(stringIn);


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
