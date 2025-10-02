#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    const int n = 15;
    int mas[n];

    // Пользователь вводит элементы массива
    for (int i = 0; i < n; i++) {
        cout << "Введите элемент" << i + 1 << ":";
        cin >> mas[i];
    }

    // Выводится весь массив
    cout << "Массив:" ;
    for (int i = 0; i < n; i++) {
        cout << mas[i] << "   ";
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
    
    // Условие обнуления элементов массива, которые расположены перед минимальным значением
    if (mas[minIndex] == 0 || mas[maxIndex] == 0) {
        for (int i = 0; i < minIndex; i++) {
            mas[i] = 0;
        }
        cout << "Новый массив:  ";
        for (int i = 0; i < n; i++) {
            cout << mas[i] << "   ";
        }
    }
    else {
        cout << "\n Максимальный и минимальный элементы не равны 0";
    }
    
    return 0;
}

