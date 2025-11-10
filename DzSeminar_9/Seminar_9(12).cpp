#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // Инициализация вектора с системными логами
    vector<string> systemLogs = {
        "INFO: System started",
        "ERROR: Database connection failed",
        "WARNING: High CPU usage",
        "ERROR: Database connection failed",
        "INFO: User login",
        "ERROR: File not found",
        "WARNING: Disk space low",
        "INFO: System shutdown"
    };

    // Создание shared_ptr для управления журналом логов
    shared_ptr<vector<string>> logPtr = make_shared<vector<string>>(systemLogs);

    // Вектор для хранения отфильтрованных ошибок
    vector<string> errorMessages;

    // Лямбда-функция для определения ошибок в логах
    auto errorDetector = [](const string& logEntry) {
        return logEntry.find("ERROR") != string::npos;
        };

    // Фильтрация логов и копирование ошибок
    copy_if(logPtr->begin(), logPtr->end(), back_inserter(errorMessages), errorDetector);

    // Удаление повторяющихся ошибок
    sort(errorMessages.begin(), errorMessages.end());
    auto uniqueEnd = unique(errorMessages.begin(), errorMessages.end());
    errorMessages.erase(uniqueEnd, errorMessages.end());

    // Вывод полного журнала системы
    cout << "=== ПОЛНЫЙ ЖУРНАЛ СИСТЕМЫ ===" << endl;
    for (const auto& entry : *logPtr) {
        cout << "• " << entry << endl;
    }

    // Вывод уникальных ошибок
    cout << "\n=== ОБНАРУЖЕННЫЕ ОШИБКИ ===" << endl;
    for (const auto& error : errorMessages) {
        cout << "⚠ " << error << endl;
    }

    // Дополнительная информация
    cout << "\n=== СТАТИСТИКА ===" << endl;
    cout << "Всего записей в журнале: " << logPtr->size() << endl;
    cout << "Найдено уникальных ошибок: " << errorMessages.size() << endl;

    return 0;
}