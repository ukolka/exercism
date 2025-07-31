#include <ctype.h>
#include <string.h>
#include "isogram.h"
bool is_isogram(const char phrase[]) {
    if (phrase == NULL) return false;

    int len = strlen(phrase);
    if (len == 0) return true;
    
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (!isalpha(phrase[i])) continue;
            if (tolower(phrase[i]) == tolower(phrase[j])) return false;
        }
    }
    return true;
}
