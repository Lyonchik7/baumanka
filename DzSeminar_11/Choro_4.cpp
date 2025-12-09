#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

// 1. Пузырьковая сортировка
void bubble(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr.size() - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// 2. Сортировка вставками
void insertion(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int n = 10000;
    vector<int> arr(n);

    // Заполняем случайными числами
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    // Копии для каждого алгоритма
    vector<int> arr1 = arr;
    vector<int> arr2 = arr;
    vector<int> arr3 = arr;

    // Замер времени для bubble sort
    auto start = chrono::high_resolution_clock::now();
    bubble(arr1);
    auto end = chrono::high_resolution_clock::now();
    auto bubble_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // Замер времени для insertion sort
    start = chrono::high_resolution_clock::now();
    insertion(arr2);
    end = chrono::high_resolution_clock::now();
    auto insertion_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // Замер времени для std::sort
    start = chrono::high_resolution_clock::now();
    sort(arr3.begin(), arr3.end());
    end = chrono::high_resolution_clock::now();
    auto std_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // Вывод результатов
    cout << "Размер массива: " << n << endl << endl;
    cout << "Пузырьковая сортировка: " << bubble_time << " мс" << endl;
    cout << "Сортировка вставками:   " << insertion_time << " мс" << endl;
    cout << "std::sort:              " << std_time << " мс" << endl;

    return 0;
}