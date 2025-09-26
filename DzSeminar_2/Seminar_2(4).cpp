#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int l;
    cout << "Введите число: " << endl;
    cin >> l;
    if (l % 2 == 0) {
        cout << " четное " << endl;
    }
    else {
        cout << " нечетное " << endl;
    }

    return 0;
}

