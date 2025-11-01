#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    vector<int> vec;
    int n = 0;

    cout << "Введите количество элементов в векторе: ";
    cin >> n;

    // Заполнение вектора 
    cout << "Введите " << n << " целых чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Элемент " << (i + 1) << ": ";
        cin >> value;
        vec.push_back(value);
    }

    cout << "\nВведенный вектор: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    
    // Указатель на первый элемент 
    int* p = vec.data();

    for (size_t i = 0; i < vec.size(); ++i) {
        *(p + i) += 10;  
    }

    cout << "\nВектор после увеличения на 10: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}

