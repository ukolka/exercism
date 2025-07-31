#include <string>

namespace log_line {
    const std::string message(const std::string log_string) {
        size_t colonPos = log_string.find(": ");

        if (colonPos != std::string::npos) {
           return log_string.substr(colonPos + 2); 
        }
        return NULL;
    }

    const std::string log_level(const std::string log_string) {
        size_t closingBracketPos = log_string.find("]");

        if (closingBracketPos != std::string::npos) {
            return log_string.substr(1, closingBracketPos - 1);
        }
        return NULL;
    }

    const std::string reformat(const std::string log_string) {
        return log_line::message(log_string) + 
            " (" + log_line::log_level(log_string) + ")";
    }
} // namespace log_line
