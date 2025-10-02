#include <iostream>

using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");

    int n = 0, sum = 0;
    int* mas = new int[n];
    cout << "Введите кооличество членов последовательности:\n";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Элемент" << i + 1 << ":";
        cin >> mas[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (mas[i] > pow(2, i+1))
            sum++;
    }

    cout << sum;

    delete[] mas;
    

    return 0;
}
