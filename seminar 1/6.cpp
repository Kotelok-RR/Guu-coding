#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class CaloriesPair {
private:
    int first;
    double second;

public:
    void init(int calories_per_100g, double weight_kg) {
        if (calories_per_100g <= 0) {
            display_error("Калорийность должна быть положительным числом");
            exit(-1);
        }
        if (weight_kg <= 0) {
            display_error("Вес должен быть положительным числом");
            exit(-1);
        }
        
        first = calories_per_100g;
        second = weight_kg;
    }

    void read() {
        cout << "Ввод данных о продукте: " << endl;
        
        do {
            cout << "Калорийность 100 г продукта: ";
            cin >> first;
            
            if (first <= 0) {
                display_error("Калорийность должна быть положительным числом");
            }
        } while (first <= 0);

        do {
            cout << "Масса продукта (кг): ";
            cin >> second;
            
            if (second <= 0) {
                display_error("Вес должен быть положительным числом");
            }
        } while (second <= 0);
    }
    
    void display() {
        cout << "Калорийность 100 г: " << first << " ккал" << endl;
        cout << "Масса продукта: " << second << " кг" << endl;
    }
    
    double power() {
        return (first * 10) * second;
    }
};

CaloriesPair make_caloriespair(int calories_per_100g, double weight_kg) {
    CaloriesPair instant;
    instant.init(calories_per_100g, weight_kg);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(CaloriesPair p) { 
    p.display();
    cout << "Общая калорийность: " << p.power() << " ккал" << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    CaloriesPair instant_init;
    instant_init.init(120, 0.5);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init);
    cout << endl;

    // Создание объекта класса с помощью функции make_caloriespair:
    CaloriesPair instant_function = make_caloriespair(85, 1.2);
    
    cout << "2. Объект создан через make_caloriespair:" << endl;
    display_task_result(instant_function);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    CaloriesPair instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Общая калорийность: " << instant_read_display.power() << " ккал" << endl;
    
    return 0;
}