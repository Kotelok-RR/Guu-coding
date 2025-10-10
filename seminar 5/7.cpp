#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void incorrect_side_len_exception() {
    cout << "Сторона треугольника должна быть больше нуля";
    exit (-1);
}

void sum_of_two_sides_is_less_than_third_exception() {
    cout << "Некорректные данные для треугольника (сума двух любых сторон должна быть больше длины третьей стороны)." << endl;
    exit (-1);
}

// ---------------------------------------------------------------------------------------------------

class Triangle {
    double AB, BC, AC;

public:
    Triangle(double AB_val = 3, double BC_val = 4, double AC_val = 5);
    Triangle(Triangle &copy);

    void display();
    double get_perimeter();
    double get_angle_ACB();
    double get_angle_BAC();
    double get_angle_ABC();

    double get_AB();
    double get_BC();
    double get_AC();

    void set_AB(double side_len);
    void set_BC(double side_len);
    void set_AC(double side_len);
};

Triangle :: Triangle(double AB_val, double BC_val, double AC_val) {
    if (AB_val <= 0 | BC_val <= 0 | BC_val <= 0) incorrect_side_len_exception();

    if (AB_val + BC_val <= AC_val | AB_val + AC_val < BC_val | BC_val + AC_val < AB_val) sum_of_two_sides_is_less_than_third_exception();

    AB = AB_val;
    BC = BC_val;
    AC = AC_val;
}

Triangle :: Triangle(Triangle &copy) {
    AB = copy.AB;
    BC = copy.BC;
    AC = copy.AC;
}

void Triangle :: display() {
    cout << "Стороны треугольника: " << endl;
    cout << "AB = " << AB << endl;
    cout << "BC = " << BC << endl;
    cout << "AC = " << AC << endl;
}

double Triangle :: get_perimeter() {
    return (AB + BC + AC);
}

double Triangle :: get_angle_ACB() {
    return acos((pow(BC, 2) + pow(AC, 2) - pow(AB, 2)) / (2 * BC * AC));
}

double Triangle :: get_angle_BAC() {
    return acos((pow(AB, 2) + pow(AC, 2) - pow(BC, 2)) / (2 * AB * AC));
}

double Triangle :: get_angle_ABC() {
    return acos((pow(AB, 2) + pow(AC, 2) - pow(AC, 2)) / (2 * AB * BC));
}

double Triangle :: get_AB() {
    return AB;
}

double Triangle :: get_BC() {
    return BC;
}
double Triangle :: get_AC() {
    return AC;
}

void Triangle :: set_AB(double side_len) {
    if (side_len <= 0) incorrect_side_len_exception();

    AB = side_len;
}

void Triangle :: set_BC(double side_len) {
    if (side_len <= 0) incorrect_side_len_exception();

    BC = side_len;
}

void Triangle :: set_AC(double side_len) {
    if (side_len <= 0) incorrect_side_len_exception();

    AC = side_len;
}

// ---------------------------------------------------------------------------------------------------

class Equilateral : public Triangle {
    double area;

public:
    Equilateral(double side = 5);

    double calculate_area();

    double get_area();

    void set_area();
};

Equilateral :: Equilateral(double side) : Triangle(side, side, side) {
    set_area();
}

double Equilateral :: calculate_area() {
    area = (pow(get_AB(), 2) * sqrt(3)) / 4;

    return area;
}

double Equilateral :: get_area() {
    return area;
}

void Equilateral :: set_area() {
    area = calculate_area();
}

// ---------------------------------------------------------------------------------------------------

int main() {
    cout << "----- Тестирование класса Triangle -----";

    cout << "\n1. Создание треугольника со сторонами 6, 8, 10:" << endl;

    Triangle t1(6, 8, 10);
    t1.display();
    cout << "Периметр: " << t1.get_perimeter() << endl;
    cout << "Угол ACB: " << t1.get_angle_ACB() << " радиан" << endl;
    cout << "Угол BAC: " << t1.get_angle_BAC() << " радиан" << endl;
    cout << "Угол ABC: " << t1.get_angle_ABC() << " радиан" << endl;

    cout << "Треугольник по умолчанию:" << endl;
    Triangle t2;
    t2.display();
    cout << "Периметр: " << t2.get_perimeter() << endl;

    cout << "Изменение сторон треугольника:" << endl;
    Triangle t3(5, 5, 5);
    t3.display();
    cout << "Периметр до изменения: " << t3.get_perimeter() << endl;
    t3.set_AB(6);
    t3.set_BC(7);
    t3.set_AC(8);
    cout << "После изменения сторон:" << endl;
    t3.display();
    cout << "Периметр после изменения: " << t3.get_perimeter() << endl;

    cout << "----- Тестирование класса Equilateral -----" << endl;
    
    cout << "Равносторонний треугольник со стороной 4:" << endl;
    Equilateral eq1(4);
    eq1.display();
    cout << "Площадь: " << eq1.get_area() << endl;
    cout << "Периметр: " << eq1.get_perimeter() << endl;
    
    cout << "Равносторонний треугольник по умолчанию:" << endl;
    Equilateral eq2;
    eq2.display();
    cout << "Площадь: " << eq2.get_area() << endl;

    return 0;
}