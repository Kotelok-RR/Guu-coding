#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class Triangle {
private:
    double first;
    double second;

public:
    void init(double a, double b) {
        if (a <= 0 || b <= 0) {
            display_error("Катеты должны быть положительными числами");
            exit(-1);
        }
        first = a;
        second = b;
    }

    void read() {
        cout << "Ввод катетов прямоугольного треугольника: " << endl;
        
        do {
            cout << "Катет a: ";
            cin >> first;
            
            if (first <= 0) {
                display_error("Катет должен быть положительным числом");
            }
        } while (first <= 0);

        do {
            cout << "Катет b: ";
            cin >> second;
            
            if (second <= 0) {
                display_error("Катет должен быть положительным числом");
            }
        } while (second <= 0);
    }
    
    void display() {
        cout << "Катет a: " << first << endl;
        cout << "Катет b: " << second << endl;
    }
    
    double hypotenuse() {
        return sqrt(first * first + second * second);
    }
};

Triangle make_triangle(double a, double b) {
    Triangle instant;
    instant.init(a, b);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(Triangle p) { 
    p.display();
    cout << "Гипотенуза: " << p.hypotenuse() << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    Triangle instant_init;
    instant_init.init(3.0, 4.0);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init);
    cout << endl;

    // Создание объекта класса с помощью функции make_triangle:
    Triangle instant_function = make_triangle(5.0, 12.0);
    
    cout << "2. Объект создан через make_triangle:" << endl;
    display_task_result(instant_function);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    Triangle instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Гипотенуза: " << instant_read_display.hypotenuse() << endl;
    
    return 0;
}