#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Создаем матрицу весов
double** createWeights(int n, int m) {
    double** weights = new double* [n];
    for (int i = 0; i < n; i++) {
        weights[i] = new double[m];
    }
    return weights;
}

// Заполняем случайными весами от -1 до 1
void initWeights(double** weights, int n, int m) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            weights[i][j] = (rand() % 2001 - 1000) / 1000.0;
        }
    }
}

// Очищаем память
void freeWeights(double** weights, int n) {
    for (int i = 0; i < n; i++) {
        delete[] weights[i];
    }
    delete[] weights;
}

// Прямой проход через слой
double* forward(double** weights, double* inputs, int n, int m) {
    double* outputs = new double[n];

    for (int i = 0; i < n; i++) {
        outputs[i] = 0;
        for (int j = 0; j < m; j++) {
            outputs[i] += weights[i][j] * inputs[j];
        }
    }

    return outputs;
}

int main() {
    setlocale(LC_ALL, "RU");
    int N = 3; // нейронов
    int M = 4; // входов

    // Создаем веса
    double** weights = createWeights(N, M);
    initWeights(weights, N, M);

    // Создаем входы
    double* inputs = new double[M];
    cout << "Введите " << M << " входных значения: ";
    for (int i = 0; i < M; i++) {
        cin >> inputs[i];
    }

    // Вычисляем выходы
    double* outputs = forward(weights, inputs, N, M);

    // Выводим результаты
    cout << "\nВеса:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << weights[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nВыходы нейронов:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Нейрон " << i << ": " << outputs[i] << endl;
    }

    // Очищаем память
    delete[] inputs;
    delete[] outputs;
    freeWeights(weights, N);

    return 0;
}