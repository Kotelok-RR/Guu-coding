#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class Combination {
private:
    int first;
    int second;

public:
    void init(int k, int n) {
        if (k < 0 || n < 0) {
            display_error("k и n должны быть положительными числами");
            exit(-1);
        }
        if (k > n) {
            display_error("k не может быть больше n");
            exit(-1);
        }
        
        first = k;
        second = n;
    }

    void read() {
        cout << "Ввод данных для сочетаний C(n,k): " << endl;
        
        do {
            cout << "n (общее количество объектов): ";
            cin >> second;
            
            if (second < 0) {
                display_error("n должно быть положительным числом");
            }
        } while (second < 0);

        do {
            cout << "k (количество выбираемых объектов): ";
            cin >> first;
            
            if (first < 0) {
                display_error("k должно быть положительным числом");
            }
            if (first > second) {
                display_error("k не может быть больше n");
            }
        } while (first < 0 || first > second);
    }
    
    void display() {
        cout << "C(" << second << "," << first << ")" << endl;
    }
    
    long long factorial(int num) {
        if (num == 0 || num == 1) return 1;
        long long result = 1;
        for (int i = 2; i <= num; i++) {
            result *= i;
        }
        return result;
    }
    
    long long combination() {
        return factorial(second) / (factorial(second - first) * factorial(first));
    }
};

Combination make_combination(int k, int n) {
    Combination instant;
    instant.init(k, n);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(Combination p) { 
    p.display();
    cout << "Результат: " << p.combination() << endl;
}

int main() {
    // Создание объекта класса с помощью метода init:
    Combination instant_init;
    instant_init.init(2, 5);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init);
    cout << endl;

    // Создание объекта класса с помощью функции make_combination:
    Combination instant_function = make_combination(3, 8);
    
    cout << "2. Объект создан через make_combination:" << endl;
    display_task_result(instant_function);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    Combination instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    cout << "Результат:" << endl;
    cout << "Число сочетаний: " << instant_read_display.combination() << endl;
    
    return 0;
}