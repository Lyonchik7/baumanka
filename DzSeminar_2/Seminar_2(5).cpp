#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int b;
    cout << "Введите число: " << endl;
    cin >> b;

    if (b % 3 == 0)
        cout << " делится на 3 " << endl;
    else
        cout << " не делится на 3 " << endl;

    if (b % 5 == 0)
        cout << " делится на 5 " << endl;
    else
        cout << " не делится на 5 " << endl;


    return 0;
}

