#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H
#include <string>
using namespace std;
namespace rna_transcription {
    char to_rna(char dna);
    string to_rna(const string& dna);
}  // namespace rna_transcription

#endif // RNA_TRANSCRIPTION_H