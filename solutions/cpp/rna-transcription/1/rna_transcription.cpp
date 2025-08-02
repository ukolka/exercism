#include "rna_transcription.h"

namespace rna_transcription {
    char to_rna(char dna) {
        switch (dna) {
            case ('G'):
                return 'C';
            case ('C'):
                return 'G';
            case ('T'):
                return 'A';
            case ('A'):
                return 'U';
        }
        return '\0';
    }

    string to_rna(const string& dna) {
        string result{};
        for (auto ch : dna) {
            result += to_rna(ch);
        }
        return result;
    }
}  // namespace rna_transcription
