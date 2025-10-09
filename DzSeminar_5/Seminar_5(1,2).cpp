#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // Задача 1
    
    const int n = 10;
    vector<int> vec1(n);

    int count = 1;
    cout << "Вектор из 10 чисел от 1 до 10" << endl;

    for_each(vec1.begin(), vec1.end(), [&count](int& element1) {
        element1 = count++;
        });

    for_each(vec1.begin(), vec1.end(), [](int element1) {
        cout << element1 << "  ";
        });
    cout << endl << endl;


    // Задача 2

    vector<int> vec2(n);
    
    cout << "Введите 10 элементов вектора (целые числа)" << endl;
    for_each(vec2.begin(), vec2.end(), [](int& element2) {
        cin >> element2;
        });
    
    for_each(vec2.begin(), vec2.end(), [](int& element2) {
        element2 = element2 * 2;
        });
    
    cout << "Удвоенный вектор" << endl;
    for_each(vec2.begin(), vec2.end(), [](int element2) {
        cout << element2 << "  ";
        });



    return 0;
}

