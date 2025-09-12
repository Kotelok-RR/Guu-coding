#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class GeometricProgression {
private:
    double first;
    double second;

public:
    void init(double a0, double r) {
        first = a0;
        second = r;
    }

    void read() {
        cout << "Ввод данных геометрической прогрессии: " << endl;
        
        cout << "Первый элемент a0: ";
        cin >> first;
        cout << "Постоянное отношение r: ";
        cin >> second;
    }
    
    void display() {
        cout << "Геометрическая прогрессия: a0 = " << first << ", r = " << second << endl;
    }
    
    double elementj(int j) {
        if (j < 0) {
            display_error("Индекс j должен быть неотрицательным");
            exit(-1);
        }
        return first * pow(second, j);
    }
};

GeometricProgression make_geometricprogression(double a0, double r) {
    GeometricProgression instant;
    instant.init(a0, r);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(GeometricProgression p, int j) { 
    p.display();
    cout << "Элемент a" << j << " = " << p.elementj(j) << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    GeometricProgression instant_init;
    instant_init.init(2.0, 3.0);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init, 4);
    cout << endl;

    // Создание объекта класса с помощью функции make_geometricprogression:
    GeometricProgression instant_function = make_geometricprogression(5.0, 2.0);
    
    cout << "2. Объект создан через make_geometricprogression:" << endl;
    display_task_result(instant_function, 3);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    GeometricProgression instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    int j;
    cout << "Введите индекс j элемента прогрессии: ";
    cin >> j;
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Элемент a" << j << " = " << instant_read_display.elementj(j) << endl;
    
    return 0;
}