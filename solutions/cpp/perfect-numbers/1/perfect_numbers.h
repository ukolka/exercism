#if !defined(PERFECT_NUMBERS_H)
#define PERFECT_NUMBERS_H

namespace perfect_numbers {
    enum Classification {
        perfect,
        abundant,
        deficient
    };

    Classification classify(int number);

}  // namespace perfect_numbers

#endif  // PERFECT_NUMBERS_H