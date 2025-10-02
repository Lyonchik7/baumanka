#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    
    int const N = 15;
    double mas[N];

    cout << "Введите" << N << "натуральных чисел\n";
    for (int i = 0; i < N; i++) {
        cout << "Элемент" << i + 1 << ":";
        cin >> mas[i];
    }

    int maxIndex = 0, minIndex = 0;
    double maxZnach = mas[0], minZnach = mas[0];

    for (int i = 0; i < N; i++) {
        if (mas[i] > mas[0]) {
            maxZnach = mas[i];
            maxIndex = i;
        }
    
        if (mas[i] < mas[0]) {
            minZnach = mas[i];
            minIndex = i;
        }

    }

    if (maxIndex < minIndex) {
        cout << "Произведение максимального и минимального элементов массива равняется: " << maxZnach * minZnach << endl;
    }
    else {
        cout << "Минимальный элемент предшествует максимальному\n";
    }



    return 0;
}

