#include "protein_translation.h"

namespace protein_translation {
    map<string, string> codonMap = {
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"},
        {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"},
        {"UUG", "Leucine"},
        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Serine"},
        {"UCG", "Serine"},
        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"UAA", "STOP"},
        {"UAG", "STOP"},
        {"UGA", "STOP"}
    };

    vector<string> proteins(const string& s) {

        vector<string> result{};

        for (long unsigned i = 0; i <= s.length() - 3; i += 3) {
            string codon = s.substr(i, 3);
            if (codonMap.count(codon)) {
                if (codonMap[codon] == "STOP")
                    break;
                result.emplace_back(codonMap[codon]);
            }
        }

        return result;
    }
}  
