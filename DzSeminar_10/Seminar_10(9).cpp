#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    ofstream data("temperature_data.txt");
    data << "Sensor1 22.5" << endl;
    data << "Sensor2 21.8" << endl;
    data << "Sensor3 23.1" << endl;
    data << "Sensor1 22.7" << endl;
    data << "Sensor2 22.0" << endl;
    data << "Sensor3 23.3" << endl;
    data.close();
    cout << "Файл temperature_data.txt создан" << endl;

    // Считывание данных
    ifstream input("temperature_data.txt");

    // Переменные для хранения данных по каждому датчику
    const int n = 10;
    double sensor1[n], sensor2[n], sensor3[n];
    int count1 = 0, count2 = 0, count3 = 0;

    string name;
    double temp;

    // Читаем данные из файла
    while (input >> name >> temp) {
        if (name == "Sensor1") {
            sensor1[count1] = temp;
            count1++;
        }
        else if (name == "Sensor2") {
            sensor2[count2] = temp;
            count2++;
        }
        else if (name == "Sensor3") {
            sensor3[count3] = temp;
            count3++;
        }
    }
    input.close();

    ofstream report("report.txt");

    // Sensor1
    double min1 = sensor1[0], max1 = sensor1[0], sum1 = 0;
    for (int i = 0; i < count1; i++) {
        if (sensor1[i] < min1) min1 = sensor1[i];
        if (sensor1[i] > max1) max1 = sensor1[i];
        sum1 += sensor1[i];
    }
    double avg1 = sum1 / count1;
    report << "Sensor1: min = " << min1 << ", max = " << max1 << ", avg = " << avg1 << endl;

    // Sensor2
    double min2 = sensor2[0], max2 = sensor2[0], sum2 = 0;
    for (int i = 0; i < count2; i++) {
        if (sensor2[i] < min2) min2 = sensor2[i];
        if (sensor2[i] > max2) max2 = sensor2[i];
        sum2 += sensor2[i];
    }
    double avg2 = sum2 / count2;
    report << "Sensor2: min = " << min2 << ", max = " << max2 << ", avg = " << avg2 << endl;

    // Sensor3
    double min3 = sensor3[0], max3 = sensor3[0], sum3 = 0;
    for (int i = 0; i < count3; i++) {
        if (sensor3[i] < min3) min3 = sensor3[i];
        if (sensor3[i] > max3) max3 = sensor3[i];
            sum3 += sensor3[i];
    }
    double avg3 = sum3 / count3;
    report << "Sensor3: min = " << min3 << ", max = " << max3 << ", avg = " << avg3 << endl;

    report.close();
    cout << "Отчёт сохранён в report.txt" << endl;

    return 0;
}