#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int n;
    cout << " Веедите число " << endl;
    cin >> n;
    int summa = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 5 == 0 || i % 2 == 0) {
            summa += i;

        }
    }
    cout << summa << endl;

    return 0;
}


