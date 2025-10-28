#include <iostream>
using namespace std;

// Функция для транспонирования матрицы
int** transpose(int** matrix, int n, int m) {
    int** result = new int* [m];
    for (int i = 0; i < m; i++) {
        result[i] = new int[n];
    }

    // Заполняем транспонированную матрицу
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix[j][i];
        }
    }
    
    return result;
}


int main() {
    setlocale(LC_ALL, "RU");

    int n = 0, m = 0;
    cout << "Введите количество строк матрицы: ";
    cin >> n;
    cout << "Введите количество столбцов матрицы: ";
    cin >> m;

    // Создание исходной матрицы
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    // Заполнение матрицы пользователем
    cout << "\nВведите элементы матрицы " << n << "на" << m << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    // Вывод матрицы
    cout << "\nМатрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int** result = transpose(matrix, n, m);
    // Вывод отраженной матрицы
    cout << "\nОтраженная матрица:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
