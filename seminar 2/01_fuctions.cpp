#include <iostream>
#include <string>
#include <cmath>
using namespace std;


struct Complex {
    double real;
    double imag;
};

void init(Complex& c, double real = 0.0, double imag = 0.0) {
    c.real = real;
    c.imag = imag;
}

void read(Complex& c) {
    cout << "Введите действительную часть: ";
    cin >> c.real;
    cout << "Введите мнимую часть: ";
    cin >> c.imag;
}

void display(Complex& c) {
    cout << "Действительная часть = " << c.real << endl;
    cout << "Мнимая часть = " << c.imag << endl;
}

string toString(Complex& c) {
    if (c.imag == 0) {
        return to_string(c.real);
    } else if (c.real == 0) {
        return to_string(c.imag) + "i";
    } else if (c.imag > 0) {
        return to_string(c.real) + " + " + to_string(c.imag) + "i";
    } else {
        return to_string(c.real) + " - " + to_string(-c.imag) + "i";
    }
}

Complex add(Complex& c1, Complex& c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

Complex sub(Complex& c1, Complex& c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

Complex mul(Complex& c1, Complex& c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

Complex div(Complex& c1, Complex& c2) {
    Complex result;
    double denominator = c2.real * c2.real + c2.imag * c2.imag;
    if (denominator == 0) {
        throw runtime_error("Деление на ноль!");
    }
    result.real = (c1.real * c2.real + c1.imag * c2.imag) / denominator;
    result.imag = (c1.imag * c2.real - c1.real * c2.imag) / denominator;
    return result;
}

bool equ(Complex& c1, Complex& c2) {
    return (c1.real == c2.real) && (c1.imag == c2.imag);
}

Complex conj(Complex& c) {
    Complex result;
    result.real = c.real;
    result.imag = -c.imag;
    return result;
}

int main() {
    Complex c1;
    cout << "Создание через init: "; 
    init (c1);
    display(c1); cout << endl;

    Complex c2;
    cout << "Создание через read: ";
    read(c2);
    display(c2); cout << endl;

    Complex c3;
    cout << "Сложение c1 + c2: ";
    c3 = add(c1, c2); 
    display(c3); cout << endl;
    
    Complex c4;
    cout << "Вычитание c1 - c2: ";
    c4 = mul(c1, c2);
    display(c4); cout << endl;

    Complex c5;
    cout << "Умножение c1 * c2: ";
    c5 = div(c1, c2);
    display(c5); cout << endl;

    Complex c6;
    cout << "Деление c1 / c2";
    c6 = div(c1, c2);
    display(c6);

    bool c7_bool_result;
    cout << "Сравнение c1 == c2";
    c7_bool_result = equ(c1, c2);
    return 0;
}
