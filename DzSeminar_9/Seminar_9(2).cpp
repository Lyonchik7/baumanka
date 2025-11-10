#include <iostream>
#include <memory>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int N;
	cout << "Введите размер массива: ";
	cin >> N;

    unique_ptr<int[]> arr = make_unique<int[]>(N);

    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    cout << "Содержимое массива: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


	return 0;
}








