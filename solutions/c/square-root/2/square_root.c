#include <stdint.h>
#include "square_root.h"

  uint32_t square_root(uint32_t squareIn) {
      uint32_t currentPowerOf2 = 1;
      while (currentPowerOf2 < squareIn) {
          currentPowerOf2 *= 2;
      }

      uint32_t result = 0;
      uint32_t guess = 0;
      while (currentPowerOf2 > 0) {
          guess = currentPowerOf2 + result;
          if (squareIn / guess >= guess) {
              result = guess;
          }

          currentPowerOf2 /= 2;
      }

      return result;
  }