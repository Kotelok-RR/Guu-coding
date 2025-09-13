#include <iostream>
#include <string>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    void init(double r, double i) {
        real = r;
        imag = i;
    };

    void read() {
        cout << "Введите действительную часть числа: ";
        cin >> real;

        cout << "Введите мнимую часть числа: ";
        cin >> imag;
    };

    void display() {
        cout << "Действительная часть = " << real << endl;
        cout << "Мнимая часть = " << imag << endl;
    }

    string toString() {
        if (imag == 0) {
            return to_string(real);
        } else if (real == 0) {
            return to_string(imag) + "i";
        } else if (imag > 0) {
            return to_string(real) + " + " +to_string(imag) + "i";
        } else {
            return to_string(real) + " - " + to_string(-imag) + "i";
        }
    }

    Complex add(Complex &other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex sub(Complex &other) {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex mul(Complex &other) {
        return Complex(real * other.real + imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex div(Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            cout << "Ошибка при делении на ноль" << endl;
            exit (-1);
        }
        return Complex((real * other.real + imag * other.imag) / denominator,
                      (imag * other.real - real * other.imag) / denominator);
    }

    bool equ(Complex &other) {
        if (real != other.real || imag != other.imag) return false;

        return true;
    }

    Complex conj() {
        return Complex(real, -imag);
    }
};

int main() {
    Complex c1;
    c1.init(2.5, 3.7);
    cout << "Создание через init: " << endl; 
    c1.display(); cout << endl;
    
    Complex c2;
    cout << "Создание через read:" << endl;
    c2.read();
    c2.display(); cout << endl;
    
    Complex c3 = c1.add(c2);
    cout << "Сложение c1 + c2: "; c3.display(); cout << endl;

    Complex c4 = c1.sub(c2);
    cout << "Вычитание c1 - c2: "; c4.display(); cout << endl;

    Complex c5 = c1.mul(c2);
    cout << "Умножение c1 * c2: "; c5.display(); cout << endl;

    Complex c6 = c1.div(c2);
    cout << "Деление c1 / c2: "; c6.display(); cout << endl;

    bool c7_equ_result = c1.equ(c2);
    cout << "Сравнение c1 == c2: " << c7_equ_result;
    return 0;
}
