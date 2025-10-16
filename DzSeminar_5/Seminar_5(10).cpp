#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    const int n = 30;
    vector<double> energy(n);

    // Инициализация генератора случайных чисел
    srand(time(0));

    cout << "Потребление энергии за месяц (с первого дня по тридцатый слева направо)" << endl;
    // Заполнение вектора случайными мощностями
    for (int i = 0; i < n; i++) {
        energy[i] = rand() % 101;
    }

    for_each(energy.begin(), energy.end(), [](int elements) {
        cout << elements << " ";
        });
    cout << endl;

    // 1) Найти общее потребление за месяц (accumulate)
    double sum = accumulate(energy.begin(), energy.end(), 0);
    cout << "Общее потребление за месяц:" << sum << " кВт*ч " << endl;

    // 2) Определитm среднесуточное значение
    double sredn = sum / energy.size();
    cout << "Среднесуточное потребление:" << sredn << " кВт*ч " << endl;

    // 3) Найтти дни с максимальным и минимальным потреблением
    auto max = max_element(energy.begin(), energy.end());
    auto min = min_element(energy.begin(), energy.end());
    cout << "Максимальное потребление: " << *max << " кВт*ч " << endl;
    cout << "Максимальное потребление было в " << (max - energy.begin()) << " день" << endl;
    cout << "Минимальное потребление: " << *min << " кВт*ч " << endl;
    cout << "Минимальное потребление было в " << (min - energy.begin()) << " день" << endl;
   
    // 4) Отфильтровать «пиковые» дни(значение > среднего на 20 %)
    cout << "Пиковые дни: ";
    for (int i = 0; i < n; i++) {
        if (energy[i] > sredn * 1.2) {
            cout << " день" << (i + 1) << "  ";
        }
    }

    return 0;
}

