#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    ofstream sourceFile1("file1.txt");
    if (sourceFile1.is_open()) {
        sourceFile1 << "hello" << endl;
        sourceFile1 << " 5 6 7 8 " << endl;
        sourceFile1 << "yes" << endl;
        sourceFile1.close();
        cout << "Файл file1.txt создан" << endl;
    }
    else {
        cerr << "Ошибка создания файла file1.txt!" << endl;
    }

    ofstream sourceFile2("file2.txt");
    if (sourceFile2.is_open()) {
        sourceFile2 << "hello" << endl;
        sourceFile2 << " 5 6 7 8 " << endl;
        sourceFile2 << "yes" << endl;
        sourceFile2.close();
        cout << "Файл file2.txt создан" << endl;
    }
    else {
        cerr << "Ошибка создания файла file2.txt!" << endl;
    }

    ifstream inputFile1("file1.txt");
    ifstream inputFile2("file2.txt");

    string line1, line2;
    bool filesAreIdentical = true;

    while (getline(inputFile1, line1) && getline(inputFile2, line2)) {
        if (line1 != line2) {
            filesAreIdentical = false;
            break;  
        }
    }

    if (filesAreIdentical) {
        if (getline(inputFile1, line1) || getline(inputFile2, line2)) {
            filesAreIdentical = false;
        }
    }

    inputFile1.close();
    inputFile2.close();

    if (filesAreIdentical) {
        cout << "Файлы идентичны." << endl;
    }
    else {
        cout << "Файлы различаются." << endl;
    }

    return 0;
}
