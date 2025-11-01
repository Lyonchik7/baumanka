#include <iostream>
using namespace std;

void parseTelemetry(const char* data) {
    const char* p = data;

    while (*p != '\0') {
        // Пропускаем пробелы
        while (*p == ' ') p++;
        if (*p == '\0') break;

        // Извлекаем и выводим имя
        while (*p != ':' && *p != '\0') {
            cout << *p;
            p++;
        }
        if (*p == '\0') break;

        cout << ": ";
        p++; // Пропускаем :

        // Извлекаем и выводим значение
        while (*p != ';' && *p != '\0') {
            cout << *p;
            p++;
        }
        cout << endl;

        if (*p == ';') p++;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    const int n = 300;
    char str[n];
    cout << "Напишите данные сенсоров: ";
    cin.getline(str, n);

    parseTelemetry(str);

    return 0;
}