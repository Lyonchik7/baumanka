#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 20;
    vector<double> temp(n);

    cout << "Введите температуры (вектор 20 чисел)" << endl;
    for_each(temp.begin(), temp.end(), [](double& element) {
        cin >> element;
        });

    cout << "Вектор:" << endl;
    for_each(temp.begin(), temp.end(), [](double element) {
        cout << element << "  ";
        });

    // 1) Удаление всех значений вне диапазона [-50;50]

    auto condition = [](double x) {   // Условие, задающее интервал [-50;50]
        return x <= -50 || x >= 50;
        };

    temp.erase(remove_if(temp.begin(), temp.end(), condition), temp.end()); // Удаление по условию

    cout << "\n Вектор внутри диапазона [-50;50]:" << endl;
    for_each(temp.begin(), temp.end(), [](double element) {
        cout << element << "  ";
        });


    // 2) Поиск минимума и максимума

    auto max = max_element(temp.begin(), temp.end());
    auto min = min_element(temp.begin(), temp.end());
    cout << "\nМаксимальная температура:" << *max << endl;
    cout << "Минимальный температура:" << *min << endl;

    // 3) Посчитайте среднее значение

    double sum = accumulate(temp.begin(), temp.end(), 0) / temp.size();
    cout << "Средняя температура:" << sum << endl;

    // 4) Проверка, превышают ли все температуры -10 градусов

    auto check_temp = find_if(temp.begin(), temp.end(), [](double x) {
        return x <= -10;
        });

    if (check_temp == temp.end()) {
        cout << "Все температуры превышают -10 градусов" << endl;
    }
    else {
        cout << "Не все температуры превышают -10 градусов" << endl;
    }


    return 0;
}

