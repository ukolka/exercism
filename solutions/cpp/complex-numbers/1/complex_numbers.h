#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers {
    class Complex {
        private:
            double m_real;
            double m_imag;
        public:
            Complex(double real, double imag);
            double real() const;
            double imag() const;
            Complex operator+(const Complex& rhs) const;
            Complex operator-(const Complex& rhs) const;
            Complex operator*(const Complex& rhs) const;
            Complex operator/(const Complex& rhs) const;
            Complex operator-() const;
            Complex operator~() const;
            double abs() const;
            Complex pow(int n) const;
            Complex exp() const;
            Complex conj() const;
    };
}  // namespace complex_numbers

#endif  // COMPLEX_NUMBERS_H
