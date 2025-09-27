#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point(double x_val = 0, double y_val = 0);
    Point(const Point &other);
    
    Point operator+(const Point &other) const;
    Point operator-(const Point &other) const;
    Point operator*(double scalar) const;
    Point operator/(double scalar) const;

    void read();
    void display() const;
    void move_x(double dx);
    void move_y(double dy);
    double get_distance_from_zeros() const;
    double get_distance_to_point(const Point &other) const;
    void get_polar(double &r, double &atan) const;
    bool is_equal(const Point &other) const;
};

Point::Point(double x_val, double y_val) {
    x = x_val;
    y = y_val;
}

Point::Point(const Point &other) {
    x = other.x;
    y = other.y;
}

Point Point::operator+(const Point &other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator-(const Point &other) const {
    return Point(x - other.x, y - other.y);
}

Point Point::operator*(double scalar) const {
    return Point(x * scalar, y * scalar);
}

Point Point::operator/(double scalar) const {
    if (scalar == 0) {
        cout << "Ошибка: деление на ноль." << endl;
        return Point(x, y);
    }
    return Point(x / scalar, y / scalar);
}

void Point::read() {
    cout << "Введите координату x: ";
    cin >> x;
    cout << "Введите координату y: ";
    cin >> y;
}

void Point::display() const {
    cout << "(" << x << ", " << y << ")" << endl;
}

void Point::move_x(double dx) {
    x += dx;
}

void Point::move_y(double dy) {
    y += dy;
}

double Point::get_distance_from_zeros() const {
    return sqrt(pow(x, 2) + pow(y, 2));
}

double Point::get_distance_to_point(const Point &other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

void Point::get_polar(double &r, double &atan) const {
    r = get_distance_from_zeros();
    atan = atan2(y, x);
}

bool Point::is_equal(const Point &other) const {
    return (x == other.x && y == other.y);
}

int main() {
    Point p1(12.5, 5);
    Point p2;
    Point p3(p1);
    double p1_r;
    double p1_atan;

    cout << "Координаты p1 (с аргументами): ";
    p1.display();

    cout << "Координаты p2 (без аргументов): ";
    p2.display();

    cout << "Координаты p3 (копия p1): ";
    p3.display();

    cout << "Введите новые данные для p2:" << endl;
    p2.read();

    cout << "Новые координаты p2: ";
    p2.display();

    Point result;
    
    result = p1 + p2;
    cout << "p1 + p2 = "; result.display();
    
    result = p1 - p2;
    cout << "p1 - p2 = "; result.display();
    
    result = p1 * 2;
    cout << "p1 * 2 = "; result.display();

    result = p1 / 2;
    cout << "p1 / 2 = "; result.display();

    cout << "Смещение p2 на 3.3 по координате x: ";
    p2.move_x(3.3);
    p2.display();

    cout << "Смещение p1 на 2.5 по координате y: ";
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