#include <iostream>
#include <string>
using namespace std;

struct Point {
    double x;
    double y;
};

void init(Point &p, double x_val, double y_val) {
    p.x = x_val;
    p.y = y_val;
}

void read(Point &p) {
    cout << "Введите координату x: ";
    cin >> p.x;

    cout << "Введите координату y: ";
    cin >> p.y;
}

void display(Point &p) {
    cout << "x = " << p.x << endl;
    cout << "y = " << p.y << endl;
}

string toString(Point &p) {
    return "(" + to_string(p.x) + " ; " + to_string(p.y) + ")";
}

void move_x(Point &p, double dx) {
    p.x += dx;
}

void move_y(Point &p, double dy) {
    p.y += dy;
}

double get_distance_from_zeros(Point &p) {
    return sqrt(pow(p.x, 2) + pow(p.y, 2));
}

double get_distance_to_point(Point &first, Point &second) {
    double dx = first.x - second.y;
    double dy = first.y - second.y;

    return sqrt(pow(dx, 2) + pow(dy, 2));
}


void get_polar(Point &p, double &r, double &atan) {
    r = get_distance_from_zeros(p);
    atan = atan2(p.y, p.x);
}

bool is_equal(Point &first, Point &second) {
    if (first.x != second.x || first.y != second.y) return false;

    return true;
}

int main() {
    Point p1;
    init(p1, 2.2, 6.5);
    cout << "Создание через init: " << endl;
    display(p1); cout << endl;

    Point p2;
    cout << "Создание через read:" << endl;
    read(p2);
    display(p2); cout << endl;

    cout << "Расстояние p1 от начала координат: " << get_distance_from_zeros(p1) << endl;
    cout << "Расстояние p2 от начала координат: " << get_distance_from_zeros(p2) << endl;
    cout << "Расстояние между p1 и p2: " << get_distance_to_point(p1, p2) << endl;
    cout << "Проверка на совпадение p1 и p2: " << is_equal(p1, p2) << endl;

    return 0;
}
