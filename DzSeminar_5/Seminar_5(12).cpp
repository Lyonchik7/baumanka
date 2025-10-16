#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 50;
    vector<double> fuel_level(n);

    // Инициализация генератора случайных чисел
    srand(time(0));

    cout << "Уровень топлива в резервуаре:" << endl;
    for (int i = 0; i < n; i++) {
        fuel_level[i] = rand() % 501;
    }

    for_each(fuel_level.begin(), fuel_level.end(), [](double elements) {
        cout << elements << ", ";
        });
    cout << endl;

    // 1) Найти минимальный уровень топлива
    auto min = min_element(fuel_level.begin(), fuel_level.end());
    cout << "Минимальный уровень топлива: " << *min << " литров" << endl;

    // 2) Проверить, не падал ли уровень ниже 5% от максимального
    auto max = max_element(fuel_level.begin(), fuel_level.end());

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (fuel_level[i] < *max * 0.05) {
            count++;
        }
    }

    cout << "Уровень топлива падал ниже 5% от максимального: ";
    if (count > 0) {
        cout << "ДА (" << count << " раз)" << endl;
    }
    else {
        cout << "НЕТ" << endl;
    }

    // 3) Посчитать среднее потребление (разность начального и конечного значений) 
    vector<double> sorted_fuel = fuel_level;
    sort(sorted_fuel.begin(), sorted_fuel.end());

    cout << "\nОтсортированный вектор мощностей:" << endl;
    for_each(sorted_fuel.begin(), sorted_fuel.end(), [](double elements) {
        cout << elements << ", ";
        });
    cout << endl;

    double sredn = sorted_fuel[n-1] - sorted_fuel[0];
    cout << "Среднее потребление: " << sredn << " литров" << endl;

    // 4) Найти медиану
    double median = 0.0;
    int size = sorted_fuel.size();  // Используем реальный размер вектора

    double middle1 = sorted_fuel[size / 2 - 1];
    double middle2 = sorted_fuel[size / 2];
    median = (middle1 + middle2) / 2.0;

    cout << "Медиана: " << median << endl;

    return 0;
}

