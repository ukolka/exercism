#include <stdlib.h>
#include <math.h>
#include "rational_numbers.h"

static int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

static rational_t create(int numerator, int denominator) {
    return reduce((rational_t) { numerator, denominator });
}

static rational_t inverse(rational_t a) {
    return create(a.denominator, a.numerator);
}

rational_t add(rational_t a, rational_t b) {
    int result_denominator = a.denominator * b.denominator;

    return create(
        a.numerator * (result_denominator / a.denominator) + 
        b.numerator * (result_denominator / b.denominator),
        result_denominator
    );
}
rational_t multiply(rational_t a, rational_t b) {
    return create(
        a.numerator * b.numerator,
        a.denominator * b.denominator);
}

rational_t divide(rational_t a, rational_t b) {
    return multiply(a, inverse(b));
}

rational_t subtract(rational_t a, rational_t b) {
    b.numerator = -b.numerator;
    return add(a, b);
}

rational_t exp_rational(rational_t r, int16_t n) {
    rational_t result = {1, 1};
    rational_t r_norm = create(r.numerator, r.denominator); 

    if (n < 0) {
        r_norm = inverse(r);
        n *= -1;
    }
    while (n-- > 0) {
        result = multiply(result, r_norm);
    }

    return reduce(result);
}

float exp_real(int16_t r, rational_t n) {
    return pow(r, (float) n.numerator / (float) n.denominator);
}

rational_t absolute(rational_t a) {
    a = reduce(a);
    rational_t result = create(
        abs(a.numerator),
        a.denominator);
    return result;
}

rational_t reduce(rational_t a) {
    if (a.numerator == 0 && a.denominator != 0) {
        a.denominator = 1;
    }

    int gcd_val = gcd(a.numerator, a.denominator);    
    a.numerator /= gcd_val;
    a.denominator /= gcd_val;

    if (a.denominator < 0 && a.numerator > 0) {
        a.numerator *= -1;
        a.denominator *= -1;
    }

    return a;
}
