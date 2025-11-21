#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

struct Task {
    string title;
    int priority;
    string deadline;
};

// Функция для записи в output.txt
void log(const string& message) {
    ofstream output("output.txt", ios::app);
    output << message << endl;
}

// 1. Создание и заполнение файла данными
void createTasks() {
    ofstream file("tasks.txt");

    cout << "Создание задач (пустое название для выхода):" << endl;
    log("Создание задач");

    while (true) {
        Task task;

        cout << "Название: ";
        getline(cin, task.title);
        if (task.title.empty()) break;

        cout << "Приоритет: ";
        cin >> task.priority;
        cin.ignore();

        cout << "Срок (ДД.ММ.ГГГГ): ";
        getline(cin, task.deadline);

        // Записываем задачу в файл
        file << task.title << "|" << task.priority << "|" << task.deadline << endl;
        cout << "Задача добавлена!\n" << endl;

        log("Добавлена: " + task.title);
    }

    file.close();
    cout << "Задачи сохранены в файл!" << endl;
}

// 2. Поиск задачи по названию
void searchTask() {
    string name;
    cout << "Поиск задачи: ";
    getline(cin, name);

    log("Поиск: " + name);

    ifstream file("tasks.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        string title = line.substr(0, pos1);

        if (title.find(name) != string::npos) {
            size_t pos2 = line.find('|', pos1 + 1);
            string priority = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string deadline = line.substr(pos2 + 1);

            cout << "Найдено: " << title << " | Приоритет: "
                << priority << " | Срок: " << deadline << endl;
            log("Найдено: " + title);
            found = true;
        }
    }

    if (!found) {
        cout << "Не найдено!" << endl;
    }
    file.close();
}

// 2. Сортировка задач
void sortTasks() {
    cout << "Сортировка: 1-по приоритету, 2-по сроку: ";
    int choice;
    cin >> choice;
    cin.ignore();

    // Читаем задачи из файла
    ifstream file("tasks.txt");
    vector<Task> tasks;
    string line;

    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        Task task;
        task.title = line.substr(0, pos1);
        task.priority = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        task.deadline = line.substr(pos2 + 1);
        tasks.push_back(task);
    }
    file.close();

    // Сортируем
    if (choice == 1) {
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.priority < b.priority;
            });
        log("Сортировка по приоритету");
    }
    else if (choice == 2) {
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.deadline < b.deadline;
            });
        log("Сортировка по сроку");
    }

    // Записываем обратно в файл
    ofstream outFile("tasks.txt");
    for (const auto& task : tasks) {
        outFile << task.title << "|" << task.priority << "|" << task.deadline << endl;
    }
    outFile.close();

    cout << "Отсортировано!" << endl;
}

// 3. Добавление новой задачи в конец файла
void addTask() {
    Task task;

    cout << "Добавление задачи:" << endl;
    cout << "Название: ";
    getline(cin, task.title);

    cout << "Приоритет: ";
    cin >> task.priority;
    cin.ignore();

    cout << "Срок: ";
    getline(cin, task.deadline);

    // Добавляем в конец файла
    ofstream file("tasks.txt", ios::app);
    file << task.title << "|" << task.priority << "|" << task.deadline << endl;
    file.close();

    cout << "Задача добавлена!" << endl;
    log("Добавлена: " + task.title);
}

// 4. Вывод задач по приоритету
void tasksByPriority() {
    int priority;
    cout << "Максимальный приоритет: ";
    cin >> priority;
    cin.ignore();

    log("Задачи с приоритетом <= " + to_string(priority));

    ifstream file("tasks.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        string title = line.substr(0, pos1);
        int taskPriority = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        string deadline = line.substr(pos2 + 1);

        if (taskPriority <= priority) {
            cout << title << " | " << taskPriority << " | " << deadline << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Нет задач!" << endl;
    }
    file.close();
}

// 5. Главное меню
int main() {
    // Установка русской локали для корректного отображения кириллицы
    setlocale(LC_ALL, "Russian");

    // Очистка лога при запуске
    ofstream output("output.txt");
    output.close();

    while (true) {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1 - Создать задачи" << endl;
        cout << "2 - Найти задачу" << endl;
        cout << "3 - Сортировать" << endl;
        cout << "4 - Добавить задачу" << endl;
        cout << "5 - Задачи по приоритету" << endl;
        cout << "0 - Выход" << endl;
        cout << "Выбор: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: createTasks(); break;
        case 2: searchTask(); break;
        case 3: sortTasks(); break;
        case 4: addTask(); break;
        case 5: tasksByPriority(); break;
        case 0:
            cout << "Выход!" << endl;
            return 0;
        default:
            cout << "Неверный выбор!" << endl;
        }
    }
}  
