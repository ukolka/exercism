#include <string.h>
#include <stddef.h>
#include "hamming.h"

int compute(const char *a, const char *b) {
    if (a == NULL || b == NULL || strlen(a) != strlen(b)) {
        return -1;
    }
    int sum = 0;
    char ch_a;
    char ch_b;
    while ((ch_a = *a++) && (ch_b = *b++))
        if (ch_a != ch_b) sum++;

    return sum;  
}
