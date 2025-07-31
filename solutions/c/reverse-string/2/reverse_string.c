#include <stdlib.h>
#include <string.h>
#include "reverse_string.h"

char* reverse(const char* string) {
    if (string == NULL) {
        return NULL;
    }
    size_t len = strlen(string);
    char* newString = realloc(NULL, (sizeof(char) * len) + 1);
    memcpy(newString, string, len);
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        newString[i] = string[j];
    }
    newString[len] = '\0';
    return newString; 
}
