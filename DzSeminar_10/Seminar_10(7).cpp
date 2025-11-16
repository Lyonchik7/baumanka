#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    ofstream sourceFile("numbers.txt");
    if (sourceFile.is_open()) {
        sourceFile << " 5 6 7 8 9 0" << endl;
        sourceFile << " 5 6 7 8 " << endl;
        sourceFile << " 0 7 8" << endl;
        sourceFile.close();
        cout << "Файл numbers.txt создан" << endl;
    }
    else {
        cerr << "Ошибка создания файла!" << endl;
    }

    ifstream inputFile("numbers.txt"); 

    int number;
    int count = 0;
    int sum = 0;
    double average = 0.0;

    while (inputFile >> number) {
        count++;          
        sum += number;
    }

    average = static_cast<double>(sum) / count;

    cout << "Количество чисел: " << count << endl;
    cout << "Сумма: " << sum << endl;
    cout << "Среднее: " << average << endl;

    return 0;
}

