#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    ofstream sourceFile("source.txt");
    if (sourceFile.is_open()) {
        sourceFile << "Это первая строка " << endl;
        sourceFile << "Вторая строка " << endl;
        sourceFile << "Третья строка для демонстрации копирования." << endl;
        sourceFile.close();
        cout << "Исходный файл source.txt создан." << endl;
    }
    else {
        cerr << "Ошибка создания исходного файла!" << endl;
    }

    ifstream inFile("source.txt");  
    ofstream outFile("copy.txt");  

    int lineCount = 0;
    string line;

    while (getline(inFile, line)) {
        outFile << line << endl; 
        lineCount++; 
    }

    inFile.close();
    outFile.close();

    cout << "Файл успешно скопирован." << endl;
    cout << "Количество скопированных строк: " << lineCount << endl;

    return 0;
}