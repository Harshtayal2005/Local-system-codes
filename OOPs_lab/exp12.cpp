#include <iostream>
using namespace std;

class Complex {
public:
    float real;
    float imag;

    Complex() : real(0), imag(0) {}

    Complex operator + (const Complex& obj) const {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    Complex operator - (const Complex& obj) const {
        Complex temp;
        temp.real = real - obj.real;
        temp.imag = imag - obj.imag;
        return temp;
    }

    Complex operator * (const Complex& obj) const {
        Complex temp;
        temp.real = (real * obj.real) - (imag * obj.imag);
        temp.imag = (real * obj.imag) + (imag * obj.real);
        return temp;
    }

    Complex operator / (const Complex& obj) const {
        Complex temp;
        float denominator = obj.real * obj.real + obj.imag * obj.imag;
        temp.real = (real * obj.real + imag * obj.imag) / denominator;
        temp.imag = (imag * obj.real - real * obj.imag) / denominator;
        return temp;
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex num1, num2, result;

    cout << "Enter first complex number (real and imaginary parts): ";
    cin >> num1.real >> num1.imag;

    cout << "Enter second complex number (real and imaginary parts): ";
    cin >> num2.real >> num2.imag;

    // Addition
    result = num1 + num2;
    cout << "Sum: ";
    result.display();

    // Subtraction
    result = num1 - num2;
    cout << "Difference: ";
    result.display();

    // Multiplication
    result = num1 * num2;
    cout << "Product: ";
    result.display();

    // Division
    result = num1 / num2;
    cout << "Quotient: ";
    result.display();

    return 0;
}