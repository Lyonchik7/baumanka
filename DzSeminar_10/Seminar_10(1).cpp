#include <fstream>
#include <iostream>
#include<string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    ofstream outFile("input.txt");

    if (outFile.is_open()) {
        outFile << "Это первая строка" << endl;
        outFile << "Это вторая строка" << endl;
        outFile.close();
        cout << "Файл успешно создан и заполнен." << endl;
    }
    else {
        cerr << "Не удалось создать файл для записи." << endl;
    }

    ifstream inFile("input.txt"); // Открытие файла для чтения
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl; // Вывод данных из файла на экран
        }
        inFile.close(); // Закрытие файла
    }
    else {
        cerr << "Не удалось открыть файл для чтения." << endl;
    }
    
    
    
    return 0;
}