#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class Number {
private:
    int first;
    int second;

public:
    void init(int integer_part, int fractional_part) {
        if (fractional_part < 0) {
            display_error("Дробная часть должна быть положительным числом");
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
            cout << "Дробная часть (положительное целое): ";
            cin >> second;
            
            if (second < 0) {
                display_error("Дробная часть должна быть положительным числом");
            }
        } while (second < 0);
    }
    
    void display() {
        cout << "Число: " << first << "." << second << " (целая часть: " << first << ", дробная: " << second << ")" << endl;
    }
    
    double getFullNumber() {
        return first + second * 0.01; // Предполагаем, что дробная часть - это сотые доли
    }
    
    double multiply(int multiplier) {
        return (first + second * 0.01) * multiplier;
    }
};

Number make_number(int integer_part, int fractional_part) {
    Number instant;
    instant.init(integer_part, fractional_part);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(Number p, int multiplier) { 
    p.display();
    cout << "Умножение на " << multiplier << ": " << p.multiply(multiplier) << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    Number instant_init;
    instant_init.init(3, 14);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init, 2);
    cout << endl;

    // Создание объекта класса с помощью функции make_number:
    Number instant_function = make_number(-2, 75);
    
    cout << "2. Объект создан через make_number:" << endl;
    display_task_result(instant_function, 3);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    Number instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    int multiplier;
    cout << "Введите целый множитель: ";
    cin >> multiplier;
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Умножение на " << multiplier << ": " << instant_read_display.multiply(multiplier) << endl;
    
    return 0;
}