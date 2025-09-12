#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class RangePair {
private:
    double first;
    double second;

public:
    void init(double left, double right) {
        if (left > right) {
            display_error("Левая граница не может быть больше правой");
            exit(-1);
        }
        
        first = left;
        second = right;
    }

    void read() {
        cout << "Ввод границ диапазона: " << endl;
        
        do {
            cout << "Левая граница: ";
            cin >> first;
            cout << "Правая граница: ";
            cin >> second;
            
            if (first > second) {
                display_error("Левая граница не может быть больше правой");
            }
        } while (first > second);
    }
    
    void display() {
        cout << "Диапазон: [" << first << ", " << second << "]" << endl;
    }
    
    bool rangecheck(double number) {
        return (number >= first) && (number <= second);
    }
};

RangePair make_rangepair(double left, double right) {
    RangePair instant;
    instant.init(left, right);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(RangePair p, double number) { 
    p.display();
    cout << "Число " << number << " ";
    if (p.rangecheck(number)) {
        cout << "принадлежит диапазону" << endl;
    } else {
        cout << "не принадлежит диапазону" << endl;
    }
}

int main() {
    // Создание объекта класса с помощью метода init:
    RangePair instant_init;
    instant_init.init(2.5, 7.8);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init, 5.0);
    cout << endl;

    // Создание объекта класса с помощью функции make_rangepair:
    RangePair instant_function = make_rangepair(-3.2, 10.5);
    
    cout << "2. Объект создан через make_rangepair:" << endl;
    display_task_result(instant_function, 15.0);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    RangePair instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    double test_number;
    cout << "Введите число для проверки: ";
    cin >> test_number;
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    if (instant_read_display.rangecheck(test_number)) {
        cout << "Число " << test_number << " принадлежит диапазону" << endl;
    } else {
        cout << "Число " << test_number << " не принадлежит диапазону" << endl;
    }
    
    return 0;
}