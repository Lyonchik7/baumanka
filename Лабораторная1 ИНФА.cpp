#include <iostream>

using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");

    float a = 0;
    cout << "Введите количество бензина:";
    cin >> a;

    if (a > 50)
        cout << "Топлива достаточно\n";

    if (a > 20 && a < 50)
        cout << "Рекомендуется заправка\n";

    if (a < 20)
        cout << "Топливо на исходе, срочно заправьтесь!\n";


    float b = 0;
    cout << "Введите количество бензина:";
    cin >> b;

    while (true) {
        cout << "Введите количество бензина:";
        cin >> b;
        if(b < 0)
            cout << "Ошибка";
        break;
    }
    
    return 0;
}

