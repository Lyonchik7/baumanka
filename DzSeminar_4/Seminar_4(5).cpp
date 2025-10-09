#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "RU");

    int N = 0, M = 0;

    int matrix[50][50];
    int result[2500]; // 50*50

    cout << "Введите количество строк\n";
    cin >> N;
    cout << "Введите количество столбцов\n";
    cin >> M;

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // Вывод матрицы
    cout << "\nМатрица" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int top = 0, bottom = N - 1;
    int left = 0, right = M - 1;
    int index = 0;

    while (top <= bottom && left <= right) {
        // Верхняя строка: слева направо
        for (int j = left; j <= right; j++) {
            result[index++] = matrix[top][j];
        }
        top++;

        // Правый столбец: сверху вниз
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;

        // Нижняя строка: справа налево (если есть)
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[index++] = matrix[bottom][j];
            }
            bottom--;
        }
        
        // Левый столбец: снизу вверх (если есть)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }

    // Вывод результата
    for (int i = 0; i < index; i++) {
        cout << result[i] << "   ";
    }
    

    return 0;
}

