#include <iostream>
using namespace std;

// Функция для нахождения суммы
int summa(int** arr, int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += *(*(arr + i) + j);
        }
    }

    return sum;
}


int main() {
    setlocale(LC_ALL, "RU");
    
    int n = 0, m = 0;
    cout << "Введите количество строк матрицы" << endl;
    cin >> n;
    cout << "Введите количество столбцов матрицы" << endl;
    cin >> m;
        
    int** arr = new int* [n]; 
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m]; 
    }

    // Заполнение массива пользователем
    cout << "\nЗаполните массив " << n << " на " << m << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    // Вывод массива в виде таблицы
    cout << "\nВведенный массив:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    int total = summa(arr, n, m);
    cout << "Сумма элементов массива равна: " << total << endl;
    
    // Удаление памяти
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    
    return 0;
}

