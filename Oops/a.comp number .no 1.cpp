#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;

    // Constructor with default values
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overloaded + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloaded * operator
    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Overloaded << operator
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return os;
    }

    // Overloaded >> operator
    friend istream& operator>>(istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }
};

int main() {
    Complex c1, c2;

    cout << "Enter first complex number (real and imaginary): ";
    cin >> c1;
    cout << "Enter second complex number (real and imaginary): ";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex product = c1 * c2;

    cout << "Sum: " << sum << "\n";
    cout << "Product: " << product << "\n";

    return 0;
} 