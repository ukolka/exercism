#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H
#include <string>
namespace atbash_cipher {
    std::string encode(std::string);
    std::string decode(std::string);
}  // namespace atbash_cipher

#endif // ATBASH_CIPHER_H