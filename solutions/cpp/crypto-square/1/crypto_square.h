#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H
#include <vector>
#include <string>
using namespace std;

namespace crypto_square {
    class cipher {
    private:
        string input_;
    public:
        cipher(const string& input) : input_(input) {}
        string normalize_plain_text(); 
        vector<string> plain_text_segments(); 
        string cipher_text();
        string normalized_cipher_text();
    };
}  // namespace crypto_square

#endif // CRYPTO_SQUARE_H