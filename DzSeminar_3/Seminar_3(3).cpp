#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    const int n = 15;
    int mas[n];

    for (int i = 0; i < n; i++) {
        cout << "Введите число" << i + 1 << ":";
        cin >> mas[i];
    }
    // Выводим маасив до перестановок
    cout << "Изначальный массив:\n";
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }

    int maxIndex = 0, minIndex = 0;
    int min = mas[0], max = mas[n-1];

    // Меняем максимальный элемент с последним
    for (int i = 0; i < n; i++) {
        if (mas[i] > mas[maxIndex])
            maxIndex = i;
    }

    swap(mas[n - 1], mas[maxIndex]);

    // Меняем минимальный элемент с первым
    for (int i = 0; i < n; i++) {
        if (mas[i] < mas[minIndex])
            minIndex = i;
    }

    swap(mas[0], mas[minIndex]);

    // Выводим изменённый масив
    cout << "\nМассив с перестановкой:\n";
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }

    return 0;
}

