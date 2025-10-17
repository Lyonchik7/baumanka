#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[100];

    cout << "Введите строку: ";
    cin.getline(str, 100);

    int count = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        // Проверяем все предыдущие символы
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break;  // Нашли такой же символ ранее
            }
        }

        // Если дошли до i, значит символ уникальный
        if (j == i) {
            count++;
        }
    }

    cout << "Количество уникальных символов: " << count << endl;

    return 0;
}