#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int n;
    cout << " Веедите число " << endl;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << i << "   " << i * i << endl;
    }

    return 0;
}

