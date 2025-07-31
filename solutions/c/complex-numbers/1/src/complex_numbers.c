#include "complex_numbers.h"
#include <math.h>

complex_t c_add(complex_t a, complex_t b)
{
  return (complex_t) { a.real + b.real, a.imag + b.imag };
}

complex_t c_sub(complex_t a, complex_t b)
{
  return (complex_t) { a.real - b.real, a.imag - b.imag };
}

//(a + i * b) * (c + i * d) =
//(a * c - b * d) + (b * c + a * d) * i
complex_t c_mul(complex_t a, complex_t b)
{
  complex_t rv = {
    (a.real * b.real - a.imag * b.imag),
    (a.imag * b.real + a.real * b.imag)
  };
  return rv;
}

//(a + i * b) / (c + i * d) =
//(a * c + b * d)/(c^2 + d^2) + (b * c - a * d)/(c^2 + d^2) * i
complex_t c_div(complex_t a, complex_t b)
{
  double divisor = (b.real * b.real + b.imag * b.imag);
  
  complex_t rv = {
    (a.real * b.real + a.imag * b.imag) / divisor,
    (a.imag * b.real - a.real * b.imag) / divisor
  };

  return rv;
}

double c_abs(complex_t x)
{
  return sqrt(x.real * x.real + x.imag * x.imag);
}

complex_t c_conjugate(complex_t x)
{
  return (complex_t) { x.real, -x.imag };
}

double c_real(complex_t x)
{
  return x.real;
}

double c_imag(complex_t x)
{
  return x.imag;
}

//exp(a + i * b) = exp(a) * exp(i * b)
//exp(i * b) = cos(b) + i * sin(b)
complex_t c_exp(complex_t x)
{
  complex_t a = { exp(x.real), 0 };
  complex_t b = { cos(x.imag), sin(x.imag) };
  return c_mul(a, b);
}