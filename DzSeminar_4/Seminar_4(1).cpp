#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int N = 0;
    double matrix[100][100];
    double matrix_1[100][100];
    double matrix_2[100][100];
    double matrix_3[100][100];
    double matrix_4[100][100];

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
    cout << "Матрица:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Отражение относительно главной диагонали
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double temp1 = matrix[i][j];
            matrix_1[j][i] = temp1;
        }
    }

    cout << "\nМатрица отражённая относительно главной диагонали:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix_1[i][j] << " ";
        }
        cout << endl;
    }

    
    // Отражение относительно побочной диагонали
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double temp2 = matrix[i][j];
            matrix_2[N - 1 - j][N - 1 - i]= temp2;
        }
    }

    cout << "\nМатрица отраженная относительно побочной диагонали:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix_2[i][j] << " ";
        }
        cout << endl;
    }

    
    // Отражение относительно вертикальной оси  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double temp3 = matrix[i][j];
            matrix_3[i][N - 1 - j] = temp3;
        }
    }

    cout << "\nМатрица отраженная относительно вертикали:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix_3[i][j] << " ";
        }
        cout << endl;
    }

    
    // Отражение относительно горизонтальной оси
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double temp4 = matrix[i][j];
            matrix_4[N - 1 - i][j] = temp4;
        }
    }

    cout << "\nМатрица отраженная относительно горизонтали:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix_4[i][j] << " ";
        }
        cout << endl;
    }

    
    // Сравнение элементво матриц
    cout << "\n                         " << endl << "Сравнение полученных матриц" << endl;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix_1[i][j] == matrix_2[i][j] && matrix_3[i][j] == matrix_4[i][j] && matrix_1[i][j] == matrix_3[i][j]) {
                cout << "Совпадающие элементы под  индексом:" << "(" << i << "," << j << ")" << endl;
            }
            else {
                cout << "NONE " << "(" << i << "," << j << ")" << endl;
            }
        }
    }

    return 0;
}