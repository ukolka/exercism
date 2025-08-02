#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H
#include <vector>
#include <string>
#include <map>
using namespace std;

namespace protein_translation {
    extern map<string, string> codonMap;
    vector<string> proteins(const string& s); 
}  // namespace protein_translation

#endif // PROTEIN_TRANSLATION_H
