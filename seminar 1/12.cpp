#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class Point {
private:
    double first;
    double second;

public:
    void init(double x, double y) {
        first = x;
        second = y;
    }

    void read() {
        cout << "Ввод координат точки: " << endl;
        
        cout << "Координата x: ";
        cin >> first;
        cout << "Координата y: ";
        cin >> second;
    }
    
    void display() {
        cout << "Точка: (" << first << ", " << second << ")" << endl;
    }
    
    double distance() {
        return sqrt(first * first + second * second);
    }
};

Point make_point(double x, double y) {
    Point instant;
    instant.init(x, y);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(Point p) { 
    p.display();
    cout << "Расстояние от начала координат: " << p.distance() << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    Point instant_init;
    instant_init.init(3.0, 4.0);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init);
    cout << endl;

    // Создание объекта класса с помощью функции make_point:
    Point instant_function = make_point(-2.0, 5.0);
    
    cout << "2. Объект создан через make_point:" << endl;
    display_task_result(instant_function);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    Point instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Расстояние от начала координат: " << instant_read_display.distance() << endl;
    
    return 0;
}