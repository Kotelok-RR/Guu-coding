#include <iostream>
#include <string>
using namespace std;

const int DIGITS_SIZE = 100;
const int BITS_SIZE = 100;

class Base_number {
public:
    virtual void setFromString(const string& value) = 0;
    virtual void print() const = 0;
};

class Decimal : public Base_number {
    unsigned char digits[100];
    bool sign;

public:
    Decimal();
    void setFromString(const string& number) override;
    void print() const override;
};

class BitString : public Base_number {
    unsigned char bits[BITS_SIZE];

public:
    BitString();
    void setFromString(const string& bitStr) override;
    void print() const override;
};

Decimal :: Decimal() {
    for (int i = 0; i < DIGITS_SIZE; i++) {
        digits[i] = 0;
    }

    sign = true;
};

void Decimal :: setFromString(const string& number) {
    int start = 0;
    sign = true;

    if (number[0] == '-') {
        sign = false;
        start = 1;
    }

    for (int i = 0; i < DIGITS_SIZE; i++) {
        digits[i] = 0;
    }

    int index = 0;

    for (int i = number.length() - 1; i >= start && index < DIGITS_SIZE; i--) {
        digits[index++] = number[i] - '0';
    }
}

void Decimal :: print() const {
    if (!sign) {
        cout << "-";
    }

    bool leadingZero = true;

    for (int i = DIGITS_SIZE - 1; i >= 0; i--) {
        if (digits[i] != 0) {
            leadingZero = false;
        }
        if (!leadingZero) {
            cout << (int)digits[i];
        }
    }

    if (leadingZero) {
        cout << "0";
    }

    cout << endl;
}

BitString :: BitString() {
    for (int i = 0; i < BITS_SIZE; i++) {
        bits[i] = 0;
    }
}

void BitString :: setFromString(const string& bitStr) {
    for (int i = 0; i < BITS_SIZE; i ++) {
        bits[i] = 0;
    }

    int index = 0;

    for (int i = bitStr.length() - 1; i >= 0 && index < BITS_SIZE; i --) {
        if (bitStr[i] == '0' || bitStr[i] == '1') {
            bits[index++] = bitStr[i] - '0';
        }
    }
}

void BitString :: print() const {
    bool leadingZero = true;

    for (int i = BITS_SIZE - 1; i >= 0; i --) {
        if (bits[i] != 0) {
            leadingZero = false;
        }
        if (!leadingZero) {
            cout << (int)bits[i];
        }
    }
    if (leadingZero) {
        cout << "0";
    }

    cout << endl;
}

int main() {
    cout << "----------Тестирование класса Decimal----------";

    Decimal dec1;
    cout << "Вывод экземпляра dec1 класса Decimal (конструктор по умолчанию):" << endl;
    dec1.print();

    Decimal dec2;
    dec2.setFromString("12345");
    cout << "Вывод экземпляра dec2 класса Decimal устанаилвая положительное значение 12345:" << endl;
    dec2.print();

    Decimal dec3;
    dec3.setFromString("-6789");
    cout << "Вывод экземпляра dec3 класса Decimal устанаилвая отрицательное значение -6789: " << endl;
    dec3.print();


    cout << "----------Тестирование класса BitString----------" << endl;

    BitString bit1;
    cout << "Вывод экземпляра bit1 класса BitString (конструктор по умолчанию):";
    bit1.print();

    BitString bit2;
    bit2.setFromString("10110");
    cout << "Вывод экземпляра bit2 класса BitString устанавливая значение 10110:" << endl;
    bit2.print();

    BitString bit3;
    bit3.setFromString("0000");
    cout << "Вывод экземпляра bit3 класса BitString устанавливая значение 0000 (ожидается вывод 0):" << endl;
    bit3.print();

    return 0;
}
