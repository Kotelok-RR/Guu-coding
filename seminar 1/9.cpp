#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class TimePair {
private:
    int first;
    int second;

public:
    void init(int hours, int minutes) {
        if (hours < 0) {
            display_error("Часы должны быть положительным числом");
            exit(-1);
        }
        if (minutes < 0 || minutes >= 60) {
            display_error("Минуты должны быть от 0 до 59");
            exit(-1);
        }
        
        first = hours;
        second = minutes;
    }

    void read() {
        cout << "Ввод времени: " << endl;
        
        do {
            cout << "Часы: ";
            cin >> first;
            
            if (first < 0) {
                display_error("Часы должны быть положительным числом");
            }
        } while (first < 0);

        do {
            cout << "Минуты (0-59): ";
            cin >> second;
            
            if (second < 0 || second >= 60) {
                display_error("Минуты должны быть от 0 до 59");
            }
        } while (second < 0 || second >= 60);
    }
    
    void display() {
        cout << "Время: " << first << " часов " << second << " минут" << endl;
    }
    
    int minutes() {
        return first * 60 + second;
    }
};

TimePair make_timepair(int hours, int minutes) {
    TimePair instant;
    instant.init(hours, minutes);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(TimePair p) { 
    p.display();
    cout << "Время в минутах: " << p.minutes() << " минут" << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    TimePair instant_init;
    instant_init.init(2, 30);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init);
    cout << endl;

    // Создание объекта класса с помощью функции make_timepair:
    TimePair instant_function = make_timepair(1, 45);
    
    cout << "2. Объект создан через make_timepair:" << endl;
    display_task_result(instant_function);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    TimePair instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Время в минутах: " << instant_read_display.minutes() << " минут" << endl;
    
    return 0;
}