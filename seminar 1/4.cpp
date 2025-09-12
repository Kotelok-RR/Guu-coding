#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class MoneyPair {
private:
    int first;
    int second;

public:
    void init(int denomination, int count) {
        int valid_denominations[] = {1, 2, 5, 10, 50, 100, 500, 1000, 5000};
        int size = 9;
        bool valid = false;
        
        for (int i = 0; i < size; i++) {
            if (denomination == valid_denominations[i]) {
                valid = true;
                break;
            }
        }
        
        if (!valid) {
            display_error("Недопустимый номинал купюры");
            exit(-1);
        }
        
        if (count <= 0) {
            display_error("Количество купюр должно быть положительным");
            exit(-1);
        }
        
        first = denomination;
        second = count;
    }

    void read() {
        cout << "Ввод данных о купюрах: " << endl;
        
        int valid_denominations[] = {1, 2, 5, 10, 50, 100, 500, 1000, 5000};
        int size = 9;
        bool valid = false;
        
        do {
            cout << "Номинал купюры (1,2,5,10,50,100,500,1000,5000): ";
            cin >> first;
            
            valid = false;
            for (int i = 0; i < size; i++) {
                if (first == valid_denominations[i]) {
                    valid = true;
                    break;
                }
            }
            
            if (!valid) {
                display_error("Недопустимый номинал купюры");
            }
        } while (!valid);

        do {
            cout << "Количество купюр: ";
            cin >> second;
            
            if (second <= 0) {
                display_error("Количество купюр должно быть положительным");
            }
        } while (second <= 0);
    }
    
    void display() {
        cout << "Номинал: " << first << endl;
        cout << "Количество: " << second << endl;
    }
    
    int summa() {
        return first * second;
    }
};

MoneyPair make_moneypair(int denomination, int count) {
    MoneyPair instant;
    instant.init(denomination, count);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(MoneyPair p) { 
    p.display();
    cout << "Общая сумма: " << p.summa() << " руб." << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    MoneyPair instant_init;
    instant_init.init(100, 5);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init);
    cout << endl;

    // Создание объекта класса с помощью функции make_moneypair:
    MoneyPair instant_function = make_moneypair(500, 3);
    
    cout << "2. Объект создан через make_moneypair:" << endl;
    display_task_result(instant_function);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    MoneyPair instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Сумма: " << instant_read_display.summa() << " руб." << endl;
    
    return 0;
}