#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ATM {
private:
    int ID;
    int bill_1000;
    int bill_500;
    int bill_100;
    int bill_50;
    int bill_10;
    int min_withdraw;
    int max_withdraw;

public:
    ATM(int ATM_ID = 0, int min = 100, int max = 10000);
    ATM(const ATM &other);
    
    void read();
    void display();
    string toString();

    ATM operator + (int amount) const;
    ATM operator - (int amount) const;
    bool operator == (const ATM &other) const;
    ATM& operator = (const ATM &other);

    void add_as_bills(int number_of_1000 = 0, int number_of_500 = 0, int number_of_100 = 0, int number_of_50 = 0, int number_of_10 = 0);
    void add_as_amount(int total_amount);
    
    bool withdraw(int amount);
    int get_total() const;
};

ATM::ATM(int ATM_ID, int min, int max) {
    ID = ATM_ID;
    min_withdraw = min;
    max_withdraw = max;
    bill_1000 = bill_500 = bill_100 = bill_50 = bill_10 = 0;
}

ATM::ATM(const ATM &other) {
    ID = other.ID + 1;
    bill_1000 = other.bill_1000;
    bill_500 = other.bill_500;
    bill_100 = other.bill_100;
    bill_50 = other.bill_50;
    bill_10 = other.bill_10;
    min_withdraw = other.min_withdraw;
    max_withdraw = other.max_withdraw;
}

void ATM::read() {
    cout << "Введите ID банкомата: ";
    cin >> ID;
    cout << "Введите минимальную сумму снятия: ";
    cin >> min_withdraw;
    cout << "Введите максимальную сумму снятия: ";
    cin >> max_withdraw;
}

void ATM::display() {
    cout << toString() << endl;
}

string ATM::toString() {
    string result = "Банкомат #" + to_string(ID) + " (" + to_string(get_total()) + " руб.)";
    return result;
}

void ATM::add_as_bills(int number_of_1000, int number_of_500, int number_of_100, int number_of_50, int number_of_10) {
    bill_1000 += number_of_1000;
    bill_500 += number_of_500;
    bill_100 += number_of_100;
    bill_50 += number_of_50;
    bill_10 += number_of_10;
}

void ATM::add_as_amount(int total_amount) {
    bill_1000 += total_amount / 1000;
    total_amount %= 1000;
    bill_500 += total_amount / 500;
    total_amount %= 500;
    bill_100 += total_amount / 100;
    total_amount %= 100;
    bill_50 += total_amount / 50;
    total_amount %= 50;
    bill_10 += total_amount / 10;
}

bool ATM::withdraw(int amount) {
    if (amount < min_withdraw || amount > max_withdraw) {
        cout << "Ошибка: сумма " << amount << " вне диапазона " << min_withdraw << "-" << max_withdraw << endl;
        return false;
    }
    
    if (amount > get_total()) {
        cout << "Ошибка: недостаточно денег!" << endl;
        return false;
    }
    
    if (amount % 10 != 0) {
        cout << "Ошибка: сумма должна быть кратной 10!" << endl;
        return false;
    }
    
    ATM temp = *this;
    int remaining = amount;
    
    int give1000 = min(remaining / 1000, temp.bill_1000);
    remaining -= give1000 * 1000;
    
    int give500 = min(remaining / 500, temp.bill_500);
    remaining -= give500 * 500;
    
    int give100 = min(remaining / 100, temp.bill_100);
    remaining -= give100 * 100;
    
    int give50 = min(remaining / 50, temp.bill_50);
    remaining -= give50 * 50;
    
    int give10 = min(remaining / 10, temp.bill_10);
    remaining -= give10 * 10;
    
    if (remaining == 0) {
        bill_1000 -= give1000;
        bill_500 -= give500;
        bill_100 -= give100;
        bill_50 -= give50;
        bill_10 -= give10;
        cout << "Выдано " << amount << " руб." << endl;
        return true;
    }
    
    cout << "Ошибка: невозможно выдать сумму!" << endl;
    return false;
}

int ATM::get_total() const {
    return bill_1000 * 1000 + bill_500 * 500 + bill_100 * 100 + bill_50 * 50 + bill_10 * 10;
}

ATM ATM::operator+(int amount) const {
    ATM result = *this;
    result.add_as_amount(amount);
    return result;
}

ATM ATM::operator-(int amount) const {
    ATM result = *this;
    result.add_as_amount(amount);
    return result;
}

bool ATM::operator==(const ATM &other) const {
    return get_total() == other.get_total();
}

ATM& ATM::operator=(const ATM &other) {
    if (this != &other) {
        ID = other.ID;
        bill_1000 = other.bill_1000;
        bill_500 = other.bill_500;
        bill_100 = other.bill_100;
        bill_50 = other.bill_50;
        bill_10 = other.bill_10;
        min_withdraw = other.min_withdraw;
        max_withdraw = other.max_withdraw;
    }
    return *this;
}

int main() {    
    ATM b1;
    ATM b2(2, 500, 20000);
    ATM b3(b2);
    
    cout << "Банкомат 1 (конструктор без аргументтов): " << endl;
    b1.display();
    cout << "Банкомат 2 (конструктор с аргументами): " << endl;
    b2.display();
    cout << "Банкомат 3 (копия 2-го банкомата): " << endl;
    b3.display();

    cout << "Добавления купюр в Банкомат 2: " << endl;
    b2.add_as_bills(5, 10, 20);
    b2.display();
    
    ATM b4 = b3 + 1000;
    cout << "b3 + 1000 = "; b4.display();

    ATM b5 = b4 - 250;
    cout << "b4 - 250 = "; b5.display();

    cout << "b1 == b2: " << (b2 == b1) << endl;

    cout << "Работа с банкоматом:" << endl;
    b2.withdraw(5000);
    b2.withdraw(15000);
    b2.display();

    cout << endl << "toString(): " << b2.toString() << endl;

    return 0;
}