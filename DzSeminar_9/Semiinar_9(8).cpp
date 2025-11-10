#include <iostream>
#include <memory>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    const int N = 3;

    // 1) Массив температур
    unique_ptr<double[]> temp = make_unique<double[]>(N);
    
    cout << "Введите " << N << " значения температур:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> temp[i];
    }

    double sum_temp = 0.0;
    cout << "Массив температур: ";
    for (int i = 0; i < N; i++) {
        cout << temp[i] << "  ";
        sum_temp += temp[i];
    }
    double sredn_temp = sum_temp / N;
    cout << "\nСредняя температура: " << sredn_temp << endl;

    // 2) Массив давлений
    unique_ptr<double[]> davl = make_unique<double[]>(N);

    cout << "\nВведите " << N << " значения давления:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> davl[i];
    }

    double sum_davl = 0.0;
    cout << "\nМассив давлений: ";
    for (int i = 0; i < N; i++) {
        cout << davl[i] << "  ";
        sum_davl += davl[i];
    }
    double sredn_davl = sum_davl / N;
    cout << "\nСреднее давление: " << sredn_davl << endl;

    // 3) Массив влажности
    unique_ptr<double[]> vlag = make_unique<double[]>(N);

    cout << "\nВведите " << N << " значений влажностей:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> vlag[i];
    }

    double sum_vlag = 0.0;
    cout << "\nМассив влажностей: ";
    for (int i = 0; i < N; i++) {
        cout << vlag[i] << "  ";
        sum_vlag += vlag[i];
    }
    double sredn_vlag = sum_vlag / N;
    cout << "\nСредняя влажность: " << sredn_vlag << endl;


    return 0;
}

