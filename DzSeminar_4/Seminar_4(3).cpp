#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    cout << "Введите количество строк, а затем количество столбцов:";
    int N, M, matrix[100][100];
    cin >> N >> M;

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // Вывод матрицы
    cout << "Матрица:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int v = matrix[i][j];
            int min_row = 1, max_row = 1, min_col = 1, max_col = 1;

            // Проверяем строку
            for (int k = 0; k < M; k++) {
                if (matrix[i][k] < v) min_row = 0;
                if (matrix[i][k] > v) max_row = 0;
            }

            // Проверяем столбец
            for (int k = 0; k < N; k++) {
                if (matrix[k][j] > v) max_col = 0;
                if (matrix[k][j] < v) min_col = 0;
            }

            if (min_row && max_col) {
                cout << "A " << v << " " << i + 1 << " " << j + 1 << endl;
                count++;
            }
            if (max_row && min_col) {
                cout << "B " << v << " " << i + 1 << " " << j + 1 << endl;
                count++;
            }
        }
    }

    if (count == 0) cout << "NONE";

    return 0;
}