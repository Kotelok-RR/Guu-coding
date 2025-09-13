#include <iostream>
#include <string>
using namespace std;

class Point {
private:
    double x;
    double y;
public:
    Point(double x_val = 0, double y_val = 0) {
        x = x_val;
        y = y_val;
    }

    void init(double x_val, double y_val) {
        x = x_val;
        y = y_val;
    };

    void read() {
        cout << "Введите координату x: ";
        cin >> x;

        cout << "Введите координату y: ";
        cin >> y;
    };

    void display() {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

    string toString() {
        return "(" + to_string(x) + " ; " + to_string(y) + ")";
    }

    void move_x(double value) {
        x += value;
    }

    void move_y(double value) {
        y += value;
    }

    double get_distance_from_zeros() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

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
    Point p1;
    p1.init(2.5, 3.7);
    cout << "Создание через init: " << endl; 
    p1.display(); cout << endl;
    
    Point p2;
    cout << "Создание через read:" << endl;
    p2.read();
    p2.display(); cout << endl;

    cout << "Расстояние p1 от начала координат: " << p1.get_distance_from_zeros() << endl;
    cout << "Расстояние p2 от начала координат: " << p2.get_distance_from_zeros() << endl;
    cout << "Расстояния между p1 и p2: " << p1.get_distance_to_point(p2) << endl;
    cout << "Проверка на совпадение p1 и p2: " << p1.is_equal(p2) << endl;

    return 0;
}
