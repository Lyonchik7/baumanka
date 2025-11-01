#include <iostream>
#include <vector>

using namespace std;

void analyzePressure(const vector<double>& data, double& minVal, double& maxVal, double& avgVal) {
    const double* p = data.data();

    minVal = *p;
    maxVal = *p;
    double sum = 0.0;

    for (size_t i = 0; i < data.size(); ++i) {
        double current = *(p + i);  

        if (current < minVal) {
            minVal = current;
        }

        if (current > maxVal) {
            maxVal = current;
        }

        sum += current;
    }

    avgVal = sum / data.size();
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<double> pressure;
    int n = 0;
    cout << "Введите количество элементов в векторе: ";
    cin >> n;

    // Заполнение вектора 
    cout << "Введите " << n << " чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        double value;
        cout << "Элемент " << (i + 1) << ": ";
        cin >> value;
        pressure.push_back(value);
    }

    double minPressure, maxPressure, avgPressure;

    analyzePressure(pressure, minPressure, maxPressure, avgPressure);

    // Выводим результаты
    cout << "Min pressure: " << minPressure << endl;
    cout << "Max pressure: " << maxPressure << endl;
    cout << "Average pressure: " << avgPressure << endl;

    return 0;
}