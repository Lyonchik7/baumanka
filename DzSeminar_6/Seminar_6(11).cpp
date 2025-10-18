#include <iostream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    char str[100];
    int k;

    cout << "Строка: ";
    cin.getline(str, 100);
    cout << "k = ";
    cin >> k;

    int len = strlen(str);

    for (int i = 0; i <= len - k; i++) {
        int ok = 1;

        // Проверяем уникальность
        for (int j = i; j < i + k && ok; j++) {
            for (int m = j + 1; m < i + k && ok; m++) {
                if (str[j] == str[m]) ok = 0;
            }
        }

        // Выводим если все символы уникальны
        if (ok) {
            for (int j = i; j < i + k; j++) {
                cout << str[j];
            }
            cout << endl;
        }
    }

    return 0;
}