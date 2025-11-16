#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    ofstream outFile("text.txt");

    if (outFile.is_open()) {
        outFile << "я учусь в МГТУ имени Бауманат на факультете ИУ, а вообще я душка" << endl;
        outFile << "banana" << endl;
        outFile.close();
        cout << "Файл успешно создан и заполнен." << endl;
    }
    else {
        cerr << "Не удалось создать файл для записи." << endl;
    }

    ifstream inFile("text.txt");

    int wordCount = 0;
    string word;

    while (inFile >> word) {
        wordCount++;
    }

    inFile.close();
    cout << "Количество слов в файле: " << wordCount << endl;

 
    return 0;
}

