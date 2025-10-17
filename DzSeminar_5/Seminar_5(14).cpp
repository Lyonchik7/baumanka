#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 24;
    vector<double> energy(n);

    // Инициализация генератора случайных чисел
    srand(time(0));

    cout << "Энергопотребление за сутки (каждый час - 24 значения):" << endl;
    for (int i = 0; i < n; i++) {
        energy[i] = (rand() % 401) + 100; // значения 100–500 кВт·ч
    }

    for_each(energy.begin(), energy.end(), [](double elements) {
        cout << elements << ", ";
        });
    cout << endl;

    // 1) Вычислить суммарное и среднее потребление(accumulate)
    double sum = accumulate(energy.begin(), energy.end(), 0.0);
    double sredn = sum / energy.size();
    cout << "Суммарное потребление: " << sum << " кВт*ч" << endl;
    cout << "Среднее потребление: " << sredn << " кВт*ч" << endl;

    // 2) Найти часы пикового потребления(max_element)
    auto max = max_element(energy.begin(), energy.end());
    cout << "Максимальное потребление: " << *max << " кВт*ч" << endl;

    // 3) Применить transform и лямбду для расчёта отклонения каждого часа от среднего
    vector<double> difference(n);
    transform(energy.begin(), energy.end(), difference.begin(),
        [sredn](double hour_energy) {
            return hour_energy - sredn;
        });

    cout << "\nОтклонения от среднего потребления по часам:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Час " << i + 1 << ": " << energy[i] << " кВт*ч, отклонение: "
            << difference[i] << " кВт*ч ("
            << (difference[i] > 0 ? "+" : "") << difference[i] << ")" << endl;
    }

    // 4) Отсортировать значения по возрастанию (sort) и вывести топ-5 минимальных часов потребления
    vector<double> sorted_energy = energy;
    sort(sorted_energy.begin(), sorted_energy.end());
        
    cout << "\nТоп-5 минимальных значений потребления:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << "-е место: " << sorted_energy[i] << " кВт*ч" << endl;
    }

    // Дополнительно: найти какие именно часы имеют минимальное потребление
    cout << "\nЧасы с минимальным потреблением:" << endl;
    vector<int> hours(n);
    iota(hours.begin(), hours.end(), 1); // заполнение вектора [1, 2, 3, ..., 24]

    // Сортируем индексы часов по потреблению
    sort(hours.begin(), hours.end(), [&energy](int a, int b) {
        return energy[a - 1] < energy[b - 1];                  // Сравниваются не сами элементы вектора hours, а соответствующие им значения из вектора      
        });

    for (int i = 0; i < 5 && i < hours.size(); i++) {
        int hour = hours[i];
        cout << i + 1 << "-е место: " << hour << "-й час - " << energy[hour - 1] << " кВт*ч" << endl;
    }


    return 0;
}

