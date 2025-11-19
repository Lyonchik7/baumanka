#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    cout << "=== ОБРАБОТКА ДАННЫХ С ДАТЧИКОВ ===" << endl;

    // Чтение данных
    ifstream file("sensor_data.txt");
    vector<double> temps;
    double temp;

    while (file >> temp) {
        temps.push_back(temp);
    }
    file.close();

    cout << "Прочитано значений: " << temps.size() << endl;

    // Фильтрация с лямбда-функцией
    vector<double> filtered;
    auto validTemp = [](double t) { return t >= -50 && t <= 50; };

    copy_if(temps.begin(), temps.end(), back_inserter(filtered), validTemp);

    cout << "После фильтрации: " << filtered.size() << endl;

    // Вычисление средней температуры
    if (!filtered.empty()) {
        double sum = accumulate(filtered.begin(), filtered.end(), 0.0);
        double average = sum / filtered.size();
        cout << "Средняя температура: " << fixed << setprecision(2) << average << "°C" << endl;
    }

    // Сохранение результатов
    ofstream out("filtered_data.txt");
    for (double t : filtered) {
        out << fixed << setprecision(1) << t << endl;
    }
    out.close();

    cout << "Данные сохранены в filtered_data.txt" << endl;

    return 0;
}