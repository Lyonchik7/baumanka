#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    // Создание и заполнение файла
    ofstream file("config.txt");
    if (!file.is_open()) {
        cout << "Ошибка в создании файла" << endl;
        return 1;
    }

    file << "server_ip=192.168.1.1" << endl;
    file << "port=8080" << endl;
    file << "timeout=30" << endl;
    file << "max_connections=100" << endl;
    file.close();

    // Чтение файла в вектор
    vector<string> vect;
    string str;

    ifstream readfile("config.txt");
    if (!readfile.is_open()) {
        cout << "Ошибка в открытии файла для чтения" << endl;
        return 1;
    }

    while (getline(readfile, str)) {
        vect.push_back(str);
    }
    readfile.close();

    // Поиск и замена
    string key = "timeout=";
    int replacements = 0;

    for (int i = 0; i < vect.size(); i++) {
        if (vect[i].find(key) != string::npos) {
            cout << "Найдено: " << vect[i] << endl;
            vect[i] = "timeout=60";
            replacements++;
            cout << "Заменено на: " << vect[i] << endl;
        }
    }

    // Перезапись файла
    ofstream endfile("config.txt");
    if (!endfile.is_open()) {
        cout << "Ошибка в открытии файла для записи" << endl;
        return 1;
    }

    for (int i = 0; i < vect.size(); i++) {
        endfile << vect[i] << endl;
    }
    endfile.close();

    cout << "Замена завершена. Изменено строк: " << replacements << endl;

    return 0;
}