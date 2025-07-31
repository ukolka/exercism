#include "complex_numbers.h"
#include <cmath>

namespace complex_numbers {
    Complex::Complex(double real, double imag) : m_real(real), m_imag(imag) {}
    double Complex::real() const { return m_real; }
    double Complex::imag() const { return m_imag; }
    double Complex::abs() const { return sqrt(m_real * m_real + m_imag * m_imag); }

    Complex Complex::conj() const { return Complex(m_real, -m_imag); }

    Complex Complex::pow(int n) const {
        const double r = abs();
        const double theta = atan2(m_imag, m_real);
        return Complex(std::pow(r, n) * cos(n * theta), std::pow(r, n) * sin(n * theta));
    }

    Complex Complex::exp() const {
        return Complex(std::exp(m_real) * cos(m_imag), std::exp(m_real) * sin(m_imag));
    }

    Complex Complex::operator+(const Complex& rhs) const {
        return Complex(m_real + rhs.m_real, m_imag + rhs.m_imag);
    }

    Complex Complex::operator-(const Complex& rhs) const {
        return Complex(m_real - rhs.m_real, m_imag - rhs.m_imag);
    }
    
    Complex Complex::operator-() const { return Complex(-m_real, -m_imag); }

    Complex Complex::operator*(const Complex& rhs) const {
        return Complex(m_real * rhs.m_real - m_imag * rhs.m_imag,
                       m_real * rhs.m_imag + m_imag * rhs.m_real);
    }

    Complex Complex::operator/(const Complex& rhs) const {
        const double denominator = rhs.m_real * rhs.m_real +
                                   rhs.m_imag * rhs.m_imag;
        return Complex((m_real * rhs.m_real + m_imag * rhs.m_imag) /
                           denominator,
                       (m_imag * rhs.m_real - m_real * rhs.m_imag) /
                           denominator);
    }

    Complex Complex::operator~() const { return Complex(m_real, -m_imag); }
}  // namespace complex_numbers
