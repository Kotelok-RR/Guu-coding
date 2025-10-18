#include <iostream>
#include <string>
using namespace std;

struct FazzyNumber {
    double x;
    double e1;
    double e2;
    FazzyNumber(double x_val = 0, double e1_val = 0, double e2_val = 0);
};

FazzyNumber :: FazzyNumber(double x_val, double e1_val, double e2_val) {
    x = x_val;
    e1 = e1_val;
    e2 = e2_val;
}

class FuzzyDivisionErrorParams {
public:
    string message;
    double b_center;
    FuzzyDivisionErrorParams(const string& msg, double b);
};

class FuzzyDivisionErrorInherited : public runtime_error {
public:
    double b_center;
    FuzzyDivisionErrorInherited(const std::string& msg, double b);
};

class FuzzyDivisionErrorEmpty {};

FuzzyDivisionErrorParams :: FuzzyDivisionErrorParams(const string& msg, double b) {
    message = msg;
    b_center = b;
}

FuzzyDivisionErrorInherited :: FuzzyDivisionErrorInherited(const string& msg, double b) : runtime_error(msg), b_center(b) {}

void validateFazzyNumber(const FazzyNumber& num, const string& name) {
    if (num.e1 < 0 || num.e2 < 0) {
        throw invalid_argument(name + " имеет отрицательные отклонения");
    }
}

FazzyNumber divideFuzzyNoSpec(const FazzyNumber& a, const FazzyNumber& b) {
    validateFazzyNumber(a, "A");
    validateFazzyNumber(b, "B");

    if (b.x <= 0) {
        runtime_error("Деление на ноль: центр B <= 0");
    }

    return FazzyNumber(
        (a.x - a.e1) / (b.x + b.e2),
        a.x / b.x,
        (a.x + a.e2) / (b.x - b.e1)
    );
}

FazzyNumber divideFuzzyEmptyThrow(const FazzyNumber& a, const FazzyNumber& b) throw() {
    try {
        validateFazzyNumber(a, "A");
        validateFazzyNumber(b, "B");
        
        if (b.x <= 0) {
            throw runtime_error("Деление на ноль: центр B <= 0");
        }

        return FazzyNumber(
            (a.x - a.e1) / (b.x + b.e2),
            a.x / b.x,
            (a.x + a.e2) / (b.x - b.e1)
        );
    } catch (...) {
        return FazzyNumber();
    }
}

FazzyNumber divideFuzzySpecificThrow(const FazzyNumber& a, const FazzyNumber& b) noexcept(false) {
    validateFazzyNumber(a, "A");
    validateFazzyNumber(b, "B");

    if (b.x <= 0) {
        throw runtime_error("Деление на ноль: центр B <= 0");
    }

    return FazzyNumber(
        (a.x - a.e1) / (b.x + b.e2),
        a.x / b.x,
        (a.x + a.e2) / (b.x - b.e1)
    );
}

FazzyNumber divideFuzzyCustomThrow(const FazzyNumber& a, const FazzyNumber& b) {
    validateFazzyNumber(a, "A");
    validateFazzyNumber(b, "B");
    
    if (b.x <= 0) {
        throw FuzzyDivisionErrorInherited("Деление на ноль: центр B <= 0", b.x);
    }
    
    return FazzyNumber(
        (a.x - a.e1) / (b.x + b.e2),
        a.x / b.x,
        (a.x + a.e2) / (b.x - b.e1)
    );
}

int main() {
    FazzyNumber a(10, 2, 3);
    FazzyNumber b(5, 1, 1);
    FazzyNumber b_zero(0, 1, 1);
    FazzyNumber a_invalid(10, -2, 3);

    cout << "Тестирование функции без спецификации исключений: " << endl;
    try {
        FazzyNumber result = divideFuzzyNoSpec(a, b);
        cout << "Результат: (" << result.x - result.e1 << ", " << result.x << ", " << result.x + result.e2 << ")" << endl;
        divideFuzzyNoSpec(a, b_zero);
    } catch (const invalid_argument& e) {
        cout << "Ошибка параметров: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Ошибка выполнения: " << e.what() << endl;
    } catch (...) {
        cout << "Неизвестная ошибка" << endl;
    }

    cout << endl << "Тестирование функции с throw():" << endl;
    try {
        FazzyNumber result = divideFuzzyEmptyThrow(a, b);
        cout << "Результат: (" << result.x - result.e1 << ", " << result.x << ", " << result.x + result.e2 << ")" << endl;
        divideFuzzyEmptyThrow(a, b_zero);
    } catch (...) {
        cout << "Перехвачена ошибка (throw())" << endl;
    }

    cout << endl << "Тестирование функции с конкретной спецификацией:" << endl;
    try {
        FazzyNumber result = divideFuzzySpecificThrow(a, b);
        cout << "Результат: (" << result.x - result.e1 << ", " << result.x << ", " << result.x + result.e2 << ")" << endl;
        divideFuzzySpecificThrow(a, b_zero);
    } catch (const invalid_argument& e) {
        cout << "Ошибка параметров: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Ошибка выполнения: " << e.what() << endl;
    }

    cout << endl << "Тестирование функции с пользовательским исключением:" << endl;
    try {
        FazzyNumber result = divideFuzzyCustomThrow(a, b);
        cout << "Результат: (" << result.x - result.e1 << ", " << result.x << ", " << result.x + result.e2 << ")" << endl;
        divideFuzzyCustomThrow(a, b_zero);
    } catch (const FuzzyDivisionErrorEmpty&) {
        cout << "Пустое пользовательское исключение" << endl;
    } catch (const FuzzyDivisionErrorParams& e) {
        cout << "Пользовательское исключение с параметрами: " << e.message << ", B центр = " << e.b_center << endl;
    } catch (const FuzzyDivisionErrorInherited& e) {
        cout << "Наследуемое пользовательское исключение: " << e.what() << ", B центр = " << e.b_center << endl;
    } catch (const invalid_argument& e) {
        cout << "Ошибка параметров: " << e.what() << endl;
    }

    return 0;
}