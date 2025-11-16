#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    ofstream sourceFile("input.txt");
    if (sourceFile.is_open()) {
        sourceFile << "Это первая строка " << endl;
        sourceFile << "Вторая строка " << endl;
        sourceFile << "lfksjjalkdgjlkhsgkjhdsh" << endl;
        sourceFile.close();
        cout << "Файл input.txt создан" << endl;
    }
    else {
        cerr << "Ошибка создания файла!" << endl;
    }

    // подсчет символов
    int count = 0;
    char ch;

    ifstream readfile("input.txt");
    while (readfile.get(ch)) {
        count++;
    }

    cout << "Количество символов в файле: " << count << endl;

    return 0;
}
