#include <iostream>
#include <iomanip>

using namespace std;

double** allocatePlate(int n, int m) {
    double** plate = new double* [n];
    for (int i = 0; i < n; i++) {
        plate[i] = new double[m];
    }
    return plate;
}

void freePlate(double** plate, int n) {
    for (int i = 0; i < n; i++) {
        delete[] plate[i];
    }
    delete[] plate;
}

void updateTemperature(double** plate, int n, int m) {
    // Создаем новую пластину для обновленных температур
    double** newPlate = allocatePlate(n, m);

    int center_i = n / 2;
    int center_j = m / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == center_i && j == center_j) {
                // Нагреватель - фиксированная температура
                newPlate[i][j] = 100.0;
            }
            else if (i > 0 && i < n - 1 && j > 0 && j < m - 1) {
                // Внутренние точки - среднее соседей
                double sum = plate[i - 1][j] + plate[i + 1][j] +
                    plate[i][j - 1] + plate[i][j + 1];
                newPlate[i][j] = sum / 4.0;
            }
            else {
                // Граничные точки - остаются без изменения
                newPlate[i][j] = plate[i][j];
            }
        }
    }

    // Копируем обратно и освобождаем временную память
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            plate[i][j] = newPlate[i][j];
        }
    }
    freePlate(newPlate, n);
}

int main() {
    setlocale(LC_ALL, "RU");
    int N = 5, M = 5, K = 3;

    double** plate = allocatePlate(N, M);

    // Инициализация
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            plate[i][j] = 20.0;
        }
    }
    plate[N / 2][M / 2] = 100.0;  // Нагреватель в центре

    // Итерации
    for (int iter = 0; iter < K; iter++) {
        updateTemperature(plate, N, M);
    }

    // Вывод результата
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(6) << plate[i][j] << " ";
        }
        cout << endl;
    }

    freePlate(plate, N);
    return 0;
}