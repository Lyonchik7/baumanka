#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    char str[256];

    cout << "Введите строку: ";
    cin.getline(str, 256);

    // Создаем временный массив для строки без пробелов
    char temp[256];
    int tempIndex = 0;

    // Удаляем пробелы и приводим к нижнему регистру
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            temp[tempIndex] = tolower(str[i]);
            tempIndex++;
        }
    }
    temp[tempIndex] = '\0'; // Завершаем строку

    // Проверяем на палиндром
    int length = strlen(temp);
    bool isPalindrome = true;

    for (int i = 0; i < length / 2; i++) {
        if (temp[i] != temp[length - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "Палиндром" << endl;
    }
    else {
        cout << "Не палиндром" << endl;
    }

    return 0;
}