#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class PhoneCall {
private:
    int first;
    double second;

public:
    void init(int duration, double price_per_minute) {
        if (duration <= 0) {
            display_error("Продолжительность разговора должна быть положительным числом");
            exit(-1);
        }
        if (price_per_minute <= 0) {
            display_error("Стоимость минуты должна быть положительным числом");
            exit(-1);
        }
        
        first = duration;
        second = price_per_minute;
    }

    void read() {
        cout << "Ввод данных о телефонном разговоре: " << endl;
        
        do {
            cout << "Продолжительность разговора (минуты): ";
            cin >> first;
            
            if (first <= 0) {
                display_error("Продолжительность разговора должна быть положительным числом");
            }
        } while (first <= 0);

        do {
            cout << "Стоимость одной минуты (рубли): ";
            cin >> second;
            
            if (second <= 0) {
                display_error("Стоимость минуты должна быть положительным числом");
            }
        } while (second <= 0);
    }
    
    void display() {
        cout << "Продолжительность: " << first << " минут" << endl;
        cout << "Стоимость минуты: " << second << " руб." << endl;
    }
    
    double cost() {
        return first * second;
    }
};

PhoneCall make_phonecall(int duration, double price_per_minute) {
    PhoneCall instant;
    instant.init(duration, price_per_minute);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(PhoneCall p) { 
    p.display();
    cout << "Общая стоимость разговора: " << p.cost() << " руб." << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    PhoneCall instant_init;
    instant_init.init(10, 2.5);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init);
    cout << endl;

    // Создание объекта класса с помощью функции make_phonecall:
    PhoneCall instant_function = make_phonecall(15, 1.8);
    
    cout << "2. Объект создан через make_phonecall:" << endl;
    display_task_result(instant_function);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    PhoneCall instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Общая стоимость разговора: " << instant_read_display.cost() << " руб." << endl;
    
    return 0;
}