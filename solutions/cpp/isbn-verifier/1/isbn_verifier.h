#if !defined(ISBN_VERIFIER_H)
#define ISBN_VERIFIER_H
#include <string>
using namespace std;

namespace isbn_verifier {
    bool is_valid(const string& candidate);
    
} // namespace isbn_verifier

#endif // ISBN_VERIFIER_H