#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H
#include <vector>
#include <string>

namespace crypto_square {
    class cipher {
    private:
        std::string input;
    public:
        cipher(const std::string& input) : input(input) {}
        std::string normalize_plain_text() const; 
        std::vector<std::string> plain_text_segments() const; 
        std::string cipher_text() const;
        std::string normalized_cipher_text() const;
    };
}  // namespace crypto_square
#endif // CRYPTO_SQUARE_H