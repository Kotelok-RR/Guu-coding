#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class IPair {
private:
    int first;
    int second;

public:
    void init(int f, int s) {
        first = f;
        second = s;
    }

    void read() {
        cout << "Ввод полей класса: " << endl;
        
        cout << "Значение числа first: ";
        cin >> first;

        do {
            cout << "Значение числа second: ";
            cin >> second;

            if (second == 0) {
                display_error("Знаменатель не может быть равен нулю");
            }
        } while(second == 0);
    }
    
    void display() {
        cout << "first: " << first << endl;
        cout << "second: " << second << endl;
    }
    
    int ipart() {
        if (second == 0) {
            cout << "Ошибка ввода. (Знаменатель равен нулю)";
            exit(-1);
        }

        return first/second;
    }
};

IPair make_ipair(double first, double second) {
    IPair instant;
    instant.init(first, second);

    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(IPair p) { 
    p.display();
    cout << "Результат выделения целой части: " << p.ipart() << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    IPair instant_init;
    instant_init.init(3, 4);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init);
    cout << endl;

    // Создание объекта класса с помощью функции make_ipart:
    IPair instant_function = make_ipair(5, 2);
    
    cout << "2. Объект создан через make_power_pair:" << endl;
    display_task_result(instant_function);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    IPair instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    display_task_result(instant_read_display);
    
    return 0;
}