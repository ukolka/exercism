#if !defined(ANAGRAM_H)
#define ANAGRAM_H
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

namespace anagram {
    class anagram {
    private:
        string word;
        map<char, int> hist;
    public:
        anagram(const string& in_word);

        string to_lower(const string& s) const;

        map<char, int> make_hist(const string& word) const;

        vector<string> matches(const vector<string>& candidates) const;
    };
}  // namespace anagram

#endif // ANAGRAM_H