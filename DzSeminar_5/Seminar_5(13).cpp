#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 50;
    vector<double> pressure(n);

    // Инициализация генератора случайных чисел
    srand(time(0));

    cout << "Давление в трубопроводе:" << endl;
    for (int i = 0; i < n; i++) {
        pressure[i] = 1 + (rand() % 1000) / 100.0; // значения от 1 до 10 бар
    }

    for_each(pressure.begin(), pressure.end(), [](double elements) {
        cout << elements << ", ";
        });
    cout << endl;

    // 1) Удаление ошибочных значений (< 0 или > 12)
    pressure.erase(remove_if(pressure.begin(), pressure.end(),
        [](double value) { return value < 0 || value > 12; }),
        pressure.end());

    cout << "\nДавление после удаления ошибочных значений:" << endl;
    for_each(pressure.begin(), pressure.end(), [](double elements) {
        cout << elements << ", ";
        });
    cout << endl;

    // 2) Вычисление среднего давления
    double average = accumulate(pressure.begin(), pressure.end(), 0.0) / pressure.size();
    cout << "Среднее давление: " << average << " бар" << endl;

    // 3)) Нахождение минимального и максимального давления
    auto minmax = minmax_element(pressure.begin(), pressure.end());
    cout << "Минимальное давление: " << *minmax.first << " бар" << endl;
    cout << "Максимальное давление: " << *minmax.second << " бар" << endl;

    // 4) Вывод значений, превышающих 8 бар
    cout << "\nЗначения, превышающие 8 бар:" << endl;
    for_each(pressure.begin(), pressure.end(), [](double value) {
        if (value > 8) {
            cout << value << ", ";
        }
        });

    return 0;
}
