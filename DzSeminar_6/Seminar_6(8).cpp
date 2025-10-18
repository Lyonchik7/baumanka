#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    char str[256];

    cout << "Введите текст (англ): ";
    cin.getline(str, 256);

    int len = strlen(str);
    int newSentence = 1; // 1 - новое предложение, 0 - не новое

    for (int i = 0; i < len; i++) {
        if (newSentence == 1 && isalpha(str[i])) {
            // Первая буква - заглавная
            str[i] = toupper(str[i]);
            newSentence = 0;
        }
        else if (newSentence == 0) {
            // Остальные буквы - строчные
            str[i] = tolower(str[i]);
        }

        // Проверяем конец предложения
        if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
            newSentence = 1;
        }
    }

    cout << "Результат: " << str << endl;

    return 0;
}