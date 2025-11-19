#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    cout << "=== РАБОТА С JSON КОНФИГУРАЦИЕЙ ===" << endl;

    // Создание конфигурационного файла
    cout << "\n1. Создание config.json..." << endl;

    ofstream createFile("config.json");
    createFile << "{\n";
    createFile << "  \"app_name\": \"My Application\",\n";
    createFile << "  \"version\": \"1.0.0\",\n";
    createFile << "  \"settings\": {\n";
    createFile << "    \"max_connections\": 100,\n";
    createFile << "    \"timeout\": 30,\n";
    createFile << "    \"debug_mode\": true\n";
    createFile << "  },\n";
    createFile << "  \"database\": {\n";
    createFile << "    \"host\": \"localhost\",\n";
    createFile << "    \"port\": 5432,\n";
    createFile << "    \"username\": \"admin\"\n";
    createFile << "  }\n";
    createFile << "}";
    createFile.close();

    cout << " Файл создан!" << endl;

    // Чтение файла
    cout << "\n2. Чтение config.json..." << endl;

    ifstream readFile("config.json");
    string line;
    while (getline(readFile, line)) {
        cout << line << endl;
    }
    readFile.close();

    // Изменение timeout
    cout << "\n3. Изменение timeout на 60..." << endl;

    ifstream inFile("config.json");
    vector<string> lines;

    while (getline(inFile, line)) {
        size_t pos = line.find("\"timeout\":");
        if (pos != string::npos) {
            line = "    \"timeout\": 60,";
        }
        lines.push_back(line);
    }
    inFile.close();

    ofstream outFile("config.json");
    for (const string& l : lines) {
        outFile << l << endl;
    }
    outFile.close();

    cout << " Timeout изменен!" << endl;

    // Вывод обновленного файла
    cout << "\n4. Обновленный config.json:" << endl;

    ifstream finalFile("config.json");
    while (getline(finalFile, line)) {
        cout << line << endl;
    }
    finalFile.close();

    return 0;
}