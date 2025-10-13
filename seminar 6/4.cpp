#include <iostream>
using namespace std;

static const int MAX_LENGTH = 100;

class Base_number {
protected:
    unsigned char data[MAX_LENGTH];
    int len;

public:
    Base_number();
    virtual void setValue(string value) = 0;
    virtual void print() const = 0;
};

class BitString : public Base_number {
public:
    BitString();
    void print() const override;
    void setValue(string value) override;
};

class Hex : public Base_number {
public:
    Hex();
    void setValue(string value) override;
    void print() const override;
};

Base_number :: Base_number() {
    for (int i = 0; i < MAX_LENGTH; ++i) {
        data[i] = 0;
    }
    len = 0;
}

BitString :: BitString() : Base_number() {};

void BitString :: setValue(string value) {
    for (int i = 0; i < value.length(); i ++) {
        data[i] = char(value[i]);
    }
}

void BitString :: print() const {
    if (len == 0) {
        cout << "0" << endl;
        return;
    }

    for (int i = len - 1; i >= 0; --i) {
        cout << data[i];
    }

    cout << endl;
}

Hex :: Hex() : Base_number() {};

void Hex :: setValue(string value) {
    for (int i = 0; i < MAX_LENGTH; i ++) {
        data[i] = char(value[i]);
    }
}

void Hex :: print() const {
    if (len == 0) {
        cout << "0";
        return;
    }

    for (int i = len - 1; i >= 0; --i) {
        const unsigned char d = data[i];
        if (d < 10) {
            cout << d;
        } else {
            cout << char('A' + d - 10);
        }
    }

    cout << endl;
}

int main() {
    cout << "----------Тестирование класса BitString----------" << endl;

    BitString bit1;
    cout << "Тестирование конструктора по-умолчанию (ожидается 0): ";
    bit1.print();

    BitString bit2;
    cout << "Тестирование установки значения: ";
    bit2.setValue("54F2");
    bit2.print();
}
