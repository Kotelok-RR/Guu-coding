#include <iostream>
#include <cmath>
using namespace std;

class Power_pair {
private:
    double first;
    int second;

public:
    void init(double f, int s) {
        first = f;
        second = s;
    }

    void read() {
        cout << "Ввод полей класса: " << endl;
        
        cout << "Значение числа first: ";
        cin >> first;
        
        cout << "Значение числа second: ";
        cin >> second;
    }
    
    void display() {
        cout << "first: " << first << endl;
        cout << "second: " << second << endl;
    }
    
    double power() {
        return pow(first, second);
    }
};

Power_pair make_power_pair(double first, int second) {
    Power_pair instant;
    instant.init(first, second);
    return instant;
}

void display_task_result(Power_pair p) { 
    p.display();
    cout << "Результат возведения в степень: " << p.power() << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    Power_pair instant_init;
    instant_init.init(3.5, 4);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init);
    cout << endl;

    // Создание объекта класса с помощью функции make_power_pair:
    Power_pair instant_function = make_power_pair(4.4, 2);
    
    cout << "2. Объект создан через make_power_pair:" << endl;
    display_task_result(instant_function);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    Power_pair instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Возведение в степень: " << instant_read_display.power() << endl;
    
    return 0;
}