#include <iostream>
#include <cstring>
using namespace std;

void myStrCopy(char* dest, const char* src) {
    while (*src != '\0') { // Пока не достигнут конец исходной строки
        *dest = *src; // Копируем текущий символ из исходной строки в буфер
        src++; // Переходим к следующему символу в исходной строке
        dest++; // Переходим к следующему свободному месту в буфере
    }
    *dest = '\0'; // Завершаем новую строку в буфере, устанавливая нулевой символ
}

int main() {
    setlocale(LC_ALL, "RU");
    const int n = 300;

    char str[n];
    cout << "Введите строку: ";
    cin.getline(str, 300);

    char str_2[n];
    myStrCopy(str_2, str);
    cout << str << endl;
    cout << str_2 << endl;

    return 0;
}

