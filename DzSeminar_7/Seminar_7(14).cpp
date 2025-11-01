#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double computeRMS(const vector<double>& signal) {
    const double* p = signal.data();

    // Вычисляем сумму квадратов элементов
    double sum_of_squares = 0.0;
    for (size_t i = 0; i < signal.size(); ++i) {
        sum_of_squares += *(p + i) * *(p + i);
    }

    // Вычисляем RMS по формуле: sqrt( (1/N) * sum(x_i^2) )
    double rms = sqrt(sum_of_squares / signal.size());

    return rms;
}

int main() {
    setlocale(LC_ALL, "RU");
    
    vector<double> signal;
    int n = 0;
    cout << "Введите количество элементов в векторе: ";
    cin >> n;

    // Заполнение вектора 
    cout << "Введите " << n << " чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        double value;
        cout << "Элемент " << (i + 1) << ": ";
        cin >> value;
        signal.push_back(value);
    }

    double rms = computeRMS(signal);
    cout << "RMS value: " << rms << endl;

    return 0;
}