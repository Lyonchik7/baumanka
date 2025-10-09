#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int N = 0;
    double matrix[50][50];

    cout << "Введите порядок матрицы\n";
    cin >> N;

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    // Вывод матрицы
    cout << "\nМатрица" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Вычисляем сумму первой строки (остальные суммы будем сравнивать с ней)
    int fixSum = 0;
    for (int j = 0; j < N; j++) {
        fixSum += matrix[0][j];
    }

    // Проверим суммы всех строк
    for (int i = 1; i < N; i++) {
        int lineSum = 0;
        for (int j = 0; j < N; j++) {
            lineSum += matrix[i][j];
        }
        if (lineSum != fixSum) {
            cout << "NO" << endl;
        }
    }

    // Проверим суммы всех столбцов
    for (int j = 0; j < N; j++) {
        int colSum = 0;
        for (int i = 0; i < N; i++) {
            colSum += matrix[i][j];
        }
        if (colSum != fixSum) {
            cout << "NO" << endl;
        }
    }

    // Проверим сумму элементов главной диагонали
    int maindiagSum = 0;
    for (int i = 0; i < N; i++) {
        maindiagSum += matrix[i][i];
    }
    if (maindiagSum != fixSum) {
        cout << "NO" << endl;
    }

    // Проверим сумму элементов побочной диагонали
    int sidediagSum = 0;
    for (int i = 0; i < N; i++) {
        sidediagSum += matrix[i][N - 1 - i];
    }
    if (sidediagSum != fixSum) {
        cout << "NO" << endl;

    }


    // Если все проверки пройдены
    cout << "YES " << fixSum << endl;

    return 0;
}
