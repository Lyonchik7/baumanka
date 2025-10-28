#include <iostream>
using namespace std;

// Функция для вычисления суммы элементов строки
int rowSum(int* row, int m) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
        sum += row[j];
    }
    return sum;
}

// Функция для сортировки строк по сумме элементов
void sortSum(int** arr, int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (rowSum(arr[j], m) > rowSum(arr[j + 1], m)) {
                // Меняем местами указатели на строки
                int* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция для освобождения памяти
void free2D(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
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
    cout << "\nЗаполните массив " << n << "на" << m << ":" << endl;
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
    
    cout << "\nСортировка строк по возрастанию суммы элементов" << endl;
    sortSum(arr, n, m);

    // Вывод отсортированного массива
    cout << "\nОтсортированный массив:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Освобождение памяти
    free2D(arr, n);
    
    return 0;
}
