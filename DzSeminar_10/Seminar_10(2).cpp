#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    ofstream outFile("data.txt");

    if (outFile.is_open()) {
        outFile << "всем" << endl;
        outFile << "привет" << endl;
        outFile << "я" << endl;
        outFile << "Лёнчик" << endl;
        outFile << "hello" << endl;
        outFile << "banana" << endl;
        outFile << "br br patapim" << endl;
        outFile << "tralalelo tralala" << endl;
        outFile.close();
        cout << "Файл успешно создан и заполнен." << endl;
    }
    else {
        cerr << "Не удалось создать файл для записи." << endl;
    }

    ifstream inFile("data.txt");

    int linecount = 0;
    string line;

    while (getline(inFile, line)) {
        linecount++;
    }

    inFile.close();

    cout << "Количество строк в файле: " << linecount << endl;


    return 0;
}

