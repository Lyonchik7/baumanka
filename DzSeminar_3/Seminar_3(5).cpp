#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    const int n = 10;
    int mas[n];

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
    double sredn = 0;

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
    if (minIndex == 4 && maxIndex == 9) {
        sredn = (mas[minIndex] + mas[maxIndex]) / 2;
    }
    else {
        cout << "Максимальный и минимальный элементы массива расположены не на тех позициях";
    }

    cout << "\nСреднее арифметическое равняется: " << sredn;
   
    

    return 0;
}

