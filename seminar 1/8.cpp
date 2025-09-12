#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class RangePair {
private:
    int first;
    int second;

public:
    void init(int left, int right) {
        if (left >= right) {
            display_error("Левая граница должна быть меньше правой");
            exit(-1);
        }
        
        first = left;
        second = right;
    }

    void read() {
        cout << "Ввод границ полуоткрытого интервала [first, second): " << endl;
        
        do {
            cout << "Левая граница (включается): ";
            cin >> first;
            cout << "Правая граница (не включается): ";
            cin >> second;
            
            if (first >= second) {
                display_error("Левая граница должна быть меньше правой");
            }
        } while (first >= second);
    }
    
    void display() {
        cout << "Полуоткрытый интервал: [" << first << ", " << second << ")" << endl;
    }
    
    bool rangecheck(int number) {
        return (number >= first) && (number < second);
    }
};

RangePair make_rangepair(int left, int right) {
    RangePair instant;
    instant.init(left, right);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(RangePair p, int number) { 
    p.display();
    cout << "Число " << number << " ";
    if (p.rangecheck(number)) {
        cout << "принадлежит интервалу" << endl;
    } else {
        cout << "не принадлежит интервалу" << endl;
    }
}

int main() {
    // Создание объекта класса с помощью метода init:
    RangePair instant_init;
    instant_init.init(2, 7);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init, 5);
    cout << endl;

    // Создание объекта класса с помощью функции make_rangepair:
    RangePair instant_function = make_rangepair(-3, 10);
    
    cout << "2. Объект создан через make_rangepair:" << endl;
    display_task_result(instant_function, 10);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    RangePair instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    int test_number;
    cout << "Введите число для проверки: ";
    cin >> test_number;
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    if (instant_read_display.rangecheck(test_number)) {
        cout << "Число " << test_number << " принадлежит интервалу" << endl;
    } else {
        cout << "Число " << test_number << " не принадлежит интервалу" << endl;
    }
    
    return 0;
}