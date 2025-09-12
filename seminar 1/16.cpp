#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class Number {
private:
    double first;
    double second;

public:
    void init(double integer_part, double fractional_part) {
        if (fractional_part < 0 || fractional_part >= 1.0) {
            display_error("Дробная часть должна быть в диапазоне [0, 1)");
            exit(-1);
        }
        
        first = integer_part;
        second = fractional_part;
    }

    void read() {
        cout << "Ввод числа с целой и дробной частью: " << endl;
        
        cout << "Целая часть: ";
        cin >> first;
        
        do {
            cout << "Дробная часть [0, 1): ";
            cin >> second;
            
            if (second < 0 || second >= 1.0) {
                display_error("Дробная часть должна быть в диапазоне [0, 1)");
            }
        } while (second < 0 || second >= 1.0);
    }
    
    void display() {
        cout << "Число: " << first + second << " (целая часть: " << first << ", дробная: " << second << ")" << endl;
    }
    
    double getFullNumber() {
        return first + second;
    }
    
    double multiply(double multiplier) {
        return (first + second) * multiplier;
    }
};

Number make_number(double integer_part, double fractional_part) {
    Number instant;
    instant.init(integer_part, fractional_part);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(Number p, double multiplier) { 
    p.display();
    cout << "Умножение на " << multiplier << ": " << p.multiply(multiplier) << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    Number instant_init;
    instant_init.init(3.0, 0.14);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init, 2.0);
    cout << endl;

    // Создание объекта класса с помощью функции make_number:
    Number instant_function = make_number(-2.0, 0.75);
    
    cout << "2. Объект создан через make_number:" << endl;
    display_task_result(instant_function, 3.0);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    Number instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    double multiplier;
    cout << "Введите множитель: ";
    cin >> multiplier;
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Умножение на " << multiplier << ": " << instant_read_display.multiply(multiplier) << endl;
    
    return 0;
}