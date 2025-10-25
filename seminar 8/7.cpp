#include <iostream>
using namespace std;

template<typename T>
int split(
    const T* arr,
    int size,
    const T& delimiter,
    const T** parts,
    int* part_sizes,
    int max_parts
) {
    if (size == 0 || max_parts == 0) {
        return 0;
    }

    int part_count = 0;
    int start = 0;

    for (int i = 0; i < size; i ++) {
        if (arr[i] == delimiter) {
            if (start < i && part_count < max_parts) {
                parts[part_count] = &arr[start];
                part_sizes[part_count] = i - start;
                part_count ++;
            }
            start = i + 1;
        }
    }

    if (start < size && part_count < max_parts) {
        parts[part_count] = &arr[start];
        part_sizes[part_count] = size - start;
        part_count ++;
    }

    return part_count;
}

int main() {
    int arr1[] = {1, 2, 0, 3, 4, 0, 5, 6, 7, 0, 0, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Исходный массив:" << endl;
    for (int i = 0; i < size1; i ++) {
        cout << arr1[i] << ' ';
    }
    cout << endl;

    const int* parts1[10];
    int sizes1[10];
    int count1 = split(arr1, size1, 0, parts1, sizes1, 10);

    cout << "Разделение массива целых чисел по 0:" << endl;
    for (int i = 0; i < count1; ++i) {
        cout << "Часть " << i << " (размер " << sizes1[i] << "): ";
        for (int j = 0; j < sizes1[i]; ++j) {
            cout << parts1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    char arr2[] = {'a', 'b', ',', 'c', 'd', ',', 'e', ',', ',', 'f', 'g'};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Исходный массив:" << endl;
    for (int i = 0; i < size2; i ++) {
        cout << arr2[i] << ' ';
    }
    cout << endl;

    const char* parts2[10];
    int sizes2[10];
    int count2 = split(arr2, size2, ',', parts2, sizes2, 10);

    cout << "Разделение массива символов по запятой:" << endl;
    for (int i = 0; i < count2; ++i) {
        cout << "Часть " << i << " (размер " << sizes2[i] << "): ";
        for (int j = 0; j < sizes2[i]; ++j) {
            cout << parts2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int empty[] = {};
    const int* parts3[5];
    int sizes3[5];
    int count3 = split(empty, 0, 0, parts3, sizes3, 5);
    cout << "Пустой массив: " << count3 << " частей\n";

    return 0;
}
