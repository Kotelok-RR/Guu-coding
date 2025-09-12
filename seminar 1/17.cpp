#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void display_error(string error_message);

class Cursor {
private:
    int first;
    int second;
    const int screen_width = 1920;
    const int screen_height = 1080;

public:
    void init(int x, int y) {
        if (x < 0 || x >= screen_width) {
            display_error("Координата x выходит за границы экрана");
            exit(-1);
        }
        if (y < 0 || y >= screen_height) {
            display_error("Координата y выходит за границы экрана");
            exit(-1);
        }
        
        first = x;
        second = y;
    }

    void read() {
        cout << "Ввод координат курсора (экран " << screen_width << "x" << screen_height << "): " << endl;
        
        do {
            cout << "Координата x (0-" << screen_width-1 << "): ";
            cin >> first;
            
            if (first < 0 || first >= screen_width) {
                display_error("Координата x выходит за границы экрана");
            }
        } while (first < 0 || first >= screen_width);

        do {
            cout << "Координата y (0-" << screen_height-1 << "): ";
            cin >> second;
            
            if (second < 0 || second >= screen_height) {
                display_error("Координата y выходит за границы экрана");
            }
        } while (second < 0 || second >= screen_height);
    }
    
    void display() {
        cout << "Координаты курсора: (" << first << ", " << second << ")" << endl;
    }
    
    void changex(int new_x) {
        if (new_x < 0 || new_x >= screen_width) {
            display_error("Новая координата x выходит за границы экрана");
            return;
        }
        first = new_x;
    }
    
    void changey(int new_y) {
        if (new_y < 0 || new_y >= screen_height) {
            display_error("Новая координата y выходит за границы экрана");
            return;
        }
        second = new_y;
    }
    
    int getX() { return first; }
    int getY() { return second; }
};

Cursor make_cursor(int x, int y) {
    Cursor instant;
    instant.init(x, y);
    return instant;
}

void display_error(string error_message) {
    cout << error_message << endl;
}

void display_task_result(Cursor p) { 
    p.display();
}

int main() {
    // Создание объекта класса с помощью метода init:
    Cursor instant_init;
    instant_init.init(100, 200);
    
    cout << "1. Объект создан через init:" << endl;
    display_task_result(instant_init);
    cout << endl;

    // Создание объекта класса с помощью функции make_cursor:
    Cursor instant_function = make_cursor(500, 300);
    
    cout << "2. Объект создан через make_cursor:" << endl;
    display_task_result(instant_function);
    cout << endl;
    
    // Создание объекта класса с помощью методов read/display:
    Cursor instant_read_display;
    cout << "3. Ввод данных с клавиатуры:" << endl;
    instant_read_display.read();
    
    cout << "Введенные данные:" << endl;
    instant_read_display.display();
    
    // Тестирование изменения координат
    cout << "Тестирование изменения координат:" << endl;
    
    cout << "Изменение x на 800: ";
    instant_read_display.changex(800);
    cout << "Новые координаты: (" << instant_read_display.getX() << ", " << instant_read_display.getY() << ")" << endl;
    
    cout << "Изменение y на 600: ";
    instant_read_display.changey(600);
    cout << "Новые координаты: (" << instant_read_display.getX() << ", " << instant_read_display.getY() << ")" << endl;
    
    // Попытка выхода за границы
    cout << "Попытка установить x = 2000: ";
    instant_read_display.changex(2000);
    cout << "Координаты остались: (" << instant_read_display.getX() << ", " << instant_read_display.getY() << ")" << endl;
    
    return 0;
}