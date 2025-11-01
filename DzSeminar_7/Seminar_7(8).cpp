#include <iostream>
using namespace std;

const char* findSubstring(const char* text, const char* word) {
    const char* ptr = text;

    while (*ptr != '\0') {
        const char* text_step = ptr;
        const char* word_step = word;

        while (*text_step != '\0' && *word_step != '\0' && *text_step == *word_step) {
            text_step++;
            word_step++;
        }

        if (*word_step == '\0') {
            return ptr;
        }
        ptr++;
    }
    return nullptr;
}


int main() {
    setlocale(LC_ALL, "RU");
    const int n = 300;

    char str[n];
    cout << "Введите строку: ";
    cin.getline(str, n);

    char word[n];
    cout << "Введите слово: ";
    cin.getline(word, n);

    const char* result = findSubstring(str, word);

    if (result != nullptr) {
        cout << "Подстрока найдена на позиции: " << (result - str) << endl;
        cout << "Найденная подстрока: " << result << endl;
    }
    else {
        cout << "Подстрока не найдена" << endl;
    }

    return 0;
}