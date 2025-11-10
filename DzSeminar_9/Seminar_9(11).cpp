#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int N;
    cout << "N: ";
    cin >> N;

    vector<double> signals(N);
    for (int i = 0; i < N; i++) cin >> signals[i];

    auto arr = make_unique<double[]>(N);
    for (int i = 0; i < N; i++) arr[i] = signals[i];

    // Среднее
    double sum = 0;
    for (int i = 0; i < N; i++) sum += arr[i];
    cout << "Среднее: " << sum / N << endl;

    // Максимум для нормализации
    double maxVal = arr[0];
    for (int i = 1; i < N; i++)
        if (arr[i] > maxVal) maxVal = arr[i];

    // Нормализация
    for (int i = 0; i < N; i++)
        arr[i] /= maxVal;

    cout << "Нормализованные: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    return 0;
}