#include <iostream>
using namespace std;

bool isPalindrome(const char* str) {
    const char* begin = str;
    const char* end = str;

    while (*end != '\0') {
        end++;
    }
    end--; // так как после while будет указывать на \0

    while (begin < end) {
        if (*begin != *end)
            return false;
        begin++;
        end--;
        
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "RU");
    const int n = 300;

    char str[n];
    cout << "Введите строку: ";
    cin.getline(str, n);

    bool check = isPalindrome(str);
    if (check) 
        cout << "Строка является палиндромом" << endl;
    else 
        cout << "Строка не является палиндромом" << endl;


    return 0;
}
