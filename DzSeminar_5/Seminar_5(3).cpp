#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    const int n = 20;
    vector<int> vec(n);
    
    cout << "Введите элементы вектора (20 целых чисел)" << endl;
    for_each(vec.begin(), vec.end(), [](int& element) {
        cin >> element;
        });

    cout << "Вектор:" << endl;
    for_each(vec.begin(), vec.end(), [](int element) {
        cout << element << "  ";
        });

    auto max1 = max_element(vec.begin(), vec.end());  // Первая более оптимизированная запись

    auto max2 = max_element(vec.begin(), vec.end(),  // Вторая запись
        [](int a, int b) {
            return a < b;  
        }
    );

    cout << "\nМаксимум: " << *max1 << endl;
    cout << "\nМаксимум: " << *max2;

    return 0;
}

