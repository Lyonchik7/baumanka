#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // Создаём тестовый файл с данными
    ofstream data("power_log.txt");
    data << "2025-11-09T08:00:00 MotorA 1.25" << endl;
    data << "2025-11-09T08:00:00 PumpB 0.95" << endl;
    data << "2025-11-09T08:30:00 MotorA 1.40" << endl;
    data << "2025-11-09T08:30:00 PumpB 0.90" << endl;
    data << "2025-11-09T09:00:00 MotorA 1.35" << endl;
    data.close();
    cout << "Файл power_log.txt создан" << endl;

    // 1. Считываем файл
    ifstream input("power_log.txt");

    // 2. Группируем данные по устройствам с помощью vector
    vector<double> motorA;
    vector<double> pumpB;

    string line;

    while (getline(input, line)) {
        size_t firstSpace = line.find(' ');
        size_t secondSpace = line.find(' ', firstSpace + 1);

        string deviceName = line.substr(firstSpace + 1, secondSpace - firstSpace - 1);
        double power = stod(line.substr(secondSpace + 1));

        if (deviceName == "MotorA") {
            motorA.push_back(power);
        }
        else if (deviceName == "PumpB") {
            pumpB.push_back(power);
        }
    }
    input.close();

    // 3. Вычисляем статистику и создаём отчёт
    ofstream report("energy_report.txt");

    // MotorA
    if (!motorA.empty()) {
        double totalA = 0;
        for (double power : motorA) {
            totalA += power;
        }
        double avgA = totalA / motorA.size();
        report << "MotorA: measurements = " << motorA.size()
            << ", total = " << totalA << " kWh"
            << ", average = " << avgA << " kW" << endl;
    }

    // PumpB
    if (!pumpB.empty()) {
        double totalB = 0;
        for (double power : pumpB) {
            totalB += power;
        }
        double avgB = totalB / pumpB.size();
        report << "PumpB: measurements = " << pumpB.size()
            << ", total = " << totalB << " kWh"
            << ", average = " << avgB << " kW" << endl;
    }

    report.close();
    cout << "Анализ завершён. Результаты сохранены в energy_report.txt" << endl;

    return 0;
}