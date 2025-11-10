#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int N, M;

    cout << "Введите размеры матрицы N и M: ";
    cin >> N >> M;

    // Создание матрицы
    auto matrix = make_unique<double[]>(N * M);

    // Ввод данных
    cout << "Введите " << N * M << " элементов матрицы:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Строка " << (i + 1) << ": ";
        for (int j = 0; j < M; j++) {
            cin >> matrix[i * M + j];
        }
    }

    // Вывод введенной матрицы
    cout << "\nВведенная матрица:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(8) << matrix[i * M + j] << " ";
        }
        cout << endl;
    }

    // Лямбда для суммирования столбцов
    auto calculateColumnSums = [N, M](const unique_ptr<double[]>& mat) {
        vector<double> sums(M, 0.0);
        for (int j = 0; j < M; j++) {
            double sum = 0.0;
            for (int i = 0; i < N; i++) {
                sum += mat[i * M + j];
            }
            sums[j] = sum;
        }
        return sums;
        };

    // Лямбда для поиска индекса максимума
    auto findMaxColumnIndex = [](const vector<double>& sums) {
        auto max_it = max_element(sums.begin(), sums.end());
        return distance(sums.begin(), max_it);
        };

    // Вычисления
    auto columnSums = calculateColumnSums(matrix);
    int bestColumn = findMaxColumnIndex(columnSums);

    // Вывод результатов
    cout << "\nАнализ матрицы:" << endl;
    cout << "Суммы по столбцам: ";
    for (size_t i = 0; i < columnSums.size(); i++) {
        cout << "Столбец " << (i + 1) << ": " << columnSums[i];
        if (i < columnSums.size() - 1) cout << ", ";
    }
    cout << endl;

    cout << "Столбец с максимальной суммой: " << (bestColumn + 1)
        << " (сумма = " << columnSums[bestColumn] << ")" << endl;

    return 0;
}