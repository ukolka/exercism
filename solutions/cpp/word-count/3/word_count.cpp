#include "word_count.h"
#include <regex>
#include <algorithm>

namespace word_count {

    const std::map<std::string, int> words(std::string initial_string) {
        std::map<std::string, int> result{};

        std::regex pattern(R"(\b[\w\d']+\b)");
        std::sregex_iterator it(
            initial_string.begin(), initial_string.end(), pattern);

        for (std::sregex_iterator end; it != end; ++it) {
            std::string word(it->str());
            std::transform(
                word.begin(),  word.end(), word.begin(),
                [](unsigned char ch) { return std::tolower(ch);});
            ++result[word];
        }

        return result;
    }
}
