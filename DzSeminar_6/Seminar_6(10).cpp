#include <iostream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    char str[256];

    cout << "Введите строку (англ): ";
    cin.getline(str, 256);

    int len = strlen(str);
    int start = 0;

    for (int i = 0; i <= len; i++) {
        // Если конец слова (пробел или конец строки)
        if (str[i] == ' ' || str[i] == '\0') {
            // Переворачиваем слово от start до i-1
            int left = start;
            int right = i - 1;

            while (left < right) {
                // Меняем символы местами
                char temp = str[left];
                str[left] = str[right];
                str[right] = temp;
                left++;
                right--;
            }

            start = i + 1; // Начало следующего слова
        }
    }

    cout << "Результат: " << str << endl;

    return 0;
}