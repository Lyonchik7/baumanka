#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    ifstream readfile("book.txt");

    if (readfile.fail()) {
        cout << "Файл book.txt не найден. Создаю новый..." << endl;

        // создание файла с примером текста
        ofstream outFile("book.txt");
        if (outFile.is_open()) {
            outFile << "Это книга о приключениях героя." << endl;
            outFile << "Главный герой отправляется в путь." << endl;
            outFile << "На пути героя ждут испытания." << endl;
            outFile << "Но наш герой справится со всем!" << endl;
            outFile << "Вот такая история о герое." << endl;
            outFile.close();
            cout << "Файл успешно создан и заполнен." << endl;
        }
        else {
            cout << "Не удалось создать файл для записи." << endl;
        }

        // переоткрываем файл для чтения
        readfile.open("book.txt");
        if (readfile.fail()) {
            cout << "Не удалось открыть созданный файл!" << endl;
        }
    }

    // создание вектора для хранения результата
    vector<pair<int, int>> vect;

    int stroka = 0;
    int position = 0;
    int count = 0;
    string str;

    while (getline(readfile, str)) {
        position = 0;
        while ((position = str.find("герой", position)) != string::npos) {
            vect.push_back({ stroka, position });
            count++;
            position += 5;
        }
        stroka++;
    }
    readfile.close();

    // записывание в файл для результат
    ofstream file("result.txt");
    for (auto& p : vect) {
        file << "Строка: " << p.first << " Позиция: " << p.second << endl;
    }

    file << "Общее количество вхождений: " << count << endl;
    file.close();

    cout << "Поиск завершен! Найдено " << count << " вхождений." << endl;

    return 0;
}