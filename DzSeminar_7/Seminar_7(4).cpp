#include <iostream>
#include <cstring>
using namespace std;
int search(char* dest, const char* src) {
    int count = 0;
    while (*dest != '\0') {
        if (*dest == *src) {
            count++;
        }
        dest++;
    }
    return count;
}


int main() {
    setlocale(LC_ALL, "RU");
    const int n = 300;

    char str[n];
    cout << "Введите строку: ";
    cin.getline(str, 300);

    char sym[2];
    cout << "Введите символ, количество которого мы будем искать: ";
    cin.getline(sym, 2);
    
    int result = search(str, sym);
    cout << result;

    return 0;
}


