#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    ofstream outputFile("output.txt"); 
    string line;

    cout << "Введите строки (пустая строка завершает ввод):" << endl;

    // Читаем первую строку
    getline(cin, line);

    while (!line.empty()) {
        outputFile << line << endl; 
        getline(cin, line);  
    }

    outputFile.close(); 
    cout << "Данные записаны в файл output.txt." << endl;

    return 0;
}

