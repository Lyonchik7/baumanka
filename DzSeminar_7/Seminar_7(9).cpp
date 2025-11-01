#include <iostream>
using namespace std;

void probel(char* dest) {
    char* read = dest;   // для чтения
    char* write = dest;  // для записи

    while (*read != '\0') {
        if (*read != ' ') {  
            *write = *read;
            write++;
        }
        read++;
    }
    *write = '\0';  // Завершаем строку
}

int main() {
    setlocale(LC_ALL, "RU");
    const int n = 300;

    char str[n];
    cout << "Введите строку: ";
    cin.getline(str, 300);

    probel(str);
    cout << str;


    return 0;
}
