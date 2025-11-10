#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    char str[100];
    cout << "Введите строку(на английском): ";
    cin.getline(str, 100);
    int length = strlen(str);

    // 1) Заполнение массива
    unique_ptr<char[]> arr = make_unique<char[]>(length + 1);
    strcpy_s(arr.get(), length + 1, str);
    cout << "Строка: " << arr.get() << endl;

    // 2) Подсчет гласный и согласных
    int glasn = 0, soglasn = 0;
    for (int i = 0; i < length; i++) {
        char c = tolower(arr[i]);
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                glasn++;
            }
            else {
                soglasn++;
            }
        }
    }
    cout << "Гласные: " << glasn << endl;
    cout << "Согласные: " << soglasn << endl;

    // 3) Массив с гласными
    unique_ptr<char[]> vowelArr = make_unique<char[]>(glasn + 1);
    int index = 0;
    for (int i = 0; i < length; i++) {
        char c = arr[i];
        char lowerC = tolower(c);

        if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' ||
            lowerC == 'o' || lowerC == 'u') {
            vowelArr[index++] = c;
        }
    }
    vowelArr[glasn] = '\0';
    cout << "Гласные буквы: " << vowelArr.get() << endl;
 
    return 0;
}
