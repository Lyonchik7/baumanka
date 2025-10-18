#include <iostream>
#include <cstring>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    char str[100];

    cout << "Введите строку: ";
    cin.getline(str, 100);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char current = str[i];
        int count = 1;

        // Считаем количество одинаковых символов подряд
        while (i + 1 < len && str[i + 1] == current) {
            count++;
            i++;
        }

        // Выводим символ и количество
        cout << current << count;
    }

    cout << endl;

    return 0;
}