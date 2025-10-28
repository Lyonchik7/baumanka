#include <iostream>
using namespace std;

void free2D(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        delete[] arr[i];  // удаление памяти каждой строки
    }
    delete[] arr;  // удаление памяти массива указателей
}

int main() {
    setlocale(LC_ALL, "RU");

    int n = 0, m = 0;
    cout << "Введите количество строк массива" << endl;
    cin >> n;
    cout << "Введите количество столбцов массива" << endl;
    cin >> m;

    // Создание двумерного динамического массива
    int** arr = new int* [n]; //Создание массива указателей на строки 
    // Выделение памяти для каждого столбца в каждой строке
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m]; // Выделяем память для каждого ряда
    }

    // Заполнение массива пользователем
    cout << "\nЗаполните массив " << n << "на" << m << "(числа от 0 до 99):" << endl;
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

    // Освобождение памяти 
    cout << "\nОсвобождение памяти" << endl;
    free2D(arr, n);
    arr = nullptr;


    return 0;
}
