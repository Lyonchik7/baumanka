#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    const int n = 15;
    float mas[n];

    for (int i = 0; i < n; i++) {
        cout << "Введите число" << i + 1 << ":";
        cin >> mas[i];
    }
    // Выводим масив
    cout << "Массив:\n";
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }

    int maxIndex = 0, minIndex = 0;
    

    // Находим максимальный и минимальный элементы
    for (int i = 0; i < n; i++) {
        if (mas[i] > mas[maxIndex])
            maxIndex = i;
    }

    for (int i = 0; i < n; i++) {
        if (mas[i] < mas[minIndex])
            minIndex = i;
    }

    // Накладываем условие
    if (minIndex == 1 && maxIndex == 0) {
        for (int i = 0; i < n; i++) {
            mas[i] = mas[i] * 0.5;
        }
    }
    else {
        cout << "\n Максимальный и минимальный элементы массива расположены не на тех позициях";
    }

    cout << "\nНовый массив:\n";
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }



    return 0;
}

