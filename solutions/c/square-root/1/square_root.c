#include <stdint.h>
#include "square_root.h"

  uint32_t square_root(uint32_t squareIn) {
      uint32_t mostSignificant = 1;
      while (mostSignificant < squareIn) {
          mostSignificant <<= 1;
      }

      uint32_t currentGuess = 0;
      uint32_t tempGuess = 0;
      while (mostSignificant > 0) {
          tempGuess = mostSignificant | currentGuess;
          if (squareIn / tempGuess >= tempGuess) {
              currentGuess |= mostSignificant;
          }

          mostSignificant >>= 1;
      }

      return currentGuess;
  }