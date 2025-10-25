#include <iostream>
using namespace std;

template <typename T> bool compare(const T& first, const T& second) {
    return first == second;
}

int main() {
    int x = 5, y = 5, z = 10;
    cout << "compare(5, 5)  = " << compare(x, y) << endl;
    cout << "compare(5, 10) = " << compare(x, z) << endl;

    double d1 = 3.14, d2 = 3.14, d3 = 2.71;
    cout << "compare(3.14, 3.14) = " << compare(d1, d2) << endl;
    cout << "compare(3.14, 2.71) = " << compare(d1, d3) << endl;

    char c1 = 'A', c2 = 'A', c3 = 'B';
    cout << "compare('A', 'A') = " << compare(c1, c2) << endl;
    cout << "compare('A', 'B') = " << compare(c1, c3) << endl;

    const char* s1 = "hello";
    const char* s2 = "hello";
    const char* s3 = "world";
    cout << "compare(hello, hello) = " << compare(s1, s2) << endl;
    cout << "compare(hello, world) = " << compare(s1, s3) << endl;

    bool b1 = true, b2 = true, b3 = false;
    cout << "compare(true, true)  = " << compare(b1, b2) << endl; 
    cout << "compare(true, false) = " << compare(b1, b3) << endl;

    return 0;
}