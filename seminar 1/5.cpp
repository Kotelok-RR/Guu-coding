#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class ProductPair {
private:
    double first;
    int second;

public:
    void init(double price, int quantity) {
        if (price <= 0) {
            display_error("Цена должна быть положительным числом");
            exit(-1);
        }
        if (quantity <= 0) {
            display_error("Количество должно быть положительным числом");
            exit(-1);
        }
        
        first = price;
        second = quantity;
    }

    void read() {
        cout << "Ввод данных о товаре: " << endl;
        
        do {
            cout << "Цена товара: ";
            cin >> first;
            
            if (first <= 0) {
                display_error("Цена должна быть положительным числом");
            }
        } while (first <= 0);

        do {
            cout << "Количество товара: ";
            cin >> second;
            
            if (second <= 0) {
                display_error("Количество должно быть положительным числом");
            }
        } while (second <= 0);
    }
    
    void display() {
        cout << "Цена: " << first << endl;
        cout << "Количество: " << second << endl;
    }
    
    double cost() {
        return first * second;
    }
};

ProductPair make_productpair(double price, int quantity) {
    ProductPair instant;
    instant.init(price, quantity);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(ProductPair p) { 
    p.display();
    cout << "Общая стоимость: " << p.cost() << " руб." << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    ProductPair instant_init;
    instant_init.init(150.5, 3);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init);
    cout << endl;

    // Создание объекта класса с помощью функции make_productpair:
    ProductPair instant_function = make_productpair(299.99, 2);
    
    cout << "2. Объект создан через make_productpair:" << endl;
    display_task_result(instant_function);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    ProductPair instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Стоимость: " << instant_read_display.cost() << " руб." << endl;
    
    return 0;
}