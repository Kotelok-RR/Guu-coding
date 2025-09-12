#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class Salary {
private:
    double first;
    int second;

public:
    void init(double salary, int worked_days) {
        if (salary <= 0) {
            display_error("Оклад должен быть положительным числом");
            exit(-1);
        }
        if (worked_days <= 0 || worked_days > 31) {
            display_error("Количество отработанных дней должно быть от 1 до 31");
            exit(-1);
        }
        
        first = salary;
        second = worked_days;
    }

    void read() {
        cout << "Ввод данных о зарплате: " << endl;
        
        do {
            cout << "Оклад: ";
            cin >> first;
            
            if (first <= 0) {
                display_error("Оклад должен быть положительным числом");
            }
        } while (first <= 0);

        do {
            cout << "Отработанные дни (1-31): ";
            cin >> second;
            
            if (second <= 0 || second > 31) {
                display_error("Количество отработанных дней должно быть от 1 до 31");
            }
        } while (second <= 0 || second > 31);
    }
    
    void display() {
        cout << "Оклад: " << first << " руб." << endl;
        cout << "Отработанные дни: " << second << endl;
    }
    
    double summa(int days_in_month = 22) {
        if (days_in_month <= 0) {
            display_error("Количество дней в месяце должно быть положительным");
            exit(-1);
        }
        return first / days_in_month * second;
    }
};

Salary make_salary(double salary, int worked_days) {
    Salary instant;
    instant.init(salary, worked_days);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(Salary p, int days_in_month = 22) { 
    p.display();
    cout << "Начисленная сумма (" << days_in_month << " рабочих дней в месяце): " << p.summa(days_in_month) << " руб." << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    Salary instant_init;
    instant_init.init(30000.0, 15);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init);
    cout << endl;

    // Создание объекта класса с помощью функции make_salary:
    Salary instant_function = make_salary(45000.0, 20);
    
    cout << "2. Объект создан через make_salary:" << endl;
    display_task_result(instant_function);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    Salary instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    int month_days;
    cout << "Введите количество рабочих дней в месяце: ";
    cin >> month_days;
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Начисленная сумма: " << instant_read_display.summa(month_days) << " руб." << endl;
    
    return 0;
}