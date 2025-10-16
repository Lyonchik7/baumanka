#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 50;
    vector<double> amplitude(n);

    // Инициализация генератора случайных чисел
    srand(time(0));

    cout << "Амплитуды вибрации:" << endl;
    for (int i = 0; i < n; i++) {
        amplitude[i] = (rand() % 1000) / 1000.0; // значения от 0 до 1
    }

    for_each(amplitude.begin(), amplitude.end(), [](double elements) {
        cout << elements << ", ";
        });
    cout << endl;

    // 1) Удаление шумов (значения < 0.1)
    amplitude.erase(remove_if(amplitude.begin(), amplitude.end(),
        [](double value) { return value < 0.1; }),
        amplitude.end());

    cout << "\nАмплитуды после удаления шумов:" << endl;
    for_each(amplitude.begin(), amplitude.end(), [](double elements) {
        cout << elements << ", ";
        });
    cout << endl;

    // 2) Нахождение среднего b максимального значениq амплитуды
    double sum = accumulate(amplitude.begin(), amplitude.end(), 0.0);
    double sredn = sum / amplitude.size();
    cout << "\nСреднее значение амплитуды: " << sredn << endl;
        
    auto max = max_element(amplitude.begin(), amplitude.end());
    cout << "\nМаксимальное значение амплитуды: " << *max << endl;

    // 3) Проверка, превышают ли все значения порог 0.5
    bool all_more = all_of(amplitude.begin(), amplitude.end(),
        [](double value) { return value > 0.5; });
    if (all_more) {
        cout << "\nВсе значения превышают порог 0.5: ДА";
    }
    else {
        cout << "\nВсе значения превышают порог 0.5: НЕТ";
    }

    // 4) Вывод 10 наибольших амплитуд для анализа
    vector<double> sorted_amplitude = amplitude;
    sort(sorted_amplitude.begin(), sorted_amplitude.end(), greater<int>());   // greater<int>() сортирует по убыванию

    cout << "\n10 максимальных скоростей:" << endl;
    for (int i = 0; i < 10 && i < sorted_amplitude.size(); i++) {
        cout << sorted_amplitude[i] << " ";
    }
    cout << endl;

    return 0;
}