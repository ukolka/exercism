#include "word_count.h"
#include <cstring>
#include <iostream>

namespace word_count {

    std::string clean_word(const char* word) {
        std::string result;
        const char* aux_word = word;
        
        while (*word) {
            char ch = *word;
            char next_ch = *(word + 1);
            if (
                std::isalnum(ch) || 
                (ch == '\'' && aux_word != word && next_ch != '\0')
            ) {
                result += std::tolower(ch);
            }
            ++word;
        }
        std::cout << result << std::endl; 
        return result;
    }
    

    const std::map<std::string, int> words(std::string initial_string) {
        std::map<std::string, int> result{};
        const char* delimiters = " ,.!?";
        char* initial_cstring = new char[initial_string.size() + 1];
        std::strcpy(initial_cstring, initial_string.c_str());

        char* token = std::strtok(initial_cstring, delimiters);
        while (token != nullptr) {
            std::string cleaned_word = clean_word(token);
            if (cleaned_word.size() > 0) {
                result[cleaned_word]++;
            }
            token = std::strtok(nullptr, delimiters);
        }
        return result;
    }
}  // namespace word_count
