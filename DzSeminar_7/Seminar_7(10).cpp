#include <iostream>
using namespace std;

int myStrCmp(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 200;
    char str1[n], str2[n];

    cout << "Введите первую строку: ";
    cin.getline(str1, n);

    cout << "Введите вторую строку: ";
    cin.getline(str2, n);

    int result = myStrCmp(str1, str2);

    if (result == 0) {
        cout << "Строки равны" << endl;
    }
    else if (result < 0) {
        cout << "Первая строка меньше второй" << endl;
    }
    else {
        cout << "Первая строка больше второй" << endl;
    }

    return 0;
}