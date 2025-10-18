#include <iostream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    char str[100];
    cout << "Введите строку:";
    cin.getline(str, 100);

    int shift = 0;
    cout << "Напиши длину сдвига для шифра Цезаря (маленькоее число) :";
    cin >> shift;

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char c = str[i];

        if (c >= 'A' && c <= 'Z') {
            // Заглавные буквы
            str[i] = (c - 'A' + shift) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z') {
            // Строчные буквы
            str[i] = (c - 'a' + shift) % 26 + 'a';
        }
    }

    cout << "Результат: " << str << endl;



    return 0;
}

