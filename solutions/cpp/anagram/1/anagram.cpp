#include "anagram.h"

namespace anagram {
    anagram::anagram(const string& in_word) {
        hist = anagram::make_hist(in_word);
        word = anagram::to_lower(in_word);
    }

    string anagram::to_lower(const string& s) const {
        string result = s;
        transform(result.begin(),
            result.end(),
            result.begin(),
            [](unsigned char c) {
                return tolower(c);
            });
        return result;
    }

    map<char, int> anagram::make_hist(const string& word) const {
        map<char, int> result{};
        for (auto ch : word) {
            ++result[tolower(ch)];
        }
        return result;
    }
    
    vector<string> anagram::matches(const vector<string>& candidates) const {
        vector<string> result{};
        for (auto candidate : candidates) {
            string lc_candidate = anagram::to_lower(candidate);
            map<char, int> h = anagram::make_hist(candidate);
            if (h == hist && lc_candidate != word) {
                result.emplace_back(candidate);
            }
        }
        return result;    
    }
}  // namespace anagram
