#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    ofstream data("vibration_log.txt");
    data << "0.02 0.05 0.03 0.10 0.09 0.07 0.15 0.04" << endl;
    data.close();
    cout << "Файл vibration_log.txt создан" << endl;

    // 1. Считываем все значения амплитуды из файла
    ifstream input("vibration_log.txt");
    vector<double> amplitudes;

    double value;
    while (input >> value) {
        amplitudes.push_back(value);
    }
    input.close();

    // 2. Анализ данных с лямбда-функциями
    vector<double> filteredAmplitudes;

    auto filterFunc = [&filteredAmplitudes](const vector<double>& amps) {
        for (int i = 0; i < amps.size(); i++) {
            if (amps[i] > 0.05) {
                filteredAmplitudes.push_back(amps[i]);
            }
        }
        };

    filterFunc(amplitudes);

    // Вычисление среднего значения с лямбдой
    auto averageFunc = [](const vector<double>& amps) {
        double total = 0;
        for (int i = 0; i < amps.size(); i++) {
            total += amps[i];
        }
        return total / amps.size();
        };

    double averageAmplitude = averageFunc(amplitudes);

    auto maxFunc = [](const vector<double>& amps) {
        double maxVal = amps[0];
        for (int i = 1; i < amps.size(); i++) {
            if (amps[i] > maxVal) maxVal = amps[i];
        }
        return maxVal;
        };

    double maxAmplitude = maxFunc(amplitudes);

    auto minFunc = [](const vector<double>& amps) {
        double minVal = amps[0];
        for (int i = 1; i < amps.size(); i++) {
            if (amps[i] < minVal) minVal = amps[i];
        }
        return minVal;
        };

    double minAmplitude = minFunc(amplitudes);

    // 3. Сохраняем результаты анализа
    ofstream report("vibration_report.txt");

    report << "Количество измерений: " << amplitudes.size() << endl;
    report << "Фильтрованные значения (>0.05): ";

    auto printFunc = [&report](const vector<double>& values) {
        for (int i = 0; i < values.size(); i++) {
            report << values[i] << " ";
        }
        };

    printFunc(filteredAmplitudes);
    report << endl;

    report << "Среднее значение: " << averageAmplitude << endl;
    report << "Минимум: " << minAmplitude << endl;
    report << "Максимум: " << maxAmplitude << endl;

    report.close();

    cout << "Анализ вибрационных данных завершён. Отчёт сохранён в vibration_report.txt" << endl;

    return 0;
}