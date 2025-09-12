#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class LinearEquation {
private:
    double first;
    double second;

public:
    void init(double A, double B) {
        first = A;
        second = B;
    }

    void read() {
        cout << "Ввод коэффициентов линейного уравнения y = Ax + B: " << endl;
        
        cout << "Коэффициент A: ";
        cin >> first;
        cout << "Коэффициент B: ";
        cin >> second;
    }
    
    void display() {
        cout << "Уравнение: y = " << first << "x + " << second << endl;
    }
    
    double function(double x) {
        return first * x + second;
    }
};

LinearEquation make_linearequation(double A, double B) {
    LinearEquation instant;
    instant.init(A, B);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(LinearEquation p, double x) { 
    p.display();
    cout << "При x = " << x << ", y = " << p.function(x) << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    LinearEquation instant_init;
    instant_init.init(2.5, 3.0);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init, 4.0);
    cout << endl;

    // Создание объекта класса с помощью функции make_linearequation:
    LinearEquation instant_function = make_linearequation(-1.0, 5.0);
    
    cout << "2. Объект создан через make_linearequation:" << endl;
    display_task_result(instant_function, 2.0);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    LinearEquation instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    double x_value;
    cout << "Введите значение x: ";
    cin >> x_value;
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "При x = " << x_value << ", y = " << instant_read_display.function(x_value) << endl;
    
    return 0;
}