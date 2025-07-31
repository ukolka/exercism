#include "anagram.h"

namespace anagram {
    anagram::anagram(const string& in_word) {
        original = in_word;
        to_lower(original);
        string norm_word(original);
        word = norm_word;
        sort(word.begin(), word.end());
    }

    void anagram::to_lower(string& s) const {
        transform(s.begin(),
            s.end(),
            s.begin(),
            [](unsigned char c) {
                return tolower(c);
            });
    }
    
    vector<string> anagram::matches(const vector<string>& candidates) const {
        vector<string> result{};
        for (auto candidate : candidates) {
            string lc_candidate(candidate);
            to_lower(lc_candidate);
            string norm_candidate(lc_candidate);
            sort(norm_candidate.begin(), norm_candidate.end());

            if (norm_candidate == word && lc_candidate != original) {
                result.emplace_back(candidate);
            }
        }
        return result;    
    }
}
