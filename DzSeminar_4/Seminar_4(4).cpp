#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    int N = 0;
    cout << "Введите порядок матрицы" << endl;
    cin >> N;

    int matrix[100][100];
    int num = 1;
    int top = 0, bottom = N - 1, left = 0, right = N - 1;

    while (num <= N * N) {
        // Верх
        for (int j = left; j <= right; j++) {
            matrix[top][j] = num++;
        }
        top++;
        
        // Право
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;
        
        // Низ
        for (int j = right; j >= left; j--) {
            matrix[bottom][j] = num++;
        }
        bottom--;
        
        // Лево
        for (int i = bottom; i >= top; i--) {
            matrix[i][left] = num++;
        }
        left++;
    }

    // Вывод
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}