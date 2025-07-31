#include "food_chain.h"
#include <vector>

namespace food_chain {
    string verse(int n) {
        string old_lady = "I know an old lady who swallowed a ";

        vector<string> verse_heads = {
            "fly.\n",
            "spider.\n"
            "It wriggled and jiggled and tickled inside her.\n",
            "bird.\n"
            "How absurd to swallow a bird!\n",
            "cat.\n"
            "Imagine that, to swallow a cat!\n",
            "dog.\n"
            "What a hog, to swallow a dog!\n",
            "goat.\n"
            "Just opened her throat and swallowed a goat!\n",
            "cow.\n"
            "I don't know how she swallowed a cow!\n",
            "horse.\n"
            "She's dead, of course!\n"
        };

        vector<string> verse_tails = {
            "I don't know why she swallowed the fly. Perhaps she'll die.\n",
            "She swallowed the spider to catch the fly.\n",
            "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n",
            "She swallowed the cat to catch the bird.\n",
            "She swallowed the dog to catch the cat.\n",
            "She swallowed the goat to catch the dog.\n",
            "She swallowed the cow to catch the goat.\n",
        };

        int idx = n - 1;
        if (n >= 1 && n < 8) {
            string tail = "";
            for (int i = idx; i >= 0; --i) {
                tail += verse_tails[i];
            }
            return old_lady + verse_heads[idx] + tail; 
        } else if (n == 8) {
            return old_lady + verse_heads[idx];
        }
        return "";
    }

    string verses(int start, int end) {
        string result = "";
        for (int i = start; i <= end; ++i) {
            result += verse(i) + "\n";            
        }
        return result;
    }

    string sing() {
        return verses(1, 8);
    }
} 
