#include <iostream>
#include <memory>

using namespace std;

void fillArray(unique_ptr<int[]>& arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i*i;

    }

    cout << "Содержимое массива: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    int N;
    cout << "Введите размер массива: ";
    cin >> N;

    unique_ptr<int[]> arr = make_unique<int[]>(N);

    fillArray(arr, N);

    return 0;
}

