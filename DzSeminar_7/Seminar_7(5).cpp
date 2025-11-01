#include <iostream>
using namespace std;

void probel(char* dest) {
    while (*dest != '\0') {
        dest++;
        if (*dest == ' ') 
            *dest = '_';
    }
    
    *dest = '\0';
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
