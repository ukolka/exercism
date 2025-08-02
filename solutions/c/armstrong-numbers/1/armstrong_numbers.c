#include <math.h>
#include "armstrong_numbers.h"
bool is_armstrong_number(int candidate) {
    int backup = candidate;
    int length = 0;
    int sum = 0;
    int digit;

    while (candidate > 0) {
        length++;
        candidate /= 10;
    }

    candidate = backup;
    while (candidate > 0) {
        digit = candidate % 10;
        sum += pow(digit, length);
        candidate /= 10;
    }

    return backup == sum;
}