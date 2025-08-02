#include "rotational_cipher.h"

namespace rotational_cipher
{
    string rotate(const string &input, int rot)
    {
        string result;

        for (auto ch : input)
        {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                result += (ch - base + rot) % 26 + base;
            } else {
                result += ch;
            }
        }

        return result;
    }
} // namespace rotational_cipher
