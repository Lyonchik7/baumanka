#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int N, T;

    cout << "Введите количество узлов и интервалов: ";
    cin >> N >> T;

    // Создаем и заполняем матрицу
    int** load = new int* [N];
    for (int i = 0; i < N; i++) {
        load[i] = new int[T];
        cout << "Узел " << i << ": ";
        for (int j = 0; j < T; j++) {
            cin >> load[i][j];
        }
    }

    // Анализ нагрузки
    cout << "\nАнализ нагрузки:" << endl;

    for (int j = 0; j < T; j++) {
        int max_load = 0, min_load = 100, total = 0;

        for (int i = 0; i < N; i++) {
            if (load[i][j] > max_load) max_load = load[i][j];
            if (load[i][j] < min_load) min_load = load[i][j];
            total += load[i][j];
        }

        cout << "Интервал " << j << ": max=" << max_load << "%, min="
            << min_load << "%, средняя=" << total / N << "%" << endl;
    }

    // Очистка памяти
    for (int i = 0; i < N; i++) {
        delete[] load[i];
    }
    delete[] load;

    return 0;
}