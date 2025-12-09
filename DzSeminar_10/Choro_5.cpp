#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

// Генерация массива
vector<int> generateArray(int n) {
    vector<int> arr(n);
    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < n; i++) {
        arr[i] = gen() % 1000000;
    }
    return arr;
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = 0; j < arr.size() - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    const int N = 10000;

    // Генерация
    vector<int> arr = generateArray(N);
    vector<int> arrCopy;

    // Bubble Sort
    arrCopy = arr;
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arrCopy);
    auto end = chrono::high_resolution_clock::now();
    long long bubbleTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // std::sort
    arrCopy = arr;
    start = chrono::high_resolution_clock::now();
    sort(arrCopy.begin(), arrCopy.end());
    end = chrono::high_resolution_clock::now();
    long long stdTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // Результаты
    cout << "Bubble Sort: " << bubbleTime << " мс" << endl;
    cout << "std::sort:   " << stdTime << " мс" << endl;
    cout << "Отношение:   " << (double)bubbleTime / stdTime << "x" << endl;

    return 0;
}