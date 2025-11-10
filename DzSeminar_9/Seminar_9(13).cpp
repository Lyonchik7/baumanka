#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // Создание уникальных указателей на строки
    unique_ptr<string> part1 = make_unique<string>("Sensor data:");
    unique_ptr<string> part2 = make_unique<string>("Voltage stable.");
    unique_ptr<string> part3 = make_unique<string>("System nominal.");

    // Сохранение указателей в вектор
    vector<unique_ptr<string>> reportParts;
    reportParts.push_back(move(part1));
    reportParts.push_back(move(part2));
    reportParts.push_back(move(part3));

    // Лямбда-функция для объединения строк
    auto concatParts = [](const vector<unique_ptr<string>>& parts) -> string {
        string result;
        for (const auto& part : parts) {
            if (!result.empty()) {
                result += "\n";
            }
            result += *part;
        }
        return result;
        };

    // Объединение всех частей в один текст
    string fullReport = concatParts(reportParts);

    // Лямбда-функция для подсчёта вхождений слова
    auto countWord = [](const string& text, const string& word) -> int {
        int count = 0;
        size_t pos = 0;
        while ((pos = text.find(word, pos)) != string::npos) {
            count++;
            pos += word.length();
        }
        return count;
        };

    // Подсчёт количества вхождений слова "data"
    int wordCount = countWord(fullReport, "data");

    // Вывод результатов
    cout << "Отчёт:" << endl;
    cout << fullReport << endl;

    cout << "Слово \"data\" встречается " << wordCount << " раз" << endl;

    return 0;
}