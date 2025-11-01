#include <iostream>
using namespace std;

void reverse(char* src) {
    char* begin = src;
    char* end = src;

    while (*end != '\0') {
        end++;
    }
    end--; // так как после while будет указывать на \0

    while (begin < end) {
        char temp = *begin;
        *begin = *end;             // Замена
        *end = temp;

        begin++;           // Сдвиг
        end--;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    const int n = 300;

    char str[n];
    cout << "Введите строку: ";
    cin.getline(str, 300);
    
    reverse(str);
    cout << str;
    
    return 0;
}

