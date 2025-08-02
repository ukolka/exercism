#if !defined(ANAGRAM_H)
#define ANAGRAM_H
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

namespace anagram {
    class anagram {
    private:
        string original;
        string word;
    public:
        anagram(const string& in_word);
        void to_lower(string& s) const;
        vector<string> matches(const vector<string>& candidates) const;
    };
}  // namespace anagram

#endif // ANAGRAM_H