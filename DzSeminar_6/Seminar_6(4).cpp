#include <iostream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    char str1[100];
    cout << "Введите строку A: ";
    cin.getline(str1, 100);

    char str2[100];
    cout << "Введите строку B: ";
    cin.getline(str2, 100);

    int length = strlen(str2);
    
    for (int i = 0; i < length; i++) {
        bool found = false;

        // Ищем символ str2[i] в строке str1
        for (int j = 0; str1[j] != '\0'; j++) {
            if (str1[j] == str2[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Нет";
            return 0;
        }
    }

    cout << "Да";

    return 0;
}

