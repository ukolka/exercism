#include "protein_translation.h"
#include <map>

namespace protein_translation {
    vector<string> proteins(const string& s) {
        string methionine = "Methionine";
        string phenylalanine = "Phenylalanine";
        string leucine = "Leucine";
        string serine = "Serine";
        string tyrosine = "Tyrosine";
        string cysteine = "Cysteine";
        string tryptophan = "Tryptophan";
        string stop = "STOP";

        map<string, string> codonMap = {
            {"AUG", methionine},
            {"UUU", phenylalanine},
            {"UUC", phenylalanine},
            {"UUA", leucine},
            {"UUG", leucine},
            {"UCU", serine},
            {"UCC", serine},
            {"UCA", serine},
            {"UCG", serine},
            {"UAU", tyrosine},
            {"UAC", tyrosine},
            {"UGU", cysteine},
            {"UGC", cysteine},
            {"UGG", tryptophan},
            {"UAA", stop},
            {"UAG", stop},
            {"UGA", stop}
        };
        vector<string> result{};

        for (long unsigned i = 0; i <= s.length() - 3; i += 3) {
            string codon = s.substr(i, 3);
            if (codonMap.count(codon)) {
                if (codonMap[codon] == stop)
                    break;
                result.emplace_back(codonMap[codon]);
            }
        }

        return result;
    }
}  
