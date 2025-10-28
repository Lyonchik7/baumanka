#include <iostream>
#include <cstring>
using namespace std;

int myStrLen(const char* str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "RU");
    
    char str[300];
    cout << "Введите строку: ";
    cin.getline(str, 300);

    int length = myStrLen(str);
    cout << "Длина строки: " << length << " символов" << endl;
    

    return 0;
}

