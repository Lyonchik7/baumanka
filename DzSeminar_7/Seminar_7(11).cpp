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

    // Указатель на первый элемент 
    int* p = &vec[0];

    // Вычисляем сумму всех элементов через указатель
    int sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        sum += *(p + i);  
    }

    cout << "\nВведенный вектор: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }

    cout << "\nСумма всех элементов: " << sum << endl;

    return 0;
}