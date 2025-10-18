#include <iostream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    char str[100];
    cout << "Введите строку" << endl;
    cin.getline(str, 100);

    int count_gl = 0;
    int count_sogl = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        char sym = tolower(str[i]);

        if (sym >= 'a' && sym <= 'z') {
            if (sym == 'a' || sym == 'e' || sym == 'i' || sym == 'o' || sym == 'u' || sym == 'y') {
                count_gl++;
            }
            else {
                count_sogl++;
            }
        }
    }
    
    cout << "Гласных: " << count_gl << endl;
    cout << "Согласных: " << count_sogl << endl;


    return 0;
}
