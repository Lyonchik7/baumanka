#include <iostream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);

    int writeIndex = 0;

    for (int readIndex = 0; str[readIndex] != '\0'; readIndex++) {
        // Проверяем, что символ НЕ является цифрой от '0' до '9'
        if (!(str[readIndex] >= '0' && str[readIndex] <= '9')) {
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
    }

    str[writeIndex] = '\0';

    cout << "Результат: " << str << endl;

    return 0;
}

