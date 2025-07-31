#include "isogram.h"
#include <array>

namespace isogram {
   bool is_isogram(const string& input) {
        array<int, 26> hist{};
       
       for (auto ch : input) {
           char lcch = tolower(ch);
           if ('a' <= lcch && lcch <= 'z') {
               int idx = lcch - 'a';
               ++hist[idx];
               if (hist[idx] > 1) {
                   return false;
               }
           }
       }
       return true;
   }
}  // namespace isogram
