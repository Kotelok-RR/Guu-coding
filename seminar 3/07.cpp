#include <iostream>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point(double x_val = 0, double y_val = 0) {
        x = x_val;
        y = y_val;
    };

    Point(Point &other) {
        x = other.x;
        y = other.y;
    }

    void read() {
        cout << "Введите координату x: ";
        cin >> x;

        cout << "Введите координату y: ";
        cin >> y;
    }

    void display() {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

    void move_x(double dx) {
        x += dx;
    }

    void move_y(double dy) {
        y += dy;
    }

    double get_distance_from_zeros() {
        return sqrt(pow(x, 2) + pow(y, 2));
    };

    double get_distance_to_point(Point &other) {
        double dx = x - other.x;
        double dy = x - other.y;

        return sqrt(pow(dx, 2) + pow(dy, 2));
    }

    void get_polar(double &r, double &atan) {
        r = get_distance_from_zeros();
        atan = atan2(y, x);
    }

    bool is_equal(Point &other) {
        if (x != other.x || y != other.y) return false;

        return true;
    }
};

int main() {
    Point p1(12.5, 5);
    Point p2;
    Point p3(p1);
    double p1_r;
    double p1_atan;

    cout << "Координаты p1 (с аргументами):" << endl;
    p1.display();

    cout << "Координаты p2 (без аргументов):" << endl;
    p2.display();

    cout << "Координаты p3 (копия p1):" << endl;
    p3.display();

    cout << "Введите новые данные для p2" << endl;
    p2.read();

    cout << "Новые координаты p2 :" << endl;
    p2.display();

    cout << "Смещение p2 на 3.3 по координтае x: " << endl;
    p2.move_x(3.3);
    p2.display();

    cout << "Смещение p1 на 2.5 по координтае y: " << endl;
    p1.move_y(2.5);
    p1.display();

    cout << "Расстояние p1 от начала координат: " << p1.get_distance_from_zeros() << endl;

    cout << "Расстояние p2 от начала координат: " << p2.get_distance_from_zeros() << endl;

    cout << "Расстояния между p1 и p2: " << p1.get_distance_to_point(p2) << endl;

    cout << "Проверка на совпадение p1 и p2: " << p1.is_equal(p2) << endl;

    cout << "Полярные координаты p1:" << endl;
    p1.get_polar(p1_r, p1_atan);
    cout << "p1_r: " << p1_r << endl;
    cout << "p1_atan: " << p1_atan << endl; 

    return 0;
}
