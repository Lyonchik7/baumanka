#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    
    float f;
    cout << "Введите сколько градусов по цельсию:" << endl;
    cin >> f;
    cout << " По Фаренгейту: " << f * 9 / 5 + 32 << endl;

    return 0;
}

