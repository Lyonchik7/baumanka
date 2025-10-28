#include <iostream>
#include <cstring>
using namespace std;

void myStrCat(char* dest, const char* src) {
    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}


int main() {
    setlocale(LC_ALL, "RU");
    const int n = 300;

    char str1[n];
    cout << "Введите строку: ";
    cin.getline(str1, 300);

    char str2[n];
    cout << "Введите строку: ";
    cin.getline(str2, 300);

    myStrCat(str1, str2);
    cout << str1;


    return 0;
}


