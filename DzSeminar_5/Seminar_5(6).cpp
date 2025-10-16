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

    // 1) Проверьте есть ли число 7
    cout << "\n\n1) ПРОВЕРКА НА НАЛИЧИЕ ЧИСЕЛ 7" << endl;
    auto it = vec.begin();
    int count = 0;

    while ((it = find(it, vec.end(), 7)) != vec.end()) {
        cout << "Число 7 найдено на позиции " << (it - vec.begin()) << endl;
        it++; // Переход к следующему элементу
        count++;
    }

    if (count == 0) {
        cout << "Число 7 не найдено в векторе" << endl;
    }
    else {
        cout << "Всего найдено чисел 7: " << count << endl;
    }

    // 2) Удалите все повторяющиеся числа (sort + unique)
    cout << "\n2) СОРТИРОВКА И УДАЛЕНИЕ ПОВТОРЯЮЩИХСЯ ЧИСЕЛ" << endl;

    vector<int> sorted_vec = vec; // Копия исходного вектора
    sort(sorted_vec.begin(), sorted_vec.end());

    cout << "Отсортированный вектор:" << endl;
    for_each(sorted_vec.begin(), sorted_vec.end(), [](int element) {
        cout << element << "  ";
        });
    
    auto last = unique(sorted_vec.begin(), sorted_vec.end());
    sorted_vec.erase(last, sorted_vec.end());

    cout << "\nНовый вектор" << endl;
    for_each(sorted_vec.begin(), sorted_vec.end(), [](int element) {
        cout << element << "  ";
        });

    return 0;
}

