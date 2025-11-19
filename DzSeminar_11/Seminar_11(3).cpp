#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    ifstream readfile("application.log");

    // Проверка на открытие файла
    if (readfile.fail()) {
        cout << "Файл application.log не найден. Создаю новый..." << endl;

        // Создаем тестовый лог-файл
        ofstream createFile("application.log");
        if (createFile.is_open()) {
            createFile << "2024-01-01 10:00:00 INFO: Application started" << endl;
            createFile << "2024-01-01 10:00:01 DEBUG: Loading configuration" << endl;
            createFile << "2024-01-01 10:00:02 INFO: Database connection established" << endl;
            createFile << "2024-01-01 10:00:03 WARNING: High memory usage detected" << endl;
            createFile << "2024-01-01 10:00:04 ERROR: Failed to connect to external service" << endl;
            createFile << "2024-01-01 10:00:05 INFO: Retrying connection..." << endl;
            createFile << "2024-01-01 10:00:06 INFO: Connection successful" << endl;
            createFile << "2024-01-01 10:00:07 DEBUG: Processing user request" << endl;
            createFile << "2024-01-01 10:00:08 INFO: Request completed successfully" << endl;
            createFile << "2024-01-01 10:00:09 INFO: Application shutdown" << endl;
            createFile.close();
            cout << "Тестовый лог-файл создан успешно!" << endl;
        }
        else {
            cout << "Не удалось создать файл для записи." << endl;;
        }

        readfile.open("application.log");
        if (readfile.fail()) {
            cout << "Не удалось открыть созданный файл!" << endl;
        }
    }

    string str;
    int part_num = 1; // Номер текущей части
    int line_count = 0; // Счетчик строк в текущей части
    const int MAX_LINES_PER_PART = 3; // Максимальное количество строк в одной части

    ofstream current_part;
    // Открываем первую часть
    current_part.open("log_part1.txt");

    // Проверка открытия файла части
    if (current_part.fail()) {
        cout << "Ошибка создания файла части!" << endl;
        readfile.close();
    }

    cout << "Начинаю разделение файла..." << endl;

    // Обработка каждой строки исходного файла
    while (getline(readfile, str)) {
        // Записываем строку в текущую часть
        current_part << str << endl;
        line_count++;

        // Если достигли максимального количества строк в части
        if (line_count >= MAX_LINES_PER_PART) {
            cout << "Создана часть " << part_num << " (строк: " << line_count << ")" << endl;

            // Закрываем текущую часть
            current_part.close();

            // Открываем следующую часть
            part_num++;
            current_part.open("log_part" + to_string(part_num) + ".txt");

            // Проверка открытия новой части
            if (current_part.fail()) {
                cout << "Ошибка создания файла части " << part_num << "!" << endl;
                break;
            }

            // Сбрасываем счетчик строк для новой части
            line_count = 0;
        }
    }

    // Закрытие файлов
    current_part.close();
    readfile.close();

    // Если последняя часть не пустая, сообщаем о ней
    if (line_count > 0) {
        cout << "Создана часть " << part_num << " (строк: " << line_count << ")" << endl;
    }

    // Создание файла-индекса с информацией о частях
    ofstream index("index.txt");
    if (index.is_open()) {
        index << "ИНФОРМАЦИЯ О РАЗДЕЛЕННЫХ ЧАСТЯХ" << endl;
        index << "Исходный файл: application.log" << endl;
        index << "Всего частей: " << part_num << endl;
        index << "Максимальное количество строк в части: " << MAX_LINES_PER_PART << endl;
        index << "Список файлов-частей:" << endl;

        for (int i = 1; i <= part_num; i++) {
            index << i << ". log_part" << i << ".txt" << endl;
        }

        index.close();
        cout << "Файл-индекс создан: index.txt" << endl;
    }
    else {
        cout << "Ошибка создания файла-индекса!" << endl;
    }

    cout << "Разделение завершено! Создано " << part_num << " частей." << endl;

    return 0;
}