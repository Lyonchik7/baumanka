#include <iostream>
#include <cstring>
using namespace std;

void sortWords(char** words, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    const int n = 7;
    char** words = new char* [n];

    cout << "Введите " << n << " слов:" << endl;

    for (int i = 0; i < n; i++) {
        char buffer[100];
        cout << "Слово " << (i + 1) << ": ";
        cin >> buffer;

        words[i] = new char[strlen(buffer) + 1];
        strcpy_s(words[i], strlen(buffer) + 1, buffer);
    }

    cout << "\nИсходные слова:" << endl;
    for (int i = 0; i < n; i++) {
        cout << words[i] << endl;
    }

    sortWords(words, n);

    cout << "\nОтсортированные слова:" << endl;
    for (int i = 0; i < n; i++) {
        cout << words[i] << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] words[i];
    }
    delete[] words;

    return 0;
}