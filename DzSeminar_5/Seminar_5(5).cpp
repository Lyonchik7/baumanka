#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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
    
    // 1) Поиск минимума и максимума
   
    auto max = max_element(vec.begin(), vec.end());
    auto min = min_element(vec.begin(), vec.end());
    cout << "\nМаксимальный элемент:" << *max << endl;
    cout << "Минимальный элемент:" << *min << endl;

    // 2) Посчитайте среднее значение
    
    auto sum = accumulate(vec.begin(), vec.end(), 0) / n;
    cout << "Среднее:" << sum << endl;

    // 3) Найдите медиану (сортировка и выбор середины)
    
    vector<int> sorted_vec = vec; // Копия исходного вектора
    sort(sorted_vec.begin(), sorted_vec.end());

    cout << "\nОтсортированный вектор:" << endl;
    for_each(sorted_vec.begin(), sorted_vec.end(), [](int element) {
        cout << element << "  ";
        });

    int median = 0;
    int middle1 = sorted_vec[n / 2 - 1];  // Первый центральный элемент
    int middle2 = sorted_vec[n / 2];      // Второй центральный элемент
    median = (middle1 + middle2) / 2.0;   // Среднее арифметическое

    cout << "\nМедиана:" << median;

    return 0;
}

