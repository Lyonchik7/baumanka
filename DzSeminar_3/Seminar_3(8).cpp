#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    const int n = 10;
    int mas[n];

    // Вводим элементы массива
    for (int i = 0; i < n; i++) {
        cout << "Введит элемент" << i + 1 << ": ";
        cin >> mas[i];
    }

    // Выводится весь массив
    cout << "Массив:";
    for (int i = 0; i < n; i++) {
        cout << mas[i] << "   \n";
    }

    //Поиск максимального и минимального значения
    int minIndex = 0, maxIndex = 0;

    for (int i = 0; i < n; i++) {
        if (mas[i] > mas[maxIndex]) {
            maxIndex = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (mas[i] < mas[minIndex]) {
            minIndex = i;
        }
    }

    if (maxIndex == 1 && minIndex == 4) {
        for (minIndex = 5; minIndex < n; minIndex++) {
            mas[minIndex] = mas[maxIndex];
        }
        cout << "Новый массив:";
        for (int i = 0; i < n; i++) {
            cout << mas[i] << "   ";
        }
    }

    else {
        cout << "Максимальный и минимальный элементы расположены на других местах";
    }




    return 0;
}

