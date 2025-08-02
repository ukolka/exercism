#include "protein_translation.h"

namespace protein_translation {
    vector<string> proteins(const string& s) {
        vector<string> result{};
        for (long unsigned i = 0; i <= s.length() - 3; i += 3) {
            switch (s[i]) {
                case ('A'):
                    if (s[i + 1] == 'U' && s[i + 2] == 'G')
                        result.emplace_back("Methionine");
                    break;
                case ('U'):
                    switch (s[i + 1]) {
                        case ('U'):
                            switch (s[i + 2]) {
                                case ('U'):
                                case ('C'):
                                    result.emplace_back("Phenylalanine");
                                    break;
                                case ('A'):
                                case ('G'):
                                    result.emplace_back("Leucine");
                                    break;
                            }
                            break;
                        case ('C'):
                            switch (s[i + 2]) {
                                case ('U'):
                                case ('C'):
                                case ('A'):
                                case ('G'):
                                    result.emplace_back("Serine");
                                    break;
                            }
                            break;
                        case ('A'):
                            switch (s[i + 2]) {
                                case ('U'):
                                case ('C'):
                                    result.emplace_back("Tyrosine");
                                    break;  
                                case ('A'):
                                case ('G'):
                                    return result;
                            }
                            break;
                        case ('G'):
                            switch (s[i + 2]) {
                                case ('U'):
                                case ('C'):
                                    result.emplace_back("Cysteine");
                                    break;
                                case ('G'):
                                    result.emplace_back("Tryptophan");
                                    break;
                                case ('A'):
                                    return result;
                            }
                            break;
                    }
                    break;
            }
        }

        return result;
    }
}  // namespace protein_translation
