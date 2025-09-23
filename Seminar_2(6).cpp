#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int c;
    cout << " Введите возраст  " << endl;
    cin >> c;

    if (c > 60)
        cout << " старше 60 \n";

    if (c > 18 && c < 60)
        cout << " старше 18, но моложе 60 \n";

    if (c < 18)
        cout << " моложе 18\n";

    return 0;
}

